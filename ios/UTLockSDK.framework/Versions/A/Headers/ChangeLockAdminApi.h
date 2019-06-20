//
//  ChangeLockAdminApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/12/19.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface ChangeLockAdminApi : APIRequest
- (id)initWithMobile:(NSString *)mobile  macs:(NSString *)macs veriCode:(NSString *)veriCode;
@end

NS_ASSUME_NONNULL_END
