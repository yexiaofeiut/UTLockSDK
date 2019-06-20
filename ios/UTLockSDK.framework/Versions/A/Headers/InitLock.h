//
//  InitLock.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/16.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BleMsg.h"
#import "BleCmdBase.h"
NS_ASSUME_NONNULL_BEGIN

@interface InitLock : BleCmdBase

- (instancetype)init:(NSString *)password;

@property (nonatomic, strong) NSData *adminPassword;
@property (nonatomic, strong) NSData *openLockPassword;
@property (nonatomic, strong) NSData *secretKey;
@property (nonatomic, strong) NSData * encryptType;

//@property (nonatomic, readonly, strong) Byte *adminPswArray;
//@property (nonatomic, readonly, strong) Byte *openLockPswArray;
//@property (nonatomic, readonly, strong) Byte *secretKeyArray;
//@property (nonatomic, readonly, strong) Byte *encryptTypeArray;
@end

NS_ASSUME_NONNULL_END
