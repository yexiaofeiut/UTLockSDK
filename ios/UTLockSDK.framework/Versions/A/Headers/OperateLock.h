//
//  OperateLock.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/16.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"

static int SINGLE_CONTROL = 0; //单独控制
static int DELAY_CONTROL = 1; //延时控制

static int OPERATE_OPEN_LOCK = 1; //开锁
static int OPERATE_CLOSE_LOCK = 0; //关锁

@interface OperateLock : BleCmdBase
- (instancetype)init:(NSData *)openLockPassword operateType:(int)operateType controlType:(int)controlType gapTime:(int)gapTime deviceNode:(int)deviceNode value:(int)value;
@end
