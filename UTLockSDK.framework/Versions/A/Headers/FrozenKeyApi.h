//
//  FrozenKeyApi.h
//  CloudLock
//
//  Created by ace chen on 2018/12/24.
//  Copyright © 2018 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface FrozenKeyApi : APIRequest
- (id)initWithKeyId:(long)keyId;
@end
