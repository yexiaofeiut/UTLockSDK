//
//  AuthOpenLockApi.h
//  CloudLock
//
//  Created by chen guichun on 2019/1/9.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface AuthOpenLockApi : APIRequest

- (instancetype)init:(NSString *)mac;

@end
