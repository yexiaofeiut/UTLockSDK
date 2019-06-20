//
//  UpdateLockVersion.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/4/3.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface UpdateLockVersion : APIRequest
- (instancetype)init:(NSString *)mac lockVersion:(NSString *)lockVersion;
@end

NS_ASSUME_NONNULL_END
