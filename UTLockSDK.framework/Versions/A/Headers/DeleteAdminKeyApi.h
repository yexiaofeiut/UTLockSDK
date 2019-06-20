//
//  DeleteAdminKeyApi.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/26.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface DeleteAdminKeyApi : APIRequest
- (instancetype)initWithMac:(NSString *)devMac;
@end
