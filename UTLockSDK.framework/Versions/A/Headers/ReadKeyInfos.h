//
//  ReadKeyInfos.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "BleCmdBase.h"

@interface ReadKeyInfos : BleCmdBase
- (instancetype)init:(int)readSerialNum isAllOprate:(BOOL)isAllOprate setIdsArr:(NSArray *)idsArr;
@end
