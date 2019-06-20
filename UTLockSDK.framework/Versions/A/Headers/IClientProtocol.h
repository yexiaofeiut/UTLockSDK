//
//  IClientProtocol.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TaskParaBase;

@protocol IClientProtocol <NSObject>

- (void)send:(NSData *)data;

- (void)sendTask:(TaskParaBase *)task data:(NSData *)data;

- (void)recevie:(NSData *)data;

- (void)disconnect;

@end
