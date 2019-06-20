//
//  AuthInfo.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AuthInfo : NSObject
@property (nonatomic, assign) int authId;  //授权编号
@property (nonatomic, assign) int keyId;   //钥匙编号
@property (nonatomic, assign) int openLockCount;  //开锁次数
@property (nonatomic, assign) Byte validWeekDay;      //控制在星期几有效
@property (nonatomic, strong) NSData* startTime;  //开始时间
@property (nonatomic, strong) NSData* endTime;    //结束时间

/**
 * 设置星期控制数组, 例如：[0, 1, 5]表示星期日、星期一、星期五为授权有效日期
 * @param validWeekDay ..
 */
- (void)setAuthDay:(NSArray *)validWeekDay;
/**
 * 返回星期控制数组，例如：[0, 1, 5]表示星期日、星期一、星期五为授权有效日期
 * @return NSArray ..
 */
- (NSArray *)getAuthDay;

/**
 * 返回授权开始时间的时间戳
 * @return ..
 */
- (long)getStartTime;

/**
 * 设置授权开始时间
 * @param starttime 时间戳
 */
- (void)setStarttime:(long) starttime;

/**
 * 返回授权结束时间的时间戳
 * @return ..
 */
- (long)getEndTime;

/**
 * 设置授权结束时间
 * @param endtime 时间戳
 */
- (void)setEndtime:(long)endtime;
@end
