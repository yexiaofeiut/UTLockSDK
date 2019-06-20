//
//  URLConfig.h
//  CloudLock
//
//  Created by ace on 2018/6/29.
//  Copyright © 2018年 ut. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface URLConfig : NSObject
- (void)createUUID;

+ (URLConfig * _Nonnull)sharedInstance;
-(NSString *_Nullable) getLoginURL;
-(NSString *_Nullable) getVerifCodeURL;
#pragma mark - 获取注册验证码
-(NSString *_Nullable) getRegisterURL;
#pragma mark - 获取忘记密码验证码
-(NSString *_Nullable) getFindPasswordURL;
-(NSString *_Nonnull) getUploadImgURL;
-(NSString *_Nonnull) getLoginInfoURL;
-(NSString *_Nonnull) getLogoutURL;
#pragma mark - 发送短信验证码（除注册和忘记密码的发送验证码）
-(NSString *_Nullable) sendMobileCodeURL;
#pragma mark -- 用验证码登录
-(NSString *_Nonnull) loginByVerifyCodeURL;
#pragma mark - 获取忘记密码验证码
-(NSString *_Nonnull) getForgetPwdVeriCodeURL;
#pragma mark - 转移管理员时获取验证
-(NSString *_Nonnull) getChangeAdminCodeURL;
#pragma mark -- 修改头像
-(NSString *_Nonnull) getUploadHeadURL;
#pragma mark -- 修改姓名
-(NSString *_Nonnull) getUpdateNameURL;
#pragma mark -- 修改配置启用状态
-(NSString *_Nonnull) getChangeUserConfigURL;
#pragma mark -- 绑定管理员
- (NSString *_Nonnull)getAddAdminLockURL;
#pragma mark -- 转移管理员
- (NSString *_Nullable)changeLockAdminURL;
#pragma mark -- 获取用户基本信息（根据手机号）
- (NSString *_Nonnull)getUserInfoByMobileURL;
#pragma mark -- 获取当前用户下的锁
- (NSString *_Nonnull)getPageUserLockURL;
#pragma mark -- 锁用户列表
- (NSString *_Nonnull)getPageLockUserURL;
#pragma mark -- 锁用户的钥匙
- (NSString *_Nonnull)getPageLockUserKeyURL;
#pragma mark -- 删除钥匙
- (NSString *_Nonnull)getDelKeyURL;
#pragma mark -- 当前为管理员的锁列表
- (NSString *_Nonnull)getPageAdminLockURL;
#pragma mark -- 修改锁分组名称
- (NSString *_Nonnull)updateGroupNameURL;
#pragma mark -- 删除分组
- (NSString *_Nonnull)delGroupURL;
#pragma mark -- 获取锁分组列表
- (NSString *_Nonnull)getLockGroupURL;
#pragma mark -- 添加锁进分组
- (NSString *_Nonnull)addLockIntoGroupURL;
#pragma mark -- 从分组中删除锁
- (NSString *_Nonnull)delLockFromGroupURL;
#pragma mark -- 新建锁分组
- (NSString *_Nonnull)getNewGroupURL;
#pragma mark -- 将锁从一个分组移动到另一个分组
- (NSString *_Nonnull)changeGroupURL;
#pragma mark -- 获取某分组内锁信息
- (NSString *_Nonnull)getLockInfoFromGroupURL;
#pragma mark -- 获取消息列表
- (NSString *_Nonnull)getMessageURL;
#pragma mark -- 读消息
- (NSString *_Nonnull)getReadMessageURL;
#pragma mark -- 未读和未处理消息个数接口
- (NSString *_Nonnull)getNewMsgCountURL;
#pragma mark -- 获取某把锁的所有消息（二级消息菜单）
- (NSString *_Nonnull)getMessageDetailURL;
#pragma mark -- 钥匙申请记录列表
- (NSString *_Nonnull)getkeyApplyListURL;
#pragma mark -- 申请记录详情
- (NSString *_Nonnull)getApplyDetailURL;
#pragma mark -- 发送钥匙
- (NSString *_Nonnull)sendKeyURL;
#pragma mark -- 忽略钥匙申请
- (NSString *_Nonnull)ignoreKeyURL;

