//
//  BleUtils.h
//  CloudLock
//
//  Created by ace on 2018/10/22.
//  Copyright © 2018年 ut. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BleUtils : NSObject
+ (BOOL)isUTDeviceType:(NSData *)advertisementData;
+ (BOOL)isJODeviceType:(NSData *)advertisementData;
+ (int)getDeviceType:(NSData *)advertisementData;
+ (int)getDeviceIsActive:(NSData *)advertisementData;
+ (int)getJODeviceIsActive:(NSData *)advertisementData;
+ (NSString * )getHexStringMac:(NSData *)advertisementData;
+ (NSString * )getJOHexStringMac:(NSData *)advertisementData;
+ (NSData *)getProtocolData:(Byte)data withFunctionCode:(Byte)functionCode;

@end
