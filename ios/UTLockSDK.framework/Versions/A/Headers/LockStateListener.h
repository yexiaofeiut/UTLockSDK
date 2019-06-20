//
//  LockStateListener.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/7.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LockState.h"
#import "AddRegisterStatus.h"
@protocol LockStateListener <NSObject>
/**
 * 收到云锁设备的状态信息
 * @param state 云锁设备上传的状态信息，调用{@link LockState#getElect()}可以获取电量
 */
- (void)onRecevieState:(NSString *)deviceUUID state:(LockState *) state;

/**
 门锁从设备上传注册流程状态

 @param addRegisterStatus 智能门锁在启动注册流程之后，处在注册流程中时需要上报注册过程中的状态或者操作异常
 */
- (void)onRecevieAddRegisterStatus:(NSString *)deviceUUID addRegisterStatus:(AddRegisterStatus *) addRegisterStatus;
@end
