//
//  GetMessageDetailApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/12/25.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface GetMessageDetailApi : APIRequest
- (id)initWithLockMac:(NSString *)lockMac;
@end

NS_ASSUME_NONNULL_END
