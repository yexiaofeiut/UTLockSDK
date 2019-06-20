//
//  FrameBase.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface FrameBase : NSObject

@property (nonatomic, readonly, strong)NSData *byteData;

//- (instancetype)init:(int)linkID cmd:(int)cmd encrypt:(EncryptType)encryptType btext:(NSData *)content;

@end
