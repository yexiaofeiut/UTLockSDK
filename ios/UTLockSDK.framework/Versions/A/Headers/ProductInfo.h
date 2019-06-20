//
//  ProductInfo.h
//  CloudLock
//
//  Created by chen guichun on 2018/11/28.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ProductInfo : NSObject

@property (nonatomic, strong)NSString *protocolVer;     //规约版本

@property (nonatomic, strong)NSData *serialNum;   //生产序列号

@property (nonatomic, strong)NSData *vendorId;    //厂商标识

@property (nonatomic, assign)int  deviceType;     //设备类型

@property (nonatomic, strong)NSString *cpu0AppVer;  //cpu0版本信息

@property (nonatomic, strong)NSString *cpu1AppVer;  //cpu1版本信息

@property (nonatomic, strong)NSString *cpu0BootVer;  //cpu0版本信息

@property (nonatomic, strong)NSString *cpu1BootVer;  //cpu1版本信息
@end
