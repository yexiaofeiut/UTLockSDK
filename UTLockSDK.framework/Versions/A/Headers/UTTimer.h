//
//  UTTimer.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/3.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UTTimer : NSObject
@property (copy) NSDate *fireDate;
@property (readonly) NSTimeInterval timeInterval;
@property (nonatomic, assign) BOOL isInvalidate;

- (instancetype)initWithFireDate:(NSDate *)date interval:(NSTimeInterval)ti target:(id)t selector:(SEL)s userInfo:(id)ui repeats:(BOOL)rep runloopMode:(NSRunLoopMode)mode;

+ (instancetype)timerWithTimeInterval:(NSTimeInterval)ti target:(id)aTarget selector:(SEL)aSelector userInfo:(id)userInfo repeats:(BOOL)yesOrNo runloopMode:(NSRunLoopMode)mode;
+ (instancetype)scheduledTimerWithTimeInterval:(NSTimeInterval)ti target:(id)aTarget selector:(SEL)aSelector userInfo:(id)userInfo repeats:(BOOL)yesOrNo runloopMode:(NSRunLoopMode)mode;

- (void)fire;
- (void)stop;
- (void)invalidate;
@end
