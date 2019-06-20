//
//  GateLockNodeInfo.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "DeviceNodeInfo.h"

typedef NS_ENUM(NSUInteger, GateLockNodeType) {
     NODE_GATE_ELECT = 0,                //电量
     NODE_KEY_EVENT = 1,            //钥匙事件
     NODE_AUTH_CONTROL = 2,         //授权控制
     NODE_AUTH_KEY_EVENT = 3,       //授权钥匙事件
     NODE_AUTH_TEMP_PASSWORD = 4,   //授权临时密码
     NODE_NORMAL_OPEN_STATE = 5,    //常开状态
     NODE_DOOR_LOCK_STATE = 6,      //门锁状态
     NODE_ALARM_STATE = 7,          //报警状态
};

@interface GateLockNodeInfo : DeviceNodeInfo

@end
