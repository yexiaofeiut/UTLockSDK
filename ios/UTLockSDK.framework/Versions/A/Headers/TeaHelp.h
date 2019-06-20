//
//  TeaHelp.h
//  tea
//
//  Created by 叶小飞 on 2018/11/6.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TeaHelp : NSObject
+(NSData *) tea_encrypt_fun:(UInt8* )src size:(UInt16)size_src key:(UInt8*)key;
+(UInt16) tea_decrypt_fun:(UInt8* )src size:(UInt16)size_src key:(UInt8*)key;
@end

NS_ASSUME_NONNULL_END
