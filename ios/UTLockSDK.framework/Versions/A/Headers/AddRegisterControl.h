//
//  AddRegisterControl.h
//  UTCloudLockSDK
//
//  Created by 叶小飞 on 2019/4/19.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"
#import "ConstParams.h"
NS_ASSUME_NONNULL_BEGIN

@interface AddRegisterControl : BleCmdBase
- (instancetype)init:(int)keyRegistType keyRegistControlInfo:(int)keyRegistControlInfo isneedPsw:(BOOL)isneedPsw;
@end

NS_ASSUME_NONNULL_END
