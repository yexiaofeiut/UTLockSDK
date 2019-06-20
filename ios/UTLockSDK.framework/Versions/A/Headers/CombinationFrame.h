//
//  CombinationFrame.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/22.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CombinationProrotol <NSObject>

- (void)onFrameCombinationSuccess:(NSData *)frame;

@end

@interface CombinationFrame : NSObject

@property (nonatomic, weak) id<CombinationProrotol> delegate;

- (void)assembleData:(NSData *)data;

@end
