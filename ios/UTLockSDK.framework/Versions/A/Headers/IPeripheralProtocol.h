//
//  IPeripheralProtocol.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/11.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IScanDeviceProtocol.h"

@class ScannedPeripheral;
/**
 * 连接成功
 *
 * @param device 蓝牙对象
 */
typedef void (^BleConnectSuccess)(ScannedPeripheral *device);

/**
 * 连接断开
 *
 * @param device 蓝牙设备
 * @param isActive  是否主动断开
 */
typedef void (^BleDisconnect)(ScannedPeripheral *device, BOOL isActive);

/**
 * 正在连接
 *
 * @param device 蓝牙设备
 */
typedef void (^BleConnect)(ScannedPeripheral *device);
/**
 * 连接失败
 *
 * @param bleDevice 蓝牙设备 ，有可能为空
 * @param code ...
 * @param message ...
 */
typedef void (^BleConnectFailure)(ScannedPeripheral *bleDevice, int code, NSString *message);

/**
 * 发送数据成功
 *
 * @param serviceUUID 服务UUID
 * @param charactUUID 特征值UUID
 */
typedef void (^onWriteSuccess)(NSString *serviceUUID ,NSString *charactUUID);
/**
 * 发送数据失败
 *
 * @param bleDevice 蓝牙设备
 * @param errorCode 错误码
 * @param msg 错误信息
 */
typedef void (^onWriteFail)(ScannedPeripheral* bleDevice, int errorCode ,NSString *msg);

#pragma mark -
@protocol BluetoothManagerDelegate <NSObject>
@optional
/*!
 * A callback called when the peripheral has been successfully connected.
 */
-(void)didDeviceConnected:(NSString *)peripheralName;


-(void)didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic data:(NSData *)data error:(NSError *)error;
/*!
 * A callback called when the device got disconnected wither by user or due to a link loss.
 */
-(void)didDeviceDisconnected;
/*!
 * Method called when the device has been initialized and is ready to be used.
 */
-(void)isDeviceReady;
/*!
 * Method called when the device does not have the required service.
 */
-(void)deviceNotSupported;


-(void)logError:(NSError *)error;

@end

#pragma mark -
@protocol IPeripheralProtocol <NSObject>

@property (nonatomic, strong) id<IScanDeviceProtocol> bluetoothPeripheral;
@property (nonatomic, weak) id<BluetoothManagerDelegate> delegate;

-(void)connectDevice:(ScannedPeripheral *)scanDevice;

-(void)disconnectDevice;

-(BOOL)isConnected;

-(void)sendData:(NSString *)serviceUUID
    charactUUID:(NSString *)charactUUID
           data:(NSData *)data
successCallback:(onWriteSuccess)success
   failCallback:(onWriteFail)fail;

-(void)senddata:(NSData *)data;

@end


