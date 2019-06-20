//
//  SendKeyApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/12/24.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface SendKeyApi : APIRequest
- (id)initWithaMobile:(NSString *)mobile mac:(NSString *)mac startTime:(NSString *)startTime endTime:(NSString *)endTime keyName:(NSString *)keyName startTimeRange:(NSString *)startTimeRange  endTimeRange:(NSString *)endTimeRange weeks:(NSString *)weeks ruleType:(int)ruleType isAdmin:(NSString *)isAdmin  totalNum:(int)totalNum;
@end

NS_ASSUME_NONNULL_END
