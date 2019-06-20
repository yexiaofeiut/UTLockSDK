//
//  AuthCountInfo.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AuthCountInfo : NSObject

@property (nonatomic ,assign) int authId;
@property (nonatomic ,assign) int authCount;      //授权开锁次数
@property (nonatomic ,assign) int openLockCount;  //已开锁次数

@end
