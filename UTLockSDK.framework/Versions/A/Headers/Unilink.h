//
//  Unilink.h
//  CloudLock
//
//  Created by chen guichun on 2018/11/29.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleDeviceOperateCallback.h"
#import "IScanDeviceCallback.h"
#import "IConnectCallback.h"
#import "LockStateListener.h"
#import "ConstParams.h"
#import "ControllerParaInfo.h"
@class AuthInfo;

@interface Unilink : NSObject

@property (nonatomic, assign)BOOL isBleStateOn;

@property (nonatomic, assign)BOOL isSearching;

@property (nonatomic, assign)BOOL isConnected;

@property (nonatomic, assign)BOOL isBackgroudModel;

/**
 *添加蓝牙搜索监听
 *@param listener 监听对象
 **/
- (void)addScanListener:(id<IScanDeviceCallback>)listener;
/**
 *删除蓝牙搜索监听
 *@param listener 监听对象
 **/
- (void)removeScanListener:(id<IScanDeviceCallback>)listener;

/**
 *添加蓝牙搜索监听
 *@param listener 监听对象
 **/
- (void)addConnectListener:(id<IConnectCallback>)listener;
/**
 *删除蓝牙搜索监听
 *@param listener 监听对象
 **/
- (void)removeConnectListener:(id<IConnectCallback>)listener;

/**
 *添加蓝牙状态监听
 *@param listener 监听对象
 **/
- (void)addLockStateListener:(id<LockStateListener>)listener;
/**
 *删除蓝牙状态监听
 *@param listener 监听对象
 **/
- (void)removeLockStateListener:(id<LockStateListener>)listener;

- (BOOL)isConnect:(NSString *)deviceUUID;

- (int)scan:(int)scanTime;

- (int)scan:(int)scanTime vendorId:(NSData *)vendorId deviceType:(int)deviceType;

- (void)stopScan;

- (void)connect:(NSString *)mac;

/**
 * 连接指定蓝牙设备
 *
 * @param uuid           设备MAC地址
 */
- (void)connectWithUUID:(NSString *)uuid;
/**
 * 连接指定蓝牙设备
 *
 * @param scanDevice           蓝牙低功耗设备
 */
- (void)connectWithDevice:(ScanDevice *)scanDevice;

/**
 *断开连接
 *@param mac mac地址
 **/
- (void)disconnect:(NSString *)mac;

/**
 *发送数据
 *@param deviceUUID 设备UUID
 *@param data 要发送的数据
 **/
- (void)send:(NSString *)deviceUUID data:(NSData *)data requestID:(int)requestID;

