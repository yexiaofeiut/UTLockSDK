//
//  AddAdminLockApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/12/17.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface AddAdminLockApi : APIRequest
- (id)initWithMac:(NSString *)mac;
@end

NS_ASSUME_NONNULL_END
