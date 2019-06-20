//
//  BufferHelper.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/21.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BufferHelper : NSObject

@property (nonatomic, assign) int currentLength;

- (instancetype)init:(int)size;

- (Byte *)getAllBytes;

- (void)add:(NSData *)data;

- (Byte)get;

- (void)reset;

@end
