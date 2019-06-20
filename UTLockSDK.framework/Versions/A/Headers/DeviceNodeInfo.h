//
//  DeviceNodeInfo.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/10.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeviceNodeInfo : NSObject

@property (nonatomic, assign) int devNum;
@property (nonatomic, strong) NSData *value;

- (instancetype)init:(int)devNum;

+ (int)getLength:(int)devNum;

@end
