//
//  WriteProductionSerialNum.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/10.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "BleCmdBase.h"

@interface WriteProductionSerialNum : BleCmdBase

- (instancetype)init:(NSData *)serialNum;

@end
