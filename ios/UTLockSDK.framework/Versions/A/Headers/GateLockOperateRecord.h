//
//  GateLockOperateRecord.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GateLockOperateRecord : NSObject

@property (nonatomic ,assign) int keyId;

@property (nonatomic, assign) int keyType;

@property (nonatomic ,strong) NSString *operateTime;

@end
