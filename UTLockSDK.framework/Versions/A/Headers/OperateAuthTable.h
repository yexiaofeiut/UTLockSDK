//
//  OperateAuthTable.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"

typedef NS_ENUM(NSUInteger, OperateAuthType) {
    ADD = 1,
    UPDATE = 2,
    DELETE = 3,
    QUERY = 4
};

@class AuthInfo;

@interface OperateAuthTable : BleCmdBase

- (instancetype)init:(int)operateType;

- (void)setAuthInfoArray:(NSArray<AuthInfo *> *)authInfoArr;

- (void)setAuthIdArr:(NSArray *)authIdArr isAllOprate:(BOOL)isAllOprate searialNum:(int)searialNum ;
@end
