//
//  IBleClienManager.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TaskParaBase;

@protocol IBleClienManager <NSObject>

- (void)onConnect:(NSString *)uuid;

- (void)onDisconnect:(NSString *)uuid code:(int)code;

- (void)send:(NSString *)uuid data:(NSData *)data;

- (void)sendTask:(NSString *)uuid task:(TaskParaBase *)task data:(NSData *)data;

- (void)onRecevie:(NSString *)uuid data:(NSData *)data;

@end
