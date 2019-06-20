//
//  FirmwareUpdateInfo.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/3/25.
//  Copyright © 2019年 chen guichun. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "BleCmdBase.h"

@interface FirmwareUpdateInfo : BleCmdBase

- (instancetype)init:(int)cpuType frameCount:(int)count checkSum:(int)checksum;

@end
