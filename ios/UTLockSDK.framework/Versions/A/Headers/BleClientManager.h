//
//  BleClientManager.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBleClienManager.h"
#import "FrameHandler.h"
#import "BleLinkProtocol.h"
#import "AddRegisterStatus.h"
@class ClientHelper;
@class LockState;

@protocol RecevieNotifiDelegate <NSObject>
- (void)onRecevieNotifyData:(NSString *)deviceUUID data:(LockState *)lockState;
- (void)onRecevieNotifyAddRegisterStatus:(NSString *)deviceUUID addRegisterStatus:(AddRegisterStatus *)addRegisterStatus;
@end
@interface BleClientManager : NSObject<IBleClienManager>

@property (nonatomic, strong)FrameHandler *frameHandle;
@property (nonatomic, weak) id<RecevieNotifiDelegate>delegate;
@property (nonatomic, weak) id<BleLinkProtocol>bluetoothLink;
@property (nonatomic ,assign) BOOL isBackgroudModel;
- (instancetype)init:(id<BleLinkProtocol>)bleLink;

- (ClientHelper *)getClientHepler:(NSString *)uuid;

- (void)onConnect:(NSString *)uuid;

- (void)disConnect:(NSString *)uuid;
@end
