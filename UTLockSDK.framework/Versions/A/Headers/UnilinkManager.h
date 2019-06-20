//
//  UnilinkManager.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/4.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleDeviceOperateCallback.h"
#import "IScanDeviceCallback.h"
#import "IConnectCallback.h"
#import "LockStateListener.h"
#import "ConstParams.h"
#import "ControllerParaInfo.h"
@class CloudLock;
@class ScanDevice;
@class AuthInfo;

@interface UnilinkManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic ,assign) BOOL isBleStateOn;

@property (nonatomic ,assign) BOOL isSearching;

@property (nonatomic, assign)BOOL isConnected;

@property (nonatomic, assign)BOOL isBackgroudModel;
/**
 *初始化云锁SDK
 *
 **/
- (void)initUnilinkSDK;

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
 *蓝牙状态监听
 *@param lister 监听对象
 *
 **/
- (void)addLockStatusLister:(id<LockStateListener>)lister;
/**
 *删除蓝牙状态监听
 *@param lister 监听对象
 *
 **/
- (void)removeLockStatusLister:(id<LockStateListener>)lister;

/**
 * 查询指定设备是否已连接
 * @param deviceUUID 设备Mac地址
 * @return true:已连接 false:未连接
 */
- (BOOL)isConnect:(NSString *)deviceUUID;

/**
 * 搜索云锁设备
 * @param scanTime 搜索时间,以秒为单位
 * @return {-1 手机蓝牙没打开 0 打开搜索成功}
 */
- (int)scan:(int)scanTime;
/**
 * 搜索指定厂商和设备类型的云锁设备
 * @param scanTime 搜索时间,以秒为单位
 * @param vendorId 要搜索的厂商标识，为4个字节数组，可为null
 * @param deviceType 要搜索的设备类型，为2个字节数组，可为null
 * @return {@link -1 蓝牙没打开}、{@link 1 正在搜索 @link 0 开始搜索}
 */
- (int)scan:(int)scanTime vendorId:(int)vendorId deviceType:(int)deviceType;

/**
 *停止搜索
 *
 **/
- (void)stopScan;

/**
 * 连接指定云锁设备
 * @param mac 云锁设备UUID地址，可以从搜索获取的云锁设备{@link ScanDevice#getAddress()}得到
 * @param connectListener 连接结果监听器
 */
- (void)connect:(NSString *)mac;

/**
 * 断开连接指定云锁设备
 * @param mac 云锁设备UUID地址，可以从搜索获取的云锁设备{@link ScanDevice#getAddress()}得到
 * @param connectListener 连接结果监听器
 */
- (void)disconnect:(NSString *)mac;

/**
 * 连接指定蓝牙设备
 * @param scanDevice 蓝牙低功耗设备 通过扫描得到{@link #scan(ScanListener, int, byte[], byte[])、 {@link #scan(ScanListener, int)}}
 */
- (void)connectDevice:(ScanDevice *)scanDevice;

/**
 * <p>初始化云锁设备,用于激活云锁设备。
 * <p>调用成功后需要在5秒内调用{@link #confirmInit(CloudLock, CallBack)}进行确认初始化，确认初始化成功后，
 * 云锁设备才成功激活
 * @param scanDevice 蓝牙低功耗设备, 通过扫描得到{@link #scan(ScanListener, int, byte[], byte[])、 {@link #scan(ScanListener, int)}}
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)initLock:(ScanDevice *)scanDevice pwd:(NSString *)pwd success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>确认初始化云锁设备,用于激活云锁设备。
 * <p>在激活云锁设备时，需先初始化云锁设备{@link #initLock(ScanDevice, CallBack)}，并在5秒内调用该命令进行确认初始化。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 *     cloudLock.setAdminPassword(adminPW);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)confirmInit:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>对指定云锁设备进行开锁操作。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 *     cloudLock.setOpenLockPassword(adminPW);
 *     cloudLock.setEncryptType(encryptType);
 *     cloudLock.setEntryptKey(key);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)openLock:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>重置指定云锁设备。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 *     cloudLock.setAdminPassword(adminPW);
 *     cloudLock.setEncryptType(encryptType);
 *     cloudLock.setEntryptKey(key);
 * </pre>
 * @param lock 表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)resetLock:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>读取云锁设备自增变量。
 * <p>成功读取的自增变量保存到回调的lock对象中，使用{@link CloudLock#getAutuIncreaseNum()}获取。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)getAutoIncreaseNum:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 发送超级密码重置设备， 测试用
 * @param deviceUUID 设备Mac地址
 */
- (void)sendSuperPassword:(NSString *)deviceUUID;

/**
 * <p>读取云锁设备指定节点信息。
 * <p>参数lock对象需要先设置要读取的设备节点编号{@link CloudLock#setDeviceNum(byte)}
 * 成功读取后的设备节点信息保存到回调的lock对象中，使用{@link CloudLock#getDeviceInfo(byte)}读取。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 *     cloudLock.setEncryptType(encryptType);
 *     cloudLock.setEntryptKey(key);
 *     cloudLock.setDeviceNum(deviceNum);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)getDeviceInfo:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>读取云锁设备多个节点信息。
 * <p>成功读取后的设备节点信息保存到回调的lock对象中，使用{@link CloudLock#getDeviceInfoMap()}读取。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 *     cloudLock.setEncryptType(encryptType);
 *     cloudLock.setEntryptKey(key);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)getDeviceInfos:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>设置云锁设备的生产序列号。
 * <p>参数lock对象需要先设置要写入的生产序列号{@link CloudLock#setSerialNum(byte[])}。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 *     cloudLock.setSerialNum(serialNum);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口
 */
