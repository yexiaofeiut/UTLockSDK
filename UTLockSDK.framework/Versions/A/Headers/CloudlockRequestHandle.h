//
//  CloudlockRequestHandle.h
//  CloudLock
//
//  Created by 叶小飞 on 2019/6/19.
//  Copyright © 2019 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "QueryLockInfoApi.h"
#import "AddAdminKeyApi.h"
#import "DeleteAdminKeyApi.h"
#import "UpdateLockNameApi.h"
#import "ApplyKeyApi.h"
#import "DeleteKeyApi.h"
#import "AddLogApi.h"
#import "AuthOpenLockApi.h"
#import "CloudLock.h"
#import <ProductInfo.h>
#import "DelGroupApi.h"
#import "DelKeyApi.h"
#import "UpdateGroupNameApi.h"
#import "PageLockUserKeyApi.h"
#import "PageAdminLockApi.h"
#import "PageLockUserApi.h"
#import "GetUserInfoByMobileApi.h"
#import "ChangeLockAdminApi.h"
#import "GetChangeAdminCodeApi.h"
#import "CloudlockRequestHandle.h"
#import "AddLogsApi.h"
#import "PageAdminLockApi.h"
#import "GetUserInfoByMobileApi.h"
#import "AboutCompanyInfoApi.h"
#import "GetNewMsgCountApi.h"
#import "GetMessageApi.h"
#import "ReadMessageApi.h"
#import "KeyApplyListApi.h"
#import "GetMessageDetailApi.h"
#import "IgnoreKeyApi.h"
#import "NewGroupApi.h"
#import "GetGroupApi.h"
#import "ChangeGroupApi.h"
#import "AddLockIntoGroupApi.h"
#import "DelLockFromGroupApi.h"
#import "UserLockApi.h"
#import "SendKeyApi.h"
#import "faultCodeListApi.h"
#import "PageKeyApi.h"
#import "ClearKeyApi.h"
#import "FrozenKeyApi.h"
#import "UNFrozenKeyApi.h"
#import "ToAuthApi.h"
#import "CancelAuthApi.h"
#import "DelKeyApi.h"
#import "UpdateKeyNameApi.h"
#import "PageLockLogApi.h"
#import "PageKeyLogApi.h"
#import "CloudLock.h"
#import "VeriUserPwdApi.h"
#import "SetCanOpenApi.h"
#import "AddfaultCodeApi.h"
#import "RequestGateLockKeysApi.h"
#import "InsertLockRecordApi.h"
#import "InnerLockApi.h"
#import "DelKeyApi.h"
#import "UpdateKeyInfoApi.h"
#import "DeleteDeviceKeyApi.h"
#import "CheckTimeApi.h"
#import "GetVersionInfoFormWeb.h"
#import "UpdateLockVersion.h"
#import "AddDeviceKeyApi.h"
#import "SaveSoundApi.h"
#import "SaveOpenApi.h"
#import "SavePryApi.h"
#import "GetAdminVeriCode.h"
#import "CheckLockAdminPwdVeriApi.h"
#import "DeviceKeyModel.h"
NS_ASSUME_NONNULL_BEGIN
typedef void(^onRequestMsgCallback)(id resultData,NSString* msgtip, NSError *error);
@interface CloudlockRequestHandle : NSObject
#pragma mark - 获取锁信息
+ (void)queryLockInfo:(NSString *)mac callBack:(onRequestMsgCallback)callback;
#pragma mark -绑定管理员
+ (void)addAdminKey:(CloudLock *)cloudLock callBack:(onRequestMsgCallback)callback;
#pragma mark -删除钥匙，并且是否删除相关的分配钥匙
+ (void)deleteKey:(long)keyId relation:(BOOL)isRelation callBack:(onRequestMsgCallback)callback;
#pragma mark -更新锁名称
+ (void)updateLockName:(NSString *)mac name:(NSString *)name callBack:(onRequestMsgCallback)callback;
#pragma mark -申请钥匙
+ (void)applyKey:(NSDictionary *)params callBack:(onRequestMsgCallback)callback;
#pragma mark -是否有权限开锁
+ (void)isAuthToOpenLock:(NSString *)mac callBack:(onRequestMsgCallback)callback;
#pragma mark -上传开锁记录列表（离线缓存后上传）
+ (void)uploadrecordsList:(NSString *)jsonStr callBack:(onRequestMsgCallback)callback;
#pragma mark - 上传开锁记录（在线）
+ (void)uploadrecord:(long)lockId keyId:(long)keyId type:(int)type openLockType:(int)openLockType elect:(int)elect ruleType:(int)ruleType callBack:(onRequestMsgCallback)callback;
#pragma mark - 解绑管理员
+ (void)deleteAdminKey:(NSString *)mac callBack:(onRequestMsgCallback)callback;
#pragma mark - 删除锁分组
+ (void)delGroupWithGroupId:(long)groupId callBack:(onRequestMsgCallback)callback;
#pragma mark - 删除钥匙
+ (void)delKeyWithKeyId:(long)keyId callBack:(onRequestMsgCallback)callback;
#pragma mark -更新钥匙名称
+ (void)updateKeyName:(long)keyId keyName:(NSString *)keyName callBack:(onRequestMsgCallback)callback;
#pragma mark -更新分组名称
+ (void)updateGroupName:(NSString *)name groupId:(long)groupId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 锁用户的钥匙
+ (void)pageLockUserKeyWithPage:(int)currentPage withSize:(int)pageSize userId:(long)userId callBack:(onRequestMsgCallback)callback;
#pragma mark -获取操作日志
+ (void)pageLockLog:(int)currentPage withSize:(int)pageSize lockId:(long)lockId callBack:(onRequestMsgCallback)callback;
#pragma mark -获取锁用户
+ (void)pageLockUserWithPage:(int)currentPage withSize:(int)pageSize userId:(long)userId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 获取用户基本信息（根据手机号）
+ (void)getUserInfoByMobile:(NSString *)mobile callBack:(onRequestMsgCallback)callback;
#pragma mark -- 转移管理员
+ (void)changeLockAdminWithMobile:(NSString *)mobile  macs:(NSString *)macs veriCode:(NSString *)veriCode callBack:(onRequestMsgCallback)callback;
+ (void)getChangeAdminCode:(onRequestMsgCallback)callback;
#pragma mark -- 当前为管理员的锁列表
+ (void)pageAdminLockWithPage:(int)currentPage withSize:(int)pageSize callBack:(onRequestMsgCallback)callback;
#pragma mark -- 用户锁下的钥匙列表
+ (void)pageKeyWithPage:(int)currentPage withSize:(int)pageSize mac:(NSString *)mac   callBack:(onRequestMsgCallback)callback;
#pragma mark -- 获取当前用户下的锁
+ (void)userLockApi:(int)currentPage withSize:(int)pageSize callBack:(onRequestMsgCallback)callback;
#pragma mark -- 忽略钥匙申请
+ (void)ignoreKeyWithapplyId:(long)applyId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 发送钥匙
+ (void)sendKeyWithaMobile:(NSString *)mobile mac:(NSString *)mac startTime:(NSString *)startTime endTime:(NSString *)endTime keyName:(NSString *)keyName startTimeRange:(NSString *)startTimeRange  endTimeRange:(NSString *)endTimeRange weeks:(NSString *)weeks ruleType:(int)ruleType isAdmin:(NSString *)isAdmin  totalNum:(int)totalNum callBack:(onRequestMsgCallback)callback;
#pragma mark -- 清空钥匙
+ (void)clearKeyWithMac:(NSString *)devMac callBack:(onRequestMsgCallback)callback;
#pragma mark --冻结钥匙
+ (void)frozenKeyWithKeyId:(long)keyId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 解除冻结钥匙
+ (void)unfrozenKeyWithKeyId:(long)keyId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 授权钥匙
+ (void)toAuthWithKeyId:(long)keyId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 取消授权钥匙
+ (void)cancelAuthWithKeyId:(long)keyId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 获取上报列表
+ (void)getfaultCode:(long)lockId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 增加上报日志
+ (void)addfaultCode:(long)lockId  keyId:(long)keyId groupId:(long)groupId reporterType:(int)reporterType keyType:(int)keyType faultId:(long)faultId lockFlowNo:(NSString *)lockFlowNo reporterName:(NSString *)reporterName faultCode:(NSString *)faultCode faultName:(NSString *)faultName lockName:(NSString *)lockName callBack:(onRequestMsgCallback)callback;
#pragma mark -- 获取锁分组列表
+ (void)getGroup:(onRequestMsgCallback)callback;
#pragma mark -- 添加锁进分组
+ (void)addLockIntoGroup:(NSString *)macs groupId:(long)groupId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 从分组中删除锁
+ (void)delLockFromGroup:(NSString *)mac groupId:(long)groupId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 将锁从一个分组移动到另一个分组
+ (void)changeGroupapi:(NSString *)mac groupId:(long)groupId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 新建锁分组
+ (void)newGroupWithName:(NSString *)name callBack:(onRequestMsgCallback)callback;
#pragma mark -- 未读和未处理消息个数接口
+ (void)getNewMsgCount:(onRequestMsgCallback)callback;
#pragma mark -- 获取消息列表
+ (void)getNewMsg:(onRequestMsgCallback)callback;
#pragma mark -- 读消息
+ (void)readMessageApiWithLockMac:(NSString *)lockMac callBack:(onRequestMsgCallback)callback;
#pragma mark -- 钥匙申请记录列表
+ (void)keyApplyList:(onRequestMsgCallback)callback;
#pragma mark -- 申请记录详情
+ (void)getMessageDetailWithLockMac:(NSString *)lockMac callBack:(onRequestMsgCallback)callback;
#pragma mark -- 修改触摸开锁
+ (void)setCanOpenWithKeyId:(long)keyId  canOpen:(int)canOpen callBack:(onRequestMsgCallback)callback;
//系统
+ (void)getAboutCompanyInfo:(onRequestMsgCallback)callback;

