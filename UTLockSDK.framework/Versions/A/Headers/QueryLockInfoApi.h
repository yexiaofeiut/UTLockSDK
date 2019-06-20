//
//  QueryLockInfoApi.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/25.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APIRequest.h"

@interface QueryLockInfoApi : APIRequest

@property (nonatomic, readonly , strong) NSString *deviceMac;

- (instancetype)initWithMac:(NSString *)devMac;
@end
