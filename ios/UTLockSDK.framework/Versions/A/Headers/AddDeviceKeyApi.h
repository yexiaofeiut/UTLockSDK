//
//  AddDeviceKey.h
//  CloudLock
//
//  Created by chen guichun on 2019/5/7.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"
#import "DeviceKeyModel.h"
@interface AddDeviceKeyApi : APIRequest
- (instancetype)initWithDevice:(DeviceKeyModel *)device;
@end
