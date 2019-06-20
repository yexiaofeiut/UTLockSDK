//
//  BleBaseLink.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/14.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleLinkProtocol.h"
#import "IBleClienManager.h"
#import "IScanDeviceCallback.h"
#import "IConnectCallback.h"
#import "LockStateListener.h"
#import "TaskManager.h"
#import "BleManger.h"
#import "TaskParaBase.h"

typedef NS_ENUM(int, UTDeviceType) {
    UT_UNKONW = -1,
    UT_CLOUDLOCK = 1,
    UT_HOMELOCK = 2,
    UT_GATEWAYLOCK = 3
};

@class ScanDevice;
@class BleClientManager;

@interface BleBaseLink : NSObject <BleLinkProtocol,TaskReadyToSendDelegate>
{
    TaskManager *taskManager;
    BOOL isSending;
    @public
    BleClientManager<IBleClienManager> *mConnectionManager;
    NSMutableArray *connectListerMap;
    NSMutableArray *lockStatetListerMap;
    BleManger *bleManager;
    BOOL _isConnecting;
}

/**
 *添加蓝牙搜索监听
 *@param listener 监听对象
 **/
- (void)addConnectListener:(id<IConnectCallback>)listener;
/**
 *删除蓝牙搜索监听
 *@param listener 监听对象
 **/
- (void)removeConnectListener:(id<IConnectCallback>)listener;

/**
 *添加蓝牙状态监听
 *@param listener 监听对象
 **/
- (void)addLockStateListener:(id<LockStateListener>)listener;
/**
 *删除蓝牙状态监听
 *@param listener 监听对象
 **/
- (void)removeLockStateListener:(id<LockStateListener>)listener;

- (void)handleSendEnd;

@end

@interface SendTask: NSObject

- (instancetype)init:(NSString *)uuid data:(NSData *)data;
@property (nonatomic, assign)TaskState taskState;
@property (nonatomic, assign)TaskPriority taskPriority;
@property (nonatomic, assign)int requestID;
@property (nonatomic, assign)int sendTimes;
@property (nonatomic, assign)BOOL isTimeOut;
@property (nonatomic, weak) id<TaskReadyToSendDelegate>bleTaskLink;

- (NSString *)getDeviceUUID;
- (NSData *)getSendData;
- (void)start;
@end
