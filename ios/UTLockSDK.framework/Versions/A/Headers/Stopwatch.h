//
//  Stopwatch.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/3.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Stopwatch : NSObject

@property (nonatomic, assign)int elapsedMilliseconds;

- (void)start;

- (void)stop;

- (void)restart;

@end
