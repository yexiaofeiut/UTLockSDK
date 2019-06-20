//
//  BitConverter.h
//  UTGateway
//
//  Created by chen guichun on 2018/8/27.
//  Copyright © 2018年 chenguichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BitConverter : NSObject

+ (uint16_t)toUInt16:(NSData *)fData startIndex:(int)index;

+ (uint32_t)toUInt32:(NSData *)fData startIndex:(int)index;

+ (Byte *)intToBytes:(int)value;

+ (Byte *)shortToBytes:(short)value;

+ (unsigned long long)byteToInts:(NSData *)data;

+ (Byte *)int8ToBytes:(Byte)value;

+ (NSString *)byteToHexString:(NSData *)data ;
+ (unsigned long long)hexStringToInt:(NSString *)hexString ;
@end

@interface ByteArrayAndIndex :NSObject

- (instancetype)init:(Byte[]) byteArray;

- (instancetype)init:(Byte[]) byteArray startIndex:(int)index;

/// Method to get a UTF-8 encoded string preceded by a 1-byte length.
- (NSString *)getShortString;

/// Method to get a UTF-8 encoded string preceded by a 2-byte length.
- (NSString *)getMediunString;

- (NSString *)getLongString;

- (int)getUInt8AsInt;

- (UInt8)getUInt8;

- (int)getUInt16AsInt;

- (UInt16)getUInt16;

- (UInt32)getUInt32;
@end
