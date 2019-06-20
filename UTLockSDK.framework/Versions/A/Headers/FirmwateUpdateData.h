//
//  FirmwateUpdateData.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/3/25.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleCmdBase.h"

@interface FirmwateUpdateData : BleCmdBase

- (instancetype)init:(int)cpuType frameNumber:(int)index data:(NSData *)data;

@end
