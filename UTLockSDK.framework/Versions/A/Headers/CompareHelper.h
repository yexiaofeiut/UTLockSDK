//
//  CompareHelper.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/16.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CompareHelper : NSObject

+ (BOOL)isStartWith:(NSData *)source templete:(NSData *)templete;

@end
