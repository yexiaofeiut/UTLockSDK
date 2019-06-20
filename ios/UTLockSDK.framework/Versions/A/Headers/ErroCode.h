//
//  ErroCode.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/6.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(int, ErrorCode) {
    ERR_FUNCTION_CODE = 0x01,  //非法功能码
    ERR_DATA = 0x02,           //非法数据
    ERR_DEVICE_BUSY = 0x03,    //设备忙
    ERR_CHECK_CODE = 0x04,     //CRC校验错误
    ERR_REPEAT_CODE = 0x05,    //防重复攻击校验码错误
    ERR_OPERATE = 0x06,        //操作异常
    ERR_ADMIN_PASSWORD = 0x07,    //管理员密码校验失败
    ERR_OPENLOCK_PASSWORD = 0x08, //开锁密码校验失败
    ERR_ALREADY_ACTIVE = 0x09,    //重复激活错误
    ERR_NOT_ACTIVE = 0x0A,        //未激活错误
    ERR_WRITE_CODE = 0x0B,      //写入失败
    ERR_READ_CODE = 0x0C,       //读取失败
    RR_DECODE_CODE = 0x0D,        //数据解密异常
    ERR_LOCK_ADMINPWD_ERROR = 0x0E,    //认证密码校验失败
    
    ERR_BOOTSTATE_ERROR = 0x0F,
    
    ERR_CPU0_BOOT_COOD = 0xF0,    //主cpu处于boot状态
    ERR_CPU1_BOOT_COOD = 0x10,    //从cpu处于boot状态
    ERR_BIN_NOMATCH_COOD = 0x11,   //升级固件不匹配
    
    ERR_READ_BINFILE_CODE = 0x20,  //读取bin文件失败
    ERR_JUMPBOOT_DISCONNECT_CODE = 0x21,  //读取bin文件失败
    
    ERR_UPFATE_LOCK_FAIL_CODE = 0x22, //升级固件失败
    
    ERR_UNKNOW = 0xFF,            //未知错误
    ERR_TIMEOUT = -1,             //应答超时
    ERR_NO_CONNECT = -2,          //设备未连接
    
};

@interface ErroCode : NSObject

+ (NSString *)getErrorMessage:(int)errorCode;

@end
