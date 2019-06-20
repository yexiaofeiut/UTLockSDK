//
//  Random.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/7.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Random : NSObject

/**
 *产生一个len字节的随机数
 *
 *@param len  产生的随机数的字节长度
 **/
+ (NSData *)random:(int)len;

@end
