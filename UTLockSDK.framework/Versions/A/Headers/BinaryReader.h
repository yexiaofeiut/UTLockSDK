//
//  BinaryReader.h
//  UTGateway
//
//  Created by chen guichun on 2018/8/27.
//  Copyright © 2018年 chenguichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BinaryReader : NSObject

@property (nonatomic, assign)BOOL hasRemaining;

/*
 *字节流通过NSInputStream 来读取
 */
- (instancetype)init:(NSData *)buffer;

/*
 *读取一个uint8的数据
 */
- (uint8_t)readUInt8;

/*
 *读取一个uint16的数据
 */
- (uint16_t)readUInt16;

/*
 *读取一个uint32的数据
 */
- (uint32_t)readUInt32;

/*
 *读取一段的数据
 */
- (void)read:(Byte *)buffer index:(int)index count:(int)count;

/*
 *关闭字节流读取
 */
- (void)close;
@end
