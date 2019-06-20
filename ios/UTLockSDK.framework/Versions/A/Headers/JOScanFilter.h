//
//  JOScanFilter.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/10.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "IScanFilter.h"
#import "DeviceFilter.h"
@interface JOScanFilter : DeviceFilter

/**
 *获取广播包里的金瓯数据包
 *@param scanRecord 广播数据
 *@return 云锁数据包
 **/
+ (NSData *)getCloudLockRecord:(NSData *)scanRecord;

@end
