//
//  VeriUserPwdApi.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/29.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface VeriUserPwdApi : APIRequest

- (instancetype)init:(NSString *)pwdStr;

@end
