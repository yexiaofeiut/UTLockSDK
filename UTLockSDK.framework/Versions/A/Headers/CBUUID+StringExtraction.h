//
//  CBUUID+StringExtraction.h
//  B100
//
//  Created by ut on 15/8/19.
//  Copyright (c) 2015年 ut. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>

@interface CBUUID (StringExtraction)

/**
 *  蓝牙UUID to String
 *
 *  @return UUIDString
 */
- (NSString *)representativeString;

@end
