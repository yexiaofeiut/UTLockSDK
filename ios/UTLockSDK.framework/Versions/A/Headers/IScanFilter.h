//
//  IScanFilter.h
//  CloudLock
//
//  Created by chen guichun on 2018/11/28.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ScannedPeripheral.h"
@protocol IScanFilter <NSObject>

/**
 *蓝牙设备过滤
 *@param device 蓝牙设备
 *@param rssi   蓝牙信号值
 *@param scanRecord  蓝牙广播数据
 **/
- (BOOL)onFilter:(ScannedPeripheral *)device rssi:(int)rssi scanRecord:(NSData *)scanRecord;

@end
