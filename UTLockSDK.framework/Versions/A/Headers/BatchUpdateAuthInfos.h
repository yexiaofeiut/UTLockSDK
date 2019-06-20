//
//  BatchUpdateAuthInfos.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"
#import "AuthInfo.h"
@interface BatchUpdateAuthInfos : BleCmdBase

- (instancetype)init:(NSArray<AuthInfo *> *)authInfos searialNum:(int)searialNum currentSerialtotalNum:(int)currentSerialtotalNum;

@end
