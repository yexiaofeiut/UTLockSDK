//
//  NSDate+BleDate.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/16.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (BleDate)

+ (NSString *)dateToNocstring;

+ (NSString *)getDateStrFromTimestamp:(NSString *)timestamp;

+ (NSDate *)getDateFromTimestamp:(NSString *)timestamp;
@end
