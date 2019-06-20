//
//  WaitHandle.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/4.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ManualResetEvent;
@interface WaitHandle : NSObject
- (instancetype)init NS_UNAVAILABLE;

+ (void)setOne;
/**
 *阻塞等待事件发生
 *@param timeout 阻塞超时时间 -1代表无限等待直到事件发生
 *@return -1 代表无限阻塞成功 0 代表等待超时时间到 1代表等待事件成功
 **/
+ (int)waitOne:(int)timeout;

+ (int)waitAny:(NSArray<ManualResetEvent *> *)waitHandles timeOut:(int)timeout;

@end


@interface ManualResetEvent : WaitHandle

- (instancetype)init:(int)value;

- (void)reset;

- (void)set;

- (void)waitOne;

@end

