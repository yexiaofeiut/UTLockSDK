//
//  UTWeakProxy.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/3.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UTWeakProxy : NSProxy
@property (weak, nonatomic) id target;

+ (instancetype)weakProxyWithTarget:(id)target;
- (instancetype)initWeakProxyWithTarget:(id)target;
@end
