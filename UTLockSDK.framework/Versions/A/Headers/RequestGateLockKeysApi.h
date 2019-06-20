//
//  RequestGateLockKeysApi.h
//  CloudLock
//
//  Created by chen guichun on 2019/1/19.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface RequestGateLockKeysApi : APIRequest
/**
 *获取家居锁钥匙信息
 *@param keyType 0获取所有钥匙信息 1，2，3获取对应的钥匙信息
 **/
- (instancetype)init:(int)keyType lockID:(long)lockId;

@end
