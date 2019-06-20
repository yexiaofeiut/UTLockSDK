//
//  Global.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/20.
//  Copyright © 2018年 叶小飞. All rights reserved.
//
typedef enum ModuleType {
    LockModule  = 0,
    KeyModule = 1,
    MeModule,
    MessageModule
} ModuleType;
typedef enum
{
    RequestDataTypeRefresh = 0, //刷新数据
    RequestDataTypeLoadMore = 1,//加载更多
    
    RequestDataTypeChangeSearchText, //修改搜索框文本内容
    RequestDataTypeSearchAction , //点击搜索按钮请求
    
    Search_RequestDataTypeRefresh = 4, //刷新数据_Search_
    Search_RequestDataTypeLoadMore = 5//加载更多_Search_
}RequestDataType;

#define localplist @"InfoPlist"
#define MainPageBoard [UIStoryboard storyboardWithName:@"mainPage" bundle:nil]
#define LoginModuleBoard [UIStoryboard storyboardWithName:@"LoginModule" bundle:nil]
#define MeModuleBoard [UIStoryboard storyboardWithName:@"Me" bundle:nil]
#define kNotificationUpdateUserTable @"kNotificationUpdateUserTable"
#define kNotificationUpdateLockTable @"kNotificationUpdateLockTable"
#define kNotificationUpdateKeyTable @"kNotificationUpdateKeyTable"
#define kNotificationUpdateKeyByLockMac @"kNotificationUpdateKeyByLockMac"
#define kNotificationUpdateGroupLockTable @"kNotificationUpdateGroupLockTable"
#define kNotificationUpdateLockLogTable @"kNotificationUpdateLockLogTable"
#define kNotificationUpdateMessageListTable @"kNotificationUpdateMessageListTable"
#define kNotificationUpdateApplyListTable @"kNotificationUpdateApplyListTable"
#define kNotificationSendKeySwitch @"kNotificationSendKeySwitch"
#define kNotificationUpdateDeviceKeyList @"kNotificationUpdateDeviceKeyList"
#define kNotificationUpdateDeviceKeyFromDb @"kNotificationUpdateDeviceKeyFromDb"
//刷新锁列表
#define kNotificationPageUserLock @"kNotificationPageUserLock"
//刷新钥匙列表
#define kNotificationPageKey @"kNotificationPageKey"
//同时刷新锁和钥匙列表
#define kNotificationPageKeyAndLock @"kNotificationPageKeyAndLock"

//刷新设备钥匙
#define kNotificationDeviceKey @"kNotificationDeviceKey"
#define UTString(str) NSLocalizedStringFromTable(str,localplist, nil)

//消息个数
#define kNotiNewMesCount @"kNotiNewMesCount"
//指定跳转页面
#define kJpushToVC @"kJpushToVC"
