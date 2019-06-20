//
//  WriteVendorId.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/10.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import "BleCmdBase.h"

@interface WriteVendorId : BleCmdBase

- (instancetype)init:(int)vendorId deviceType:(int)devType;

@end
