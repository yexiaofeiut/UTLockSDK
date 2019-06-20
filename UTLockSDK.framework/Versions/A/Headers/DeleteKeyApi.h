//
//  DeleteKey.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/28.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

@interface DeleteKeyApi : APIRequest

- (instancetype)initWithMac:(long)keyId relation:(int)isRelation;

@end
