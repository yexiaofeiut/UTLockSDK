//
//  IScanCallback.h
//  CloudLock
//
//  Created by chen guichun on 2018/11/30.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScanDevice.h"

@protocol IScanCallback <NSObject>
@required
/**
 *搜索发现蓝牙设备
 *@param device 搜索到的新设备
 *
 **/
- (void)onFoundDevice:(ScanDevice *)device;
/**
 *搜索完成
 *
 *
 **/
- (void)onScanFinish;
/**
 *搜索超时
 *
 *
 **/
- (void)onScanTimeOut;

@end
