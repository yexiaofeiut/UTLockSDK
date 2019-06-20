//
//  ScanCallback.h
//  CloudLock
//
//  Created by chen guichun on 2018/11/29.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DeviceFilter.h"

typedef void(^onFoundDevice)(ScannedPeripheral *bleDevice);
typedef void(^onSearchFinish)(void);
typedef void(^onSearchTimeout)(void);

@interface ScanCallback : NSObject <IScanFilter>

@property (nonatomic, strong)NSMutableArray *scanCallbackLister;

@property (nonatomic, assign)int scanTime;

@property (readonly, assign)BOOL isScanning;

- (void)addScanFilter:(DeviceFilter *)filter;
/**
 *搜索蓝牙设备
 *
 *
 **/
- (int)scan:(onFoundDevice)foundDevice finish:(onSearchFinish)finish timeout:(onSearchTimeout)timeout;
/**
 *停止搜索蓝牙设备
 *
 *
 **/
- (void)stop;
@end
