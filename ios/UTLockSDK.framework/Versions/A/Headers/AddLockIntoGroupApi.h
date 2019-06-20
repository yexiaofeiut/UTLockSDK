//
//  AddLockIntoGroupApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/1/9.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface AddLockIntoGroupApi : APIRequest
- (instancetype)init:(NSString *)macs groupId:(long)groupId;
@end

NS_ASSUME_NONNULL_END
