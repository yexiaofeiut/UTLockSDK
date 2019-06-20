//
//  DeviceKeyModel.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/1/16.
//  Copyright © 2019年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


static int MAXOPENLOCKCOUNT = 255;

typedef NS_ENUM(int, DeviceKeyType) {
    GATELOCK_FINGER_KEY,
    GATELOCK_PASSWORD_KEY,
    GATELOCK_ELECT_KEY,
    GATELOCK_MOBILE_KEY,
    GATELOCK_CARD_KEY
};

@interface DeviceKeyModel : NSObject <NSCoding>

@property (nonatomic, assign) long keyID;
@property (nonatomic, assign) int keyType;
@property (nonatomic, assign) int keyCfg;//钥匙配置属性；
@property (nonatomic, assign) long keyInId;//钥匙内部编号
@property (nonatomic, assign) int  isAuthKey;//是授权钥匙还是正常钥匙 0：正常钥匙;1:授权钥匙
@property (nonatomic, assign) int  keyStatus;//0:正常;1:已过期;2:已失效;3:已冻结
@property (nonatomic, assign) int  keyAuthType;//0:永久;1：限时;2:循环
@property (nonatomic, assign) long  authId;     //授权编号
@property (nonatomic, assign) int  openLockCnt;  //开锁次数   预留
@property (nonatomic, strong) NSString * timeICtl;         //时间控制,控制星期几有效
@property (nonatomic, assign) long  timeStart;     //开始时间
@property (nonatomic, assign) long  timeEnd;         //结束时间
@property (nonatomic, assign) int  openLockCntUsed;//已开锁次数
@property (nonatomic, assign) long  lockID;//锁对应的id
@property (nonatomic, strong) NSString *name;
@property (nonatomic, assign) long deviceId;
- (NSString *)getDeviceName;
- (NSString *)keysTypeName;
- (int)getDeviceKeyState;
- (NSString *)getStartTime;
- (NSString *)getEndTime;
+(BOOL)insertObjectWithModelList:(NSArray *)objectArray;
+(NSMutableArray *)searchDataByKeyType:(int)keyType andLockID:(long)lockId;
+(NSMutableArray *)searchAllData;
+(NSArray *)searchDataByKeyId:(long)keyID andLockID:(long)lockId;
+(BOOL)updateDataByKeyState:(DeviceKeyModel *)deviceKey;
+(BOOL)deleteAllData;
+(BOOL)deleteKey:(DeviceKeyModel *)deviceKey;
@end

NS_ASSUME_NONNULL_END
