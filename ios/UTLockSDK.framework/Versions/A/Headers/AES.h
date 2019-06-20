//
//  AES.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2018/12/18.
//  Copyright © 2018年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AES : NSObject

+(NSData *) aes_encrypt_fun:(NSData* )src size:(UInt16)size_src key:(NSData *)key;
+(NSData *) aes_decrypt_fun:(NSData* )src size:(UInt16)size_src key:(NSData *)key;

@end
