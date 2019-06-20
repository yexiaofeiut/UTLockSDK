//
//  BleManger.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/12.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "SearchBleManager.h"
#import "DidBluetoothManager.h"
#import "ScannedPeripheral.h"
#import "BleUtils.h"
//#import "BleOperate.h"
//#import "BleCmdHandler.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import "Constants.h"
#import "IScanCallback.h"
#import "ScanCallback.h"
#import "IPeripheralProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RecevieBleDataDelegate <NSObject>

- (void)onRecevieData:(id<IScanDeviceProtocol>)bleDevice data:(NSData *)data serviceUUID:(NSString *)serviceUUID characteristicUUID:(NSString *)charactUUID;

@end

//设备状态改变的委托
typedef void (^BleUpdateStateBlock)(CBCentralManager *central);

//找到设备的委托
typedef void (^BleDiscoverPeripheralsBlock)(NSArray * scannedPeripherals);

//返回错误状态
typedef void (^BleFailtureMessBlock)(NSString*message ,BleType type);

//返回成功状态
typedef void (^BleSucessMessBlock)(NSString*message ,BleType type);

@interface BleManger : NSObject
@property (nonatomic, copy) BleUpdateStateBlock blockOnCentralManagerDidUpdateState;
@property (nonatomic, copy) BleDiscoverPeripheralsBlock bleDiscoverPeripheralsBlock;
@property (nonatomic, copy) BleFailtureMessBlock bleFailtureMessBlock;
@property (nonatomic, copy) BleSucessMessBlock bleSucessMessBlock;
@property (nonatomic, weak) id<RecevieBleDataDelegate>delegate;
@property (nonatomic, assign) BOOL isBluetoothOn;
@property (nonatomic, assign) BOOL isSearching;
@property (nonatomic, assign) BOOL isConnected;
+ (BleManger *)sharedInstance;

#pragma mark - class event
- (DidBluetoothManager *)getPeripheral;

#pragma mark - 蓝牙操作
/**
 *搜索蓝牙
 *@param scanCallback ...
 **/
- (int)scan:(ScanCallback *)scanCallback success:(onFoundDevice)device finish:(onSearchFinish)finish timeout:(onSearchTimeout)timeout;

/**
 *停止搜索蓝牙
 *
 **/
- (void)stop;

/**
 * 通过蓝牙设备连接
 *
 * @param scanPeripheral       蓝牙对象 {@link IScanCallback#onDeviceFound(BleDevice, List)}
 */
- (void)connect:(ScannedPeripheral *)scanPeripheral;

/**
 * 通过蓝牙UUID或者MAC地址直接连接
 *
 * @param deviceUUID      蓝牙UUID或者MAC地址
 */
- (void)connectByUUID:(NSString *)deviceUUID;

/**
 *断开蓝牙连接
 *
 *
 **/
- (void)disconnect;

/**
 *断开蓝牙连接
 *
 *@param deviceUUID      蓝牙UUID或者MAC地址
 **/
- (void)disconnectByUUID:(NSString *)deviceUUID;

- (void)removePeripheralDevice:(NSString *)deviceUUID;

/**
 * 是否已经连接
 *
 * @param deviceUUID 蓝牙设备UUID或者MAC地址
 * @return true 已连接
 */

/**
 * 写数据 ，需要回复
 *
 * @param deviceUUID         蓝牙设备UUID或者MAC地址
 * @param serviceUUID        服务UUID
 * @param characteristicUUID 写特征UUID
 * @param data               数据
 * @param writeCallback
 */
- (void)write:(NSString *)deviceUUID data:(NSData *)data serviceUUID:(NSString *)serviceUUID charactUUID:(NSString *)characteristicUUID success:(onWriteSuccess)success fail:(onWriteFail)fail;

- (BOOL)isConnected:(NSString *)deviceUUID;
#pragma mark - 读写命令

/**
 *主设备绑定从设备
 *
 **/
- (void)initLock;

- (void)openLock;
- (void)closeLock;
- (void)toSendAlarm;
- (void)getLockElectricityStatus;
@end

@interface PeripheralDevicePool: NSObject

- (void)addPeripheralDevice:(id<IPeripheralProtocol>)peripheralDevice;

- (void)removePeripheralDevice:(id<IPeripheralProtocol>)peripheralDevice;

- (void)removePeripheralDeviceByUUID:(NSString *)deviceUUID;

- (BOOL)contains:(NSString *)deviceUUID;

- (id<IPeripheralProtocol>)getPeripheralDevice:(NSString *)deviceUUID;

- (void)clear;
@end

NS_ASSUME_NONNULL_END
