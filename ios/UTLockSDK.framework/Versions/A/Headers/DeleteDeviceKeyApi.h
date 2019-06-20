//
//  DeleteDeviceKeyApi.h
//  CloudLock
//
//  Created by chen guichun on 2019/1/23.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface DeleteDeviceKeyApi : APIRequest

- (instancetype)init:(long)lockId keysId:(NSString *)keys;

@end
