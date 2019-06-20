//
//  BinaryInput.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/7.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BinaryInput : NSObject

@property (nonatomic, readonly, strong)NSData *inputData;

@property (nonatomic, readonly)Byte *inputBytes;

@property (nonatomic, assign) int currentPosition;
/*
 *字节流通过NSOutStream 来读取
 */
- (instancetype)init:(NSData *)buffer;

- (instancetype)initSize:(int)length;

- (void)putData:(NSData *)data;

- (void)putUInt8:(uint8_t)data;

- (void)putUInt16:(uint16_t)data;

- (void)putUInt32:(uint32_t)data;

- (void)putData:(Byte *)data startIndex:(int)index len:(int)length;

- (NSData *)getInputBytes:(int)startIndex len:(int)length;

- (void)close;

@end
