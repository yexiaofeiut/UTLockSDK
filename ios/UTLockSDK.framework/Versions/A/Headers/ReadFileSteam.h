//
//  ReadFileSteam.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/3/26.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^ReadFileCallback)(NSArray *dataArray);

@interface ReadFileSteam : NSObject

- (instancetype)init:(NSString *)filePath readSize:(int)size;

@property (nonatomic, readonly, strong) NSArray *dataArray;

- (void)readDataFramPath:(ReadFileCallback)callback;

@end