/**
 * 初始化云锁设备
 *
 * @param scanDevice 蓝牙低功耗设备
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)initLock:(ScanDevice *)scanDevice pwd:(NSString *)pwd success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 确认初始化
 * @param lock .     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)confirmInit:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 对指定云锁设备进行开锁操作
 *
 * @param lock       表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)openLock:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 设置电机正转
 *
 * @param lock       表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)setMotorForward:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 设置电机反转
 *
 * @param lock       表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)setMotorReverse:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 重置指定云锁设备
 *
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)resetLock:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 主设备读从设备指定节点信息
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readDeviceInfo:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 主设备读从设备多点节点信息
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readMutilDeviceInfo:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 获取设备产品信息
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)getProductInfo:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 写入从设备生产序列号
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)writeSerialNum:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 读取生产序列号， 读取到的数据存放到参数lock里
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readSerialNum:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 写入从设备厂商标识
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)writeVendorId:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 读取从设备厂商标识和设备类型， 读取到的数据存放到参数lock里
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readVendorId:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 读取自增变量
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readAutoIncreaseNum:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 新规约开锁
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)operateLock:(CloudLock *)lock controlType:(int)controlType gapTime:(int)gapTime success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

#pragma mark - 家居锁
/**
 * 批量更新授权信息
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param authInfos  授权信息
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)batchUpdateAuthInfos:(CloudLock *)lock authInfos:(NSArray *)authInfos searialNum:(int)searialNum currentSerialtotalNum:(int)currentSerialtotalNum success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 删除钥匙
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param keyId      钥匙ID
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)deleteKey:(CloudLock *)lock keyID:(int)keyId success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**x
 * 增加授权
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param authInfo   授权信息
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)addAuth:(CloudLock *)lock authInfos:(NSArray<AuthInfo *> *)authInfos success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 删除授权
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param authId     授权ID
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)deleteAuth:(CloudLock *)lock authIdArr:(NSArray *)authIdArr success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 删除授权
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param authInfo     授权ID
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)updateAuth:(CloudLock *)lock authInfos:(NSArray<AuthInfo *> *)authInfos success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

- (void)operateAuthTable:(CloudLock *)lock operateType:(int)operateType operateAuthIdArr:(NSArray *)operateAuthIdArr authInfoArr:(NSArray<AuthInfo *> *)authInfoArr isAllOprate:(BOOL)isAllOprate searialNum:(int)searialNum  success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 获取某一个授权
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param authInfo     授权ID
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)queryAuthById:(CloudLock *)lock authIdArr:(NSArray *)authIdArr success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 获取所有授权
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)queryAllAuth:(CloudLock *)lock searialNum:(int)searialNum  success:(onOperateLockSuccess)success  fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 获取授权次数
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readAuthCountInfo:(CloudLock *)lock success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 读取钥匙信息
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readKeyInfos:(CloudLock *)lock  readSerialNum:(int)readSerialNum success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeou;

/**
 * 写钥匙信息
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)writeKeyInfos:(CloudLock *)lock gateLockKeys:(NSArray *)gateLockKeys  readSerialNum:(int)readSerialNum currentSerialtotalNum:(int)currentSerialtotalNum success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 读取开锁记录
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readGateLockOpenLockRecord:(CloudLock *)lock readSerialNum:(int)readSerialNum success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 读取锁时间
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readTime:(CloudLock *)lock success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 写锁时间
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)writeTime:(CloudLock *)lock time:(int)time success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 获取cpu 的状态
 * @param uuid       锁的uuid
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)readCPUState:(NSString *)uuid
             success:(onOperateLockSuccess)success
                fail:(onOperateFail)fail
             timeout:(onOperateTimeout)timeout;

/**
 * 升级锁固件
 * @param uuid       锁的uuid
 * @param path       bin文件存储路径
 * @param cpuType    cpu类型 0升级主cpu 1升级次cpu
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)updateGateLockFirmware:(NSString *)uuid
                      filePath:(NSString *)path
                       cpuType:(int)cpuType
                       success:(onOperateLockSuccess)success
                          fail:(onOperateFail)fail
                       timeout:(onOperateTimeout)timeout;



/**
 主设备写入注册流程控制信息

 @param uuid  锁的uuid
 @param encryptType 加密类型
 @param encryptKey 密钥
 @param isNeedPwd 需要管理员密码验证
 @param keyRegistType 注册类型定
 @param keyRegistControlInfo 控制信息
 @param success  操作成功回调接口
 @param fail 操作失败回调接口
 @param timeout 操作超时回调接口
 */
- (void)keyRegistControl:(CloudLock *)lock encryptType:(int)encryptType encryptKey:(NSData *)encryptKey isNeedPwd:(BOOL)isNeedPwd keyRegistType:(keyRegistType)keyRegistType keyRegistControlInfo:(keyRegistControlInfo)keyRegistControlInfo  success:(onOperateLockSuccess)success
                    fail:(onOperateFail)fail
                 timeout:(onOperateTimeout)timeout;

#pragma mark -- 主设备验证注册流程密码
- (void)registUserPwd:(CloudLock *)lock encryptType:(int)encryptType encryptKey:(NSData *)encryptKey userPwd:(NSString *)userPwd success:(onOperateLockSuccess)success
                 fail:(onOperateFail)fail
              timeout:(onOperateTimeout)timeout;

#pragma mark -- 从设备上传注册流程状态

- (void)setKeyRegistProcessListener;

#pragma mark -- 主设备读取从设备控制参数
- (void)deviceReadParamterControl:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

#pragma mark -- 主设备写入从设备控制参数
- (void)writeParamterControl:(CloudLock *)lock contolArr:(NSArray<ControllerParaInfo *>*)contolArr success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;
#pragma mark--z重置管理员密码
- (void)resetAdminPsw:(CloudLock *)lock  psw:(NSString *)psw success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;
@end
