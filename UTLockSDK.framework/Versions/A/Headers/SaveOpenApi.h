//
//  SaveOpenApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/5/21.
//  Copyright © 2019 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface SaveOpenApi : APIRequest
- (id)initWithMac:(NSString *)mac openVal:(int)openVal;
@end

NS_ASSUME_NONNULL_END
