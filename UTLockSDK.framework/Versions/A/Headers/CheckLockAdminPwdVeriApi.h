//
//  CheckLockAdminPwdVeriApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/5/23.
//  Copyright © 2019 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface CheckLockAdminPwdVeriApi : APIRequest
- (id)initWithMac:(NSString *)mac code:(NSString *)code;
@end

NS_ASSUME_NONNULL_END
