//
//  TaskParaBase.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClientHelper.h"

@class BleMsg;

typedef NS_ENUM(NSUInteger, TaskState) {
    TASKSTATE_NEW,
    TASKSTATE_PROCESSING,
    TASKSTATE_COMPLETED,
    TASKSTATE_TIMEOUT
};

typedef NS_ENUM(NSUInteger, TaskPriority) {
    PRIORITY_HIGH,
    PRIORITY_MEDIUM,
    PRIORITY_LOW,
};

@interface TaskParaBase : NSObject

@property (nonatomic ,strong)BleMsg *frame;

@property (nonatomic ,assign)int taskID;

@property (nonatomic ,strong)NSString *deviceUUID;

@property (nonatomic ,strong)NSString *name;

@property (nonatomic ,assign)BOOL isTimeOut;

@property (nonatomic ,copy)onACK onAck;

@property (nonatomic ,copy)onNAK onNak;

@property (nonatomic ,copy)onTimeout onTimeOut;

@property (nonatomic ,copy) NSArray *dataArray;

@property (nonatomic ,assign)TaskState taskState;

@property (nonatomic ,assign)TaskPriority taskPriority;

@property (nonatomic ,assign) int sendPachageIndex;

@property (nonatomic , readonly,strong) NSData *currentSendData;

@property (nonatomic ,assign) BOOL hasSendPackage;

@property (nonatomic ,assign) int sendTimes;

@property (nonatomic ,assign) int resentCount;

@property (nonatomic, assign) int currentFrameCount;

- (instancetype)init:(BleMsg *)frame withTimeout:(int)timeout;

- (void)startTimeWatch;

- (void)stopTimeWatch;

- (void)sendCount:(void(^)(BOOL isTimeout))callback;
@end
