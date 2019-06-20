//
//  TaskManager.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TaskParaBase.h"

@class UTBleLink;
@class SendTask;

@protocol TaskReadyToSendDelegate <NSObject>

- (void)taskReadyToSend:(NSString *)uuid data:(NSData *)sendData;

- (void)taskSendTimeout:(TaskParaBase *)sendtask;

@end

@interface TaskManager : NSObject

@property (nonatomic, weak) id<TaskReadyToSendDelegate> delegate;


+ (TaskManager *)sharedInstance;

/**
 *新增一个任务
 *@param task  新增的任务
 *
 **/
- (void)addTask:(TaskParaBase *)task;
/**
 *任务处理完成
 *
 **/
- (void)taskOperateComplete;
/**
 *删除一个任务
 *@param task 任务
 *
 **/
- (void)removeTask:(TaskParaBase *)task;
/**
 *删除所以任务
 *@param task 任务
 *
 **/
- (void)removeAllTask;

@end
