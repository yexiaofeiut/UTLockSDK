//
//  ReadAdminPsw.h
//  UTCloudLockSDK
//
//  Created by 叶小飞 on 2019/5/20.
//  Copyright © 2019 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface ResetAdminPsw : BleCmdBase
- (instancetype)initWithPsw:(NSString *)psw;
@end

NS_ASSUME_NONNULL_END
