//
//  UpdateLockProcess.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/3/26.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IConnectCallback.h"
#import "BleDeviceOperateCallback.h"

@class BleBaseLink;

extern BOOL isOperateJump;

@interface UpdateLockProcess : NSObject <IConnectCallback>

@property (nonatomic, strong) NSString *uuid;

- (instancetype)init:(NSString *)filePath link:(BleBaseLink* )bleLink;

/**
 *获取锁的版本信息,如果CPU0处于App 获取成功返回ProductInfo；
 *如果CPU0处于Boot 获取失败 返回nil，此时直接从云端拿最新固件升级
 *@param success  成功回调
 *@param fail     失败回调
 *@param timeout  超时回调
 **/
//- (void)jumpToBoot:(int)cpuType
//           success:(onOperateLockSuccess)success
//              fail:(onOperateFail)fail
//           timeOut:(onOperateTimeout)timeout;

/**
 *开始升级固件，先跳转到boot ，再发信息帧，再发数据帧；
 *@param cpuType  cpu类型 0升级主CPU 1 升级次CPU
 *@param success  成功回调
 *@param fail     失败回调
 *@param timeout  超时回调
 **/
- (void)startUpdate:(int)cpuType
            success:(onOperateLockSuccess)success
               fail:(onOperateFail)fail
            timeOut:(onOperateTimeout)timeout;
@end
