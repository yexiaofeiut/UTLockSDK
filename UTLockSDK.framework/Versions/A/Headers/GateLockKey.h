//
//  GateLockKey.h
//  UTCloudLockSDK
//
//  Created by chen guichun on 2019/1/17.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, GateKeyType) {
    TYPE_FINGERPRINT = 0, //指纹钥
    TYPE_PASSWORD = 1,    //密码钥匙
    TYPE_ELECT = 2,       //电子钥匙
    TYPE_BLE = 3,         //蓝牙钥匙
    TYPE_CARD = 4         //卡片钥匙
};

@interface GateLockKey : NSObject

@property (nonatomic ,assign) int keyType;
@property (nonatomic ,assign) int attribute; //钥匙配置属性
@property (nonatomic ,assign) int innerNum;  //钥匙内部编号
@property (nonatomic ,assign) int keyId;     //钥匙编号

/**
 * 设置钥匙授权状态
 * @param isAuth ..
 */
- (void)setAuthState:(BOOL) isAuth;

/**
 * 获取钥匙授权状态
 * @return ..
 */
- (BOOL)isAuthKey;

/**
 * 获取钥匙名称备注状态
 * @return ..
 */
- (BOOL)isNameMark;
/**
 *
 * 设置钥匙名称备注状态
 * @param isMark ..
 */
- (void)setNameMarkState:(BOOL)isMark;
/**
 * 得到钥匙冻结状态
 * @return ..
 */
- (BOOL)isFreeze;
/**
 * 设置钥匙冻结状态
 * @param isFreeze ..
 */
- (void)setFreezeState:(BOOL)isFreeze;
@end
