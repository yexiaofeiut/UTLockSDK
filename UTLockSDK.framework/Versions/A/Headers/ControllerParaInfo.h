//
//  ControllerParaInfo.h
//  UTCloudLockSDK
//
//  Created by 叶小飞 on 2019/5/17.
//  Copyright © 2019 chen guichun. All rights reserved.
//

#import <Foundation/Foundation.h>
//0x00：开锁提示音开关(默认为0x00)；
//0x01: 音量大小(默认为0x01)；
//0x02：防破门报警开关(默认为0x01)；
//0x03：门铃提示音开关(默认为0x01)；
//0x04：常开设置开关(默认为0x00)；
typedef NS_ENUM(int, ControlType) {
    Beeper = 0x00,
    Volume = 0x01,
    PryVal = 0x02,
    DoorBell = 0x03,
    Openval = 0x04

};
typedef NS_ENUM(int, ControlValue) {
   Control_off = 0x00,
   Control_on = 0x01,
   Control_other = 0x02
};
NS_ASSUME_NONNULL_BEGIN

@interface ControllerParaInfo : NSObject
@property (nonatomic ,assign) ControlType paraType;
@property (nonatomic ,assign)  int paraLength;
@property (nonatomic ,assign) ControlValue paraData;
@end

NS_ASSUME_NONNULL_END
