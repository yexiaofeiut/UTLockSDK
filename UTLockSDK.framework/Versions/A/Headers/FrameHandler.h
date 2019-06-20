//
//  FrameHandler.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/15.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FrameHandler : NSObject

- (void)setFrameSize:(int)size;

-(NSMutableArray *)handleSend:(NSData *)msg;

-(NSData *)handleReceive:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
