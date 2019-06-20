//
//  BleLinkProtocol.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/14.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TaskParaBase;

@protocol BleLinkProtocol <NSObject>

@property (nonatomic, assign)int deviceId;

- (void)connect:(NSString *)uuid;

- (void)disconnect:(NSString *)deviceUUID;

- (void)send:(NSString *)deviceUUID data:(NSData *)data requestID:(int)requestID;

- (void)sendTask:(NSString *)deviceUUID data:(TaskParaBase *)task;

- (BOOL)write:(NSString *)deviceUUID data:(NSData *)data;

@end
