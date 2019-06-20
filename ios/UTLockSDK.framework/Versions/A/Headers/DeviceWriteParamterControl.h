//
//  DeviceWriteParamterControl.h
//  UTCloudLockSDK
//
//  Created by 叶小飞 on 2019/5/20.
//  Copyright © 2019 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"
#import "ControllerParaInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface DeviceWriteParamterControl : BleCmdBase
- (instancetype)initData:(NSArray<ControllerParaInfo *>*)contolArr;
@end

NS_ASSUME_NONNULL_END
