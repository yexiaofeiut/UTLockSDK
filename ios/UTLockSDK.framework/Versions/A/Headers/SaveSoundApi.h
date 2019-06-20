//
//  SaveSoundApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/5/21.
//  Copyright © 2019 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface SaveSoundApi : APIRequest
- (id)initWithMobile:(NSString *)mac beeper:(int)beeper  doorBell:(int)doorBell volume:(int)volume;
@end

NS_ASSUME_NONNULL_END
