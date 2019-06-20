//
//  CloudLock.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/5.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ScanDevice;
@class ProductInfo;
@class ControllerParaInfo;
@interface CloudLock : NSObject <NSCoding>

- (instancetype)init:(NSString *)deviceUUID;

/**
 * 获取云锁设备UUID地址
 */
@property (nonatomic, strong) NSString *deviceUUID;

/**
 * 获取云锁设备mac地址
 */
@property (nonatomic, strong) NSString *mac;

/**
 * 获取云锁设备名称
 */
@property (nonatomic, strong) NSString *name;

/**
 * 管理员密码
 */
@property (nonatomic, strong) NSString *adminPassword;
/**
 * 开锁密码
 */
@property (nonatomic, strong) NSString * openLockPassword;
/**
 * 加密密钥
 */
@property (nonatomic, strong) NSString * entryptKey;

/**
 * 加密方式 0：TEA加密   1：AES加密
 */
@property (nonatomic, assign) int encryptType;
/**
 *管理员密码byte数据
 */
@property (nonatomic, strong) NSData *adminPswArray;
/**
 *开锁密码byte数据
 */
@property (nonatomic, strong) NSData *openLockPswArray;
/**
 *加密密钥byte数据
 */
@property (nonatomic, strong) NSData *secretKeyArray;
/**
 *加密方式byte数据
 */
@property (nonatomic, strong) NSData *encryptTypeArray;

/**
 * 自增变量
 */
@property (nonatomic, assign) int autuIncreaseNum;
/**
 * 搜索到的蓝牙设备
 */
@property (nonatomic, strong) ScanDevice *bleDevice;
/**
 * 设备编号
 */
@property (nonatomic, assign) int currentDeviceNum;          //当前想要读取的设备编号，用于读取从设备节点信息命令
/**
 * 设备类型
 */
@property (nonatomic, assign) int deviceType;
/**
 * 云锁激活状态
 */
@property (nonatomic, assign) BOOL isActive;
/**
 * 设置厂商标识
 */
@property (nonatomic, assign) int vendorId;
/**
 * 设备节点信息
 */
@property (nonatomic, strong) NSMutableDictionary<NSString *, NSData *> *deviceInfoMap ;
/**
 * 设备的产品信息
 */
@property (nonatomic, strong) ProductInfo *productInfo;

/**
 * 设备控制参数
 */
@property (nonatomic, strong) NSArray<ControllerParaInfo *>  *controlInfoArr;

/**
 * 获取设备的版本
 */
@property (nonatomic, strong) NSString *version;

/**
 * 生产序列号
 */
@property (nonatomic, strong) NSData *serialNum;

/**
 * 获取设备的所有节点信息
 * @return 设备节点信息Map
 */
- (NSDictionary *) getDeviceInfoMap;

/**
 * 设置设备的所有节点信息
 * @param deviceInfoMap ..
 */
- (void)setDeviceInfoMap:(NSMutableDictionary<NSString *, NSData *> *)deviceInfoMap;

/**
 * 获取指定设备节点信息
 * @param deviceNum ..
 * @return 设备节点信息
 */
- (NSData *)getDeviceInfo:(NSString *)deviceNum;

/**
 * 添加指定设备节点信息
 * @param deviceNum ..
 * @param deviceInfo ..
 */
- (void)addDeviceInfo:(NSString *) deviceNum info:(NSData *)deviceInfo;

@end
