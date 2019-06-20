//
//  BleDeviceOperateCallback.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/14.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CloudLock.h"

/**
 *操作成功回调
 *@param data 云锁设备信息
 **/
typedef void(^onOperateSuccess)(CloudLock *data);

/**
 *操作成功回调
 *@param data 云锁设备信息  如果data = 0xFFFF表示锁跳转boot重连成功
 **/
typedef void(^onOperateLockSuccess)(id data);

/**
 *操作失败回调
 *@param errorCode 错误码
 *@param msg       错误码信息
 **/
typedef void(^onOperateFail)(int errorCode ,NSString *msg);
/**
 *操作超时回调
 **/
typedef void(^onOperateTimeout)(void);

@protocol BleDeviceOperateCallback <NSObject>

@end
