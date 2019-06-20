//
//  faultCodeListApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/3/19.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface faultCodeListApi : APIRequest
- (instancetype)initLockId:(long)lockId;
@end

NS_ASSUME_NONNULL_END
