//
//  CloudLockNodeInfo.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "DeviceNodeInfo.h"

typedef NS_ENUM(NSUInteger, CloudLockNodeType) {
    NODE_CLOUD_ELECT,
    NODE_LOCK_CONTROL,
    NODE_LOCK_STATE,
};

@interface CloudLockNodeInfo : DeviceNodeInfo

@end
