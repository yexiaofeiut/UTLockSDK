//
//  JOBluetoothDataPacket.h

//  Created by wbh on 12-4-18.
//  Copyright (c) 2012年 重庆金瓯科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#define MULTI_PACKET_ONE_RESPONSE   0           //是否启用多个数据包一次应答机制
#define DISCONNECT_WHEN_MULTI_PACKET_TIMEOUT    //当同一个序号的数据包连续多次出现超时时，我们断开连接

@class JOBluetoothDataPacket;

@protocol JOBluetoothDataPacketDelegate
@optional
@required
-(Boolean) bluetoothDataPacket:(JOBluetoothDataPacket *)dataPacketHandler writeData:(NSData *)data;
-(Boolean) bluetoothDataPacket:(JOBluetoothDataPacket *)dataPacketHandler writeResponsePacket:(NSData *)data error:(Boolean)error;
-(Boolean) bluetoothDataPacket:(JOBluetoothDataPacket *)dataPacketHandler writeHostCanReceivePacket:(NSData *)data;
-(Boolean) bluetoothDataPacket:(JOBluetoothDataPacket *)dataPacketHandler writeResetSequence:(NSData *)data;
-(void) bluetoothDataPacket:(JOBluetoothDataPacket *)dataPacketHandler characteristic:(CBCharacteristic *)characteristic didDataReceived:(const void *)buffer length:(NSUInteger)length;
-(void) disconnect;
@end

@interface JOBluetoothDataPacket : NSObject
{
    NSMutableArray * arrayWaitSendData;         //等待发送的数据包
    NSMutableArray * arrayWaitResponseData;     //未接收到应答的数据包
    int nNextSendDataIndex;                     //下一次发送数据的位置
    NSTimer * dataTimer;
    id <JOBluetoothDataPacketDelegate> delegate;
    Byte nNextSendPacketSequence;               //下一次发送的数据包的序号
    Byte nNextWantRecvPacketSequence;           //下一次希望接收的数据包的序号
    NSDate * lastSendDate;                      //最后一次发送数据的时间，用于数据包超时控制
    NSDate * lastRecvResetSequenceDate;         //最后一次接收复位序号消息的时间，用于控制连续收到多个复位序号消息时，我们只处理一个
    int nNoResponseCurrAllowMaxPacketCount;     //最大允许无应答时发送的包数量，有时我们需要零时调整，此变量记录当前值
#if MULTI_PACKET_ONE_RESPONSE
    int nCurrNotResponsePacketCount;            //启用多个数据包一次应答机制时，记录当前还没有应答的数据包个数
    NSTimer * multiPacketResponseTimeoutTimer;  //启用多个数据包一次应答机制时的超时定时器
#endif
    //int nFirstWaitResendSequence;                //此变量与下面的变量一起，用于记录要求进行重发的数据包序号，由于要求重发的数据包序号是连续的，所以我们使用开始序号及长度就可以了。 此变量记录最后一个要求重发的第一个数据包序号
    //由于 nFirstWaitResendSequence 与 nNextSendPacketSequence 相同，我们直接使用就可以了
    int nWaitResendPacketCount;                 //要求重发的数据包个数
#ifdef DISCONNECT_WHEN_MULTI_PACKET_TIMEOUT
    int nContinuePacketTimeoutCount;            //连续包超时次数
    Byte nLastPacketTimeoutSeq;                 //上一次出现超时的数据包序号
#endif

}

@property (nonatomic) int nMaxPacketSize;                       //最大数据包字节个数
@property (nonatomic) int nPacketTimeout;                       //数据包应答超时
@property (nonatomic) int nNoResponseAllowMaxPacketCount;       //没有应答时，最大可以发送的数据包数量
@property (nonatomic) Boolean bPeerCanReceive;                  //是否对方设备还可以继续接收数据
/*!
 *  @method nWaitSendDataCount:
 *
 *  @discussion 还没有成功发送的字节个数
 */
@property(readonly, getter = getNWaitSendDataCount) NSUInteger nWaitSendDataCount;

/*!
 *  @method initWithDelegate:
 *
 *  @param delegate	The delegate to receive the events
 *  @discussion The initialization call.
 *
 */
-(id) initWithDelegate:(id<JOBluetoothDataPacketDelegate>)delegate;

/*!
 *  @method reset
 *
 *
 *  @discussion  复位数据包处理程序
 */
-(void) reset;

/*!
    将需要发送的数据加入到发送队列
 */
-(Boolean) sendDataToPeer:(NSData *)data;
-(Boolean) recvDataFromPeer:(NSData *)data characteristic:(CBCharacteristic *)characteristic;

/*!
 *  @method recvDataPackeSequence
 *
 *  @param  nSeq 数据包序号
 *          error   错误序号还是正确序号
 *  @return none
 *
 *  @discussion  接收到对方发送过来的数据包序号消息，也就是对方成功接收到某个序号的数据包，或者某个数据包接收错误
 */
-(void) recvDataPackeSequence:(Byte) nSeq error:(Boolean)error;

/*!
 *  @method recvResetSequence:
 *
 *  @discussion 当传输出现严重错误时，模块用来通知主机复位数据包的序号
 */
-(void) recvResetSequence;

@end
