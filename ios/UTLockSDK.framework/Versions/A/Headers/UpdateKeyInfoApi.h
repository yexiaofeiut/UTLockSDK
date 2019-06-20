//
//  UpdateKeyInfoApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/1/17.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface UpdateKeyInfoApi : APIRequest
- (instancetype)initWithVolist:(NSString *)volist;
@end

NS_ASSUME_NONNULL_END
