//
//  AesEncrypt.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2018/12/18.
//  Copyright © 2018年 chen guichun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IEncrypt.h"

@interface AesEncrypt : NSObject <IEncrypt>

- (instancetype)init:(Byte *)key withLegth:(int)length;

@end
