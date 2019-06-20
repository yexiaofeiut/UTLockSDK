//
//  AddRegisterStatus.h
//  UTCloudLockSDK
//
//  Created by 叶小飞 on 2019/4/19.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import "ConstParams.h"

NS_ASSUME_NONNULL_BEGIN

@interface AddRegisterStatus : NSObject
//当注册类型为指纹时，状态信息定义如下:
//0x00: 请开始第一次扫描指纹； 注: 默认初始态，不需要上传；
//0x01：指纹已扫描一次，请再次扫描；
//0x02：指纹已扫描两次，请再次扫描；
//0x03：指纹登记成功，(提示退出或继续)；
//0x04：指纹重复登记，(提示退出或继续)；
//0x05：操作错误(输入错误)；
//0x06：操作已超时；
//0x07：登记指纹已满；
//0x08:  指纹扫描错误，请重新扫描（手机APP界面提示用户将手指擦干净或将手指平放在指纹头的中间位置，尽量保持三次扫描的位置一致）
//当注册类型为IC卡、电子钥匙或密码时，状态信息定义如下:
//0：请刷卡(请插入IC卡、请输入密码) 注:默认初始态，不需要上传；
//1：登记成功(提示退出或继续)；
//2：重复登记(提示退出或继续)；
//3：操作错误(输入错误)；
//4：操作已超时；
//5: 登记已满；

@property (nonatomic, assign) int status;
@property (nonatomic, assign) keyRegistType keyRegistType;
@property (nonatomic, assign) int keynumber;
@property (nonatomic, assign) int keyInerNumber;
+ (AddRegisterStatus *)parseAddRegisterStatus:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
