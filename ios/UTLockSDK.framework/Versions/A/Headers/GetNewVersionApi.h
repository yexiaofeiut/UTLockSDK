//
//  GetNewVersionApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/12/29.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface GetNewVersionApi : APIRequest
- (id)initWithtypeId:(int)typeId;
@end

NS_ASSUME_NONNULL_END