#pragma mark -- 获取家居锁所有钥匙信息
+(void)requestKeysInfo:(long)lockId keyType:(int)type callBack:(onRequestMsgCallback)callback;

#pragma mark -- 初始化门锁钥匙信息
+ (void)addDeviceKeysInfo:(long)lockId keysDataJson:(NSString *)keysJson callBack:(onRequestMsgCallback)callback;

#pragma mark -- 添加门锁开锁记录
+ (void)addLockRecord:(long)lockId recordData:(NSString *)recordArr callBack:(onRequestMsgCallback)callback;

#pragma mark -- 删除门锁钥匙信息
+ (void)deleteDeviceKey:(long)lockId key:(long)keyId callBack:(onRequestMsgCallback)callback;
#pragma mark -- 更新钥匙信息
+ (void)updateKeyInfo:(NSString *)deviceKeyJsonstr callBack:(onRequestMsgCallback)callback;
#pragma mark -- 获取最新版本
+ (void)getVersionInfos:(onRequestMsgCallback)callback;
#pragma mark -- 修改锁版本
+ (void)updateLockVersion:(NSString *)mac lockVersion:(NSString *)lockVersion  callBack:(onRequestMsgCallback)callback;
#pragma mark -- 门锁提示音
+ (void)saveControlparaSettings:(NSString *)mac openVal:(int)openVal doorBell:(int)doorBell volume:(int)volume pryVal:(int)pryVal beeper:(int)beeper callback:(onRequestMsgCallback)callback;
#pragma mark -- 常开设置
+ (void)saveOpenVal:(NSString *)mac isopen:(int)isopen  callback:(onRequestMsgCallback)callback;
#pragma mark -- 防撬报警
+ (void)savePryVal:(NSString *)mac isopen:(int)isopen  callback:(onRequestMsgCallback)callback;
#pragma mark -- 获取重置管理员密码验证码
+ (void)getAdminVeriCode:(NSString *)mac callback:(onRequestMsgCallback)callback;
#pragma mark -- 判断重置管理员密码的验证码
+ (void)checkLockAdminPwdVeri:(NSString *)mac code:(NSString *)code callback:(onRequestMsgCallback)callback;
#pragma mark -- 添加钥匙信息
+ (void)addKeyState:(DeviceKeyModel *)deviceKey callBack:(onRequestMsgCallback)callback;
#pragma mark -- 对时
+ (void)checkTimeApi:(onRequestMsgCallback)callback;

@end

NS_ASSUME_NONNULL_END
