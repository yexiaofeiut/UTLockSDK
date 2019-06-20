//
//  AddLogApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/12/29.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface AddLogApi : APIRequest
- (instancetype)initLockId:(long)lockId keyId:(long)keyId type:(int)type openLockType:(int)openLockType elect:(int)elect ruleType:(int)ruleType;
@end

NS_ASSUME_NONNULL_END
