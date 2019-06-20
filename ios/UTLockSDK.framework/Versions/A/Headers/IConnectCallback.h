//
//  IConnectCallback.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/4.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScannedPeripheral.h"

@protocol IConnectCallback <NSObject>
/**
 * 连接成功
 *
 * @param device 蓝牙对象
 */
- (void)onConnectSuccess:(ScannedPeripheral *)device;

/**
 * 连接断开
 *
 * @param device 蓝牙设备
 * @param isActive  是否主动断开
 */
- (void)onDisConnect:(ScannedPeripheral *)device isActive:(BOOL)isActive;
/**
 * 正在连接
 *
 * @param device 蓝牙设备
 */
- (void)onConnects:(ScannedPeripheral *)device;
/**
 * 连接失败
 *
 * @param device 蓝牙设备 ，有可能为空
 * @param code ...
 * @param msg ...
 */
- (void)onConnectFailure:(ScannedPeripheral *)device code:(int)code message:(NSString *)msg;
@end
