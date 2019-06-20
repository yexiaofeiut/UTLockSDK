//
//  IEncrypt.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/6.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IEncrypt <NSObject>

- (NSData *)encrypt:(NSData *)src;

- (NSData *)decrypt:(NSData *)src;

@end
