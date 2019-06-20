//
//  UpdateLockNameApi.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/27.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface UpdateLockNameApi : APIRequest

- (instancetype)init:(NSString *)mac name:(NSString *)name;

@end
