//
//  BleCmdBase.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/6.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ClientHelper;
@class BleMsg;

typedef void(^onBleSuccess)(id result);
typedef void(^onBleFial)(int errorcode, NSString *msg);
typedef void(^onBleTimeout)(void);

@interface BleCmdBase : NSObject

@property (nonatomic, assign)int autoIncreaseNum;

@property (nonatomic, strong)ClientHelper *clientHepler;

@property (nonatomic, copy)onBleSuccess onSuccess;
@property (nonatomic, copy)onBleFial onFail;
@property (nonatomic, copy)onBleTimeout onTimeOut;

+ (void)setInscreaseNum:(int)num;

- (instancetype)init:(ClientHelper *)clientHelper;

- (void)sendMsg:(onBleSuccess)successCallbck fail:(onBleFial)failCallback timeout:(onBleTimeout)timeoutCallback;

- (BleMsg *)build;

- (id)parse:(BleMsg *)msg;
@end
