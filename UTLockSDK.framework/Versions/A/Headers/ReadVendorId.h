//
//  ReadVendorId.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/16.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleMsg.h"
#import "BleCmdBase.h"
NS_ASSUME_NONNULL_BEGIN

@interface ReadVendorId : BleCmdBase

@end

@interface ReadVendorResultData: NSObject

@property (nonatomic, assign) int vendorId;
@property (nonatomic, assign) short deviceType;

@end

NS_ASSUME_NONNULL_END
