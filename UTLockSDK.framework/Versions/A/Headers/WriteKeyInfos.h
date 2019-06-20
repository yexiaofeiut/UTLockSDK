//
//  WriteKeyInfos.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"
#import "GateLockKey.h"

@interface WriteKeyInfos : BleCmdBase

- (instancetype)init:(NSArray<GateLockKey *> *)keys searialNum:(int)searialNum currentSerialtotalNum:(int)currentSerialtotalNum  ;

@end
