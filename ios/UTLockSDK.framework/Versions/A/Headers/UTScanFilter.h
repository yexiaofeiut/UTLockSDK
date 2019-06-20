//
//  UTScanFilter.h
//  CloudLock
//
//  Created by chen guichun on 2018/11/28.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DeviceFilter.h"

@interface UTScanFilter : DeviceFilter

@property (nonatomic ,strong)NSData *mVendorId;

@property (nonatomic ,assign)int mDeviceType;

/**
 *获取广播包里的云锁数据包
 *@param scanRecord 广播数据
 *@return 云锁数据包
 **/
+ (NSData *)getCloudLockRecord:(NSData *)scanRecord;

@end
