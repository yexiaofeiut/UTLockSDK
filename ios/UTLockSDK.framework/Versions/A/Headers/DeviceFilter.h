//
//  DeviceFilter.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/14.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IScanFilter.h"

@interface DeviceFilter : NSObject <IScanFilter>

@property (nonatomic, assign) int deviceId;

@end
