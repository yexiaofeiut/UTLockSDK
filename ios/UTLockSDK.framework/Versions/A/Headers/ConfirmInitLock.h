//
//  ConfirmInitLock.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/7.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleCmdBase.h"

@interface ConfirmInitLock : BleCmdBase

- (instancetype)init:(NSData *)adminPsw;

@property (nonatomic, strong)NSData *adminPsw;

@end