- (void)setSerialNum:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>读取生产序列号。
 * <p>读取到的数据存放到参数lock里，使用{@link CloudLock#getSerialNum()}获取。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口s
 */
- (void)getSerialNum:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>设置云锁设备的产商标识和设备类型。
 * <p>传入参数lock需先设置厂商标识和设备类型{@link CloudLock#setVendorId(byte[])}、{@link CloudLock#setDeviceType(byte[])}。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 *     cloudLock.setVendorId(vendorId);
 *     cloudLock.setDeviceType(deviceType);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口s
 */
- (void)setVendorId:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>读取云锁设备厂商标识和设备类型。
 * <p>读取到的数据存放到参数lock里，使用{@link CloudLock#getVendorId()}、{@link CloudLock#getDeviceType()}获取。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口s
 */
- (void)getVendorId:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>获取云锁设备产品信息。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口s
 */
- (void)getProductInfo:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>设置电机正转。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口s
 */
- (void)setMotorForward:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * <p>设置电机反转。
 * <p>调用命令前需要先激活云锁设备{@link #initLock(ScanDevice, CallBack)、 {@link #confirmInit(CloudLock, CallBack)}}。
 * <p><pre>参数lock对象有两种获取方式
 * 1.通过调用初始化命令成功后获取{@link #initLock(ScanDevice, CallBack)}
 * 2.手动创建,需要设置相应参数
 *
 *     CloudLock cloudLock = new CloudLock(mac);
 * </pre>
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口s
 */
- (void)setMotorReverse:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 新规约开锁
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)operateLock:(CloudLock *)lock controlType:(int)controlType gapTime:(int)gapTime success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 批量修改授权信息（需要先从设备中读取授权信息）
 * @param lock 表示某个云锁设备
 * @param success 操作回调接口，初始化成功会返回CloudLock对象
 * @param fail    操作失败回调接口
 * @param timeout 操作超时回调接口s
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

/**
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
- (void)deleteAuth:(CloudLock *)lock  authIdArr:(NSArray *)authIdArr success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 删除授权
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param authInfo     授权ID
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)updateAuth:(CloudLock *)lock authInfos:(NSArray<AuthInfo *> *)authInfos success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

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
- (void)readKeyInfos:(CloudLock *)lock readSerialNum:(int)readSerialNum  success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
 * 写钥匙信息
 * @param lock     表示某个云锁设备， 初始化云锁成功后{@link #initLock(ScanDevice, CallBack)}会返回相应CloudLock对象
 * @param success    操作成功回调接口
 * @param fail       操作失败回调接口
 * @param timeout    操作超时回调接口
 */
- (void)writeKeyInfos:(CloudLock *)lock gateLockKeys:(NSArray *)gateLockKeys readSerialNum:(int)readSerialNum currentSerialtotalNum:(int)currentSerialtotalNum  success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

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
 新增设备钥匙
 主设备写入注册流程控制信息
 @param uuid  锁的uuid
 @param encryptType 加密类型
 @param encryptKey 密钥
 @param isNeedPwd 是否验证密码
 @param keyRegistType 钥匙类型
 @param keyRegistControlInfo 注册流程点
 @param success 操作成功回调接口
 @param fail 操作失败回调接口
 @param timeout 操作超时回调接口
 */
- (void)devicekeyRegistControl:(CloudLock *)lock encryptType:(int)encryptType encryptKey:(NSData *)encryptKey isNeedPwd:(BOOL)isNeedPwd keyRegistType:(keyRegistType)keyRegistType keyRegistControlInfo:(keyRegistControlInfo)keyRegistControlInfo  success:(onOperateLockSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

/**
  新增设备钥匙
 录入密码

 @param uuid 锁的uuid
 @param encryptType 加密类型
 @param encryptKey 密钥
 @param userPwd 密码
 @param success 操作成功回调接口
 @param fail 操作失败回调接口
 @param timeout 操作超时回调接口
 */
- (void)registUserPwd:(CloudLock *)lock encryptType:(int)encryptType encryptKey:(NSData *)encryptKey userPwd:(NSString *)userPwd success:(onOperateLockSuccess)success
                 fail:(onOperateFail)fail
              timeout:(onOperateTimeout)timeout;


#pragma mark -- 主设备读取从设备控制参数
- (void)deviceReadParamterControl:(CloudLock *)lock success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

#pragma mark -- 主设备写入从设备控制参数
- (void)writeParamterControl:(CloudLock *)lock contolArr:(NSArray<ControllerParaInfo *>*)contolArr success:(onOperateSuccess)success fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;

#pragma mark--z重置管理员密码
- (void)resetAdminPsw:(CloudLock *)lock psw:(NSString *)psw success:(onOperateSuccess)success  fail:(onOperateFail)fail timeout:(onOperateTimeout)timeout;
@end
