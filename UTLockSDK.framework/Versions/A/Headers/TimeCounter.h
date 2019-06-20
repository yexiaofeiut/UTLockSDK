//
//  TimeCounter.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/3.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Stopwatch.h"
@interface TimeCounter : Stopwatch

@property (nonatomic, assign)int timeout;

- (instancetype)init:(int)timeOut;

- (BOOL)over;
@end
