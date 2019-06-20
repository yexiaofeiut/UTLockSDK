//
//  JOBlePerioheralManager.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/11.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "IPeripheralProtocol.h"
#import "JOBluetoothDevice.h"

@interface JOBlePerioheralManager : NSObject<IPeripheralProtocol>

//@property (nonatomic, strong) ScannedPeripheral *bluetoothPeripheral;

@property (nonatomic, copy) BleConnect onConnect;
@property (nonatomic, copy) BleConnectSuccess onConnectSuccess;
@property (nonatomic, copy) BleDisconnect onDisconnect;
@property (nonatomic, copy) BleConnectFailure onConnectFailure;

- (instancetype)initWithManager:(CBCentralManager *)centralManager scanPeripheral:(ScannedPeripheral *)scanDevice;

//- (void)addScanJODevice:(ScannedPeripheral *)scanDevice;
@end
