//
//  AddfaultCodeApi.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/3/19.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import "APIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface AddfaultCodeApi : APIRequest
- (instancetype)initLockId:(long)lockId keyId:(long)keyId groupId:(long)groupId reporterType:(int)reporterType keyType:(int)keyType faultId:(long)faultId lockFlowNo:(NSString *)lockFlowNo reporterName:(NSString *)reporterName faultCode:(NSString *)faultCode faultName:(NSString *)faultName lockName:(NSString *)lockName;
@end

NS_ASSUME_NONNULL_END