#pragma mark -- 冻结钥匙
- (NSString *_Nonnull)frozenKeyURL;
#pragma mark -- 解除冻结钥匙
- (NSString *_Nullable)unFrozenKeyURL;

#pragma mark -- 查询锁信息
- (NSString *_Nonnull)queryLockInfo;
#pragma mark -- 修改锁名称
- (NSString *_Nonnull)updateLockName;
#pragma mark -- 申请钥匙
- (NSString *_Nullable)applyKey;
#pragma mark -- 添加管理员钥匙
- (NSString *_Nonnull)addAdminKey;
#pragma mark -- 删除管理员钥匙
- (NSString *_Nullable)deleteAdminKey;
#pragma mark -- 删除钥匙
- (NSString *_Nonnull)deleteKey;
#pragma mark -- 用户锁下的钥匙列表
- (NSString *_Nonnull)querypageKeyURL;
#pragma mark -- 清空钥匙
- (NSString *_Nonnull)clearKeyURL;
#pragma mark -- 修改钥匙规则
- (NSString *_Nonnull)modifyKeyRuleURL;
#pragma mark -- 修改钥匙名称
- (NSString *_Nonnull)updateKeyNameURL;
#pragma mark -- 授权钥匙
- (NSString *_Nonnull)toAuthURL;
#pragma mark -- 取消授权钥匙
- (NSString *_Nonnull)cancelAuthURL;
#pragma mark -- 查找锁日志
- (NSString *_Nonnull)pageLockLogURL;
#pragma mark -- 根据钥匙查找锁日志
- (NSString *_Nonnull)pageKeyLogURL;
#pragma mark -- 验证用户密码
- (NSString *_Nonnull)veriUserURL;
#pragma mark -- 添加日志
- (NSString *_Nonnull)addLogURL;
#pragma mark -- 批量上传日志
- (NSString *_Nonnull)addLogsURL;
#pragma mark -- 获取最新版本
- (NSString *_Nonnull)getNewVersionURL;
#pragma mark -- 判断是否允许开锁
- (NSString *_Nonnull)authOpenLockURL;
#pragma mark -- 修改触摸开锁
- (NSString *_Nonnull)setCanOpenURL;
#pragma mark -- 添加钥匙信息
- (NSString *_Nonnull)addKeyInfoURL;
#pragma mark -- 更新钥匙信息
- (NSString *_Nonnull)updateKeyInfoURL;
#pragma mark -- 对时
- (NSString *_Nonnull)checkTimeURL;
#pragma mark -- 初始化钥匙信息
- (NSString *_Nonnull)innerLockURL;
#pragma mark -- 删除钥匙信息
- (NSString *_Nonnull)delKeyInfoURL;
#pragma mark -- 获取家居锁所有钥匙信息
- (NSString *_Nonnull)getGateLockKeysURL;
#pragma mark -- 添加门锁开锁记录
- (NSString *_Nonnull)innsertGateLockRecordURL;
#pragma mark -- 删除门锁钥匙信息
- (NSString *_Nonnull)deleteDeviceKeyURL;
#pragma mark -- 获取上报列表
- (NSString *_Nonnull)faultCodelistURL;
#pragma mark -- 增加上报日志
- (NSString *_Nonnull)addfaultCodeURL;
#pragma mark -- 修改锁版本
- (NSString *_Nonnull)updateLockVersionURL;
#pragma mark -- 添加单个设备钥匙
- (NSString *_Nonnull)addKeyURL;
#pragma mark -- 保存门锁设置
- (NSString *_Nonnull)saveSettingsURL;
#pragma mark -- 门锁提示音
- (NSString *_Nonnull)saveSoundURL;
#pragma mark -- 常开设置
- (NSString *_Nonnull)saveOpenURL;
#pragma mark -- 防撬报警
- (NSString *_Nonnull)savePryURL;
#pragma mark -- 获取重置管理员密码验证码
- (NSString *_Nonnull)getAdminVeriCodeURL;
#pragma mark -- 保存管理员密码
- (NSString *_Nonnull)saveLockAdminPwdURL;
#pragma mark -- 判断重置管理员密码的验证码
- (NSString *)checkLockAdminPwdVeriURL;
@end
