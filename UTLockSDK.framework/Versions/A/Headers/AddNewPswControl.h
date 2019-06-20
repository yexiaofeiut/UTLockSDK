//
//  AddNewPswControl.h
//  UTCloudLockSDK
//
//  Created by 叶小飞 on 2019/4/19.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface AddNewPswControl : BleCmdBase
- (instancetype)initWithPsw:(NSString *)psw;
@end

NS_ASSUME_NONNULL_END
