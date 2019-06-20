//
//  APIRequest.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/6.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <YTKNetwork/YTKNetwork.h>
#import "URLConfig.h"
NS_ASSUME_NONNULL_BEGIN

@interface APIRequest : YTKRequest
@property(nonatomic,assign)BOOL isWithAppid;
- (NSString *)msgtip;
- (int)code;
- (instancetype)data ;
@end

NS_ASSUME_NONNULL_END
