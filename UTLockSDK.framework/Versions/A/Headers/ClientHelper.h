//
//  ClientHelper.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IClientProtocol.h"
#import "BleMsg.h"

@class BleClient;
@class TaskParaBase;

/**
 *锁状态上报 delelgate
 *lockState 锁状态信息
 **/
@protocol LockStateDelegate <NSObject>

- (void)onRecevieNotifiData:(NSString *)deviceUUID state:(BleMsg *)msg;

/**
 从设备上传注册流程状态
 */
- (void)onRecevieNotifiData:(NSString *)deviceUUID onregisterState:(BleMsg *)msg;
@end

typedef void(^onACK)(BleMsg * msg);
typedef void(^onNAK)(int errorcode);
typedef void(^onTimeout)(void);

@interface ClientHelper : NSObject

@property (nonatomic,readonly,weak)id<IClientProtocol> bleClient;

@property (nonatomic,weak)id<LockStateDelegate> locksteDelegate;

@property (nonatomic,strong)id<IEncrypt> mEncrypt;

@property (nonatomic, strong) NSMutableDictionary<NSString * , TaskParaBase *> *sendTaskDic;

@property (nonatomic, assign)BOOL isBackgroudModel;

- (instancetype)init:(BleClient *)client;

- (void)asyncSend:(BleMsg *)frame
      ACKCallback:(onACK)ackCallback
      NAKCallback:(onNAK)nakCallback
          timeout:(onTimeout)timeoutCallback;

- (void)asyncSend:(BleMsg *)frame;

- (void)syncSend:(BleMsg *)frame
      ACKCallback:(onACK)ackCallback
      NAKCallback:(onNAK)nakCallback
          timeout:(onTimeout)timeoutCallback;

- (void)syncSend:(BleMsg *)frame;

- (void)disconnect;

- (TaskParaBase *)getSendedTask:(int)requestID;

- (void)deleteSendedTask:(int)requestID;
@end
