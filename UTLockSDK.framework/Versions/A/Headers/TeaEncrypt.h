//
//  TeaEncrypt.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/6.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IEncrypt.h"

@interface TeaEncrypt : NSObject<IEncrypt>

- (instancetype)init:(Byte *)key withLegth:(int)length;

@end
