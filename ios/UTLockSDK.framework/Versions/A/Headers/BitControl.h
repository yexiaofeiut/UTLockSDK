//
//  BitControl.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/16.
//  Copyright © 2019年 chen guichun. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface BitControl : NSObject

/**
 * 获取指定位，
 * @param data ..
 * @param pos ..
 * @return 0或1
 */
+ (int)bit:(int)data pos:(int)pos;

/**
 * 对指定位进行置一操作
 * @param data ..
 * @param pos ..
 * @return int ..
 */
+ (int)set1:(int)data pos:(int)pos;
/**
 * 对指定位进行清零操作
 * @param data ..
 * @param pos ..
 * @return int ..
 */
+ (int)set0:(int)data pos:(int)pos;

/**
 * 对指定位设置值
 * @param data ..
 * @param pos ..
 * @param value 0或1
 * @return
 */
+ (int)set:(int)data pos:(int)pos value:(int) value;

@end
