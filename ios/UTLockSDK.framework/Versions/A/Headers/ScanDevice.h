//
//  ScanDevice.h
//  CloudLock
//
//  Created by chen guichun on 2018/11/26.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ScannedPeripheral;

@interface ScanDevice : NSObject<NSCoding>

/**
 *获取设备UUID地址
 *@return string UUID地址
 **/
@property (nonatomic, strong)NSString *address;

/**
 *获取设备mac地址
 *@return string mac地址
 **/
@property (nonatomic, strong)NSString *mac;

/**
 *获取设备名称
 *@return string mac地址
 **/
@property (nonatomic, strong)NSString *name;

/**
 *蓝牙设备的信号强度
 **/
@property (nonatomic, assign)int rssi;

/**
 *获取厂商标识
 *@return byte[] 4字节数组
 **/
@property (nonatomic, strong)NSData *vendorId;

/**
 *设备是否激活
 *@return BOOL
 **/
@property (nonatomic, assign)BOOL isActive;

/**
 *获取设备类型
 *@return NSData 2字节数组
 **/
@property (nonatomic, strong)NSData *deviceType;

/**
 *设备类型id 1 是云锁 2时门锁
 **/
@property (nonatomic, assign)int deviceId;


/**
 *获取蓝牙设备
 *@return NSData 2字节数组
 **/
@property (nonatomic, strong)ScannedPeripheral *bleDevice;

@end
