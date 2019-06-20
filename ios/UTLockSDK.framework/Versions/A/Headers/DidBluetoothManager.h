
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "Logger.h"
#import "ScannedPeripheral.h"
#import "IPeripheralProtocol.h"
#import "IPeripheralProtocol.h"


typedef NS_ENUM(int, ConnectState) {
    CONNECT_INIT = -1,           //连接初始化
    CONNECT_PROCESS = 0x00,      //连接中
    CONNECT_SUCCESS = 0x01,      //连接成功
    CONNECT_FAILURE = 0x02,      //连接失败
    CONNECT_TIMEOUT = 0x03,      //连接超时
    CONNECT_DISCONNECT = 0x04   //连接断开
};



@interface DidBluetoothManager : NSObject <IPeripheralProtocol,CBCentralManagerDelegate, CBPeripheralDelegate>

-(instancetype)initWithManager:(CBCentralManager*)manager;

// Delegate properties
@property (nonatomic, strong) ScannedPeripheral *bluetoothPeripheral;
//@property (nonatomic, weak) id<BluetoothManagerDelegate> delegate;
@property (nonatomic, weak) id<Logger> logger;

@property (nonatomic, copy) BleConnect onConnect;
@property (nonatomic, copy) BleConnectSuccess onConnectSuccess;
@property (nonatomic, copy) BleDisconnect onDisconnect;
@property (nonatomic, copy) BleConnectFailure onConnectFailure;

//-(void)connectDevice:(ScannedPeripheral *)scanDevice;
//-(void)disconnectDevice;
////-(void)send:(NSString *)text;
//-(BOOL)isConnected;
//-(void)sendData:(NSString *)serviceUUID
//    charactUUID:(NSString *)charactUUID
//           data:(NSData *)data
//successCallback:(onWriteSuccess)success
//   failCallback:(onWriteFail)fail;
//-(void)senddata:(NSData *)data;
@end
