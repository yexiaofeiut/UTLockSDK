//
//  ApplyKeyApi.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/28.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface ApplyKeyApi : APIRequest
- (instancetype)initMac:(NSString *)mac reason:(NSString *)reason ruleType:(NSNumber *)ruleType;
@end
