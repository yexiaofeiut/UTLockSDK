//
//  UTBleManager.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/8.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ScannedPeripheral.h"
@protocol ScannerDelegate <NSObject>
- (void) centralManager:(CBCentralManager*) manager didPeripheralSelected:(ScannedPeripheral*) peripheral;
- (void)onDiscovered:(NSMutableArray*)peripherals;
@end

typedef void (^onFoudDeviceBlock)(ScannedPeripheral *peripheral, int rssi, NSData *scanRecord);

typedef void (^onSearchCompleteBlock)(void);

typedef void (^onSearchTimeOut)(void);

NS_ASSUME_NONNULL_BEGIN

typedef CBManagerState (^ReturnBlueToothStateBlock)(void);
@interface SearchBleManager : NSObject
{
    @public
    BOOL isSearching;
}
@property (strong, nonatomic) CBCentralManager *bluetoothManager;
@property (strong, nonatomic) NSMutableDictionary<NSString *, ScannedPeripheral *> *peripherals;
@property (strong, nonatomic) CBUUID *filterUUID;
@property (strong, nonatomic) NSArray<CBUUID *>* filterUUIDArr;
@property (strong, nonatomic) id <ScannerDelegate> delegate;

@property (nonatomic, copy) ReturnBlueToothStateBlock returnState;

@property (nonatomic, copy) onFoudDeviceBlock foundDevice;
@property (nonatomic, copy) onSearchCompleteBlock searchComplete;
@property (nonatomic, copy) onSearchTimeOut searchTimeout;

+ (SearchBleManager *)sharedInstance;

- (int)startScan:(int)timeOut;

- (void)stopScan;

- (void)disConnectSuccess;

- (void)didPeripheralSelected:(ScannedPeripheral*) sensor;

- (ScannedPeripheral *)getScannedPeripheral:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
