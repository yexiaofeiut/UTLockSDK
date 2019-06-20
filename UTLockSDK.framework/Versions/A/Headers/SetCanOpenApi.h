//
//  SetCanOpenApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/1/17.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface SetCanOpenApi : APIRequest
- (id)initWithKeyId:(long)keyId canOpen:(int)canOpen;
@end

NS_ASSUME_NONNULL_END
