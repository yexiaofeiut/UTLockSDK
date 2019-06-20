//
//  ConstParams.h
//  UTCloudLockSDK
//
//  Created by 叶小飞 on 2019/4/18.
//  Copyright © 2019年 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
//注册类型定义:
//0x00：指纹类型
//0x01：IC卡类型
//0x02：电子钥匙类型
//0x03：密码类型
//其他值：未定义
typedef NS_ENUM(NSUInteger, keyRegistType) {
    FINGER = 0x00,
    IC = 0x01,
    ELECTRICITYKEY = 0x02,
    PASSWORD = 0x03,
};
//控制信息定义:
//0x00：启动
//0x01：继续
//0x02：完成
//0x03：终止

typedef NS_ENUM(NSUInteger, keyRegistControlInfo) {
    START = 0x00,
    CONTINUE = 0x01,
    FINISH = 0x02,
    END = 0x03,
};


NS_ASSUME_NONNULL_BEGIN

@interface ConstParams : NSObject

@end

NS_ASSUME_NONNULL_END
