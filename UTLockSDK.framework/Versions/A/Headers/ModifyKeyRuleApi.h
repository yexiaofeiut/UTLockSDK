//
//  ModifyKeyRuleApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/12/26.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface ModifyKeyRuleApi : APIRequest

- (id)initWithamac:(NSString *)mac  startTime:(NSString *)startTime endTime:(NSString *)endTime startTimeRange:(NSString *)startTimeRange  endTimeRange:(NSString *)endTimeRange weeks:(NSString *)weeks keyId:(long)keyId availNum:(int)availNum ;
@end

NS_ASSUME_NONNULL_END
