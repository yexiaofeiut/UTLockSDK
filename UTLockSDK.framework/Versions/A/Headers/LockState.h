//
//  LockState.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/7.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LockState : NSObject
/**
 *门锁状态
 *0 门锁关闭
 *1 门锁打开
 **/
@property (nonatomic, assign) int status;
/**
 *门锁电量
 *
 **/
@property (nonatomic, assign) int elect;

+ (LockState *)parseLockState:(NSData *)data;
@end
