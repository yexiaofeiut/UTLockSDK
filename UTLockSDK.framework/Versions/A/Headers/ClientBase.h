//
//  ClientBase.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IClientProtocol.h"
@class BleClientManager;
@protocol ClientRecevieProtocol <NSObject>

- (void)onRecevie:(NSData *)data;

@end

@interface ClientBase : NSObject <IClientProtocol>

@property (nonatomic, weak)id<ClientRecevieProtocol> delegate;
@property (nonatomic, readonly, strong)NSString *deviceUUID;
@property (nonatomic, readonly, strong)BleClientManager *clientManager;
- (instancetype)init:(NSString *)deviceUUID manager:(BleClientManager *)manager;


@end
