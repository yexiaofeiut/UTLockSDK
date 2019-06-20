//
//  BleMsg.h
//  CloudLock
//
//  Created by 叶小飞 on 2018/11/16.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IEncrypt.h"
typedef enum ENCRYPT_TYPE {
    ENCRYPT_TYPE_NO = -1,           //不加密
    ENCRYPT_TYPE_DYNAMIC = 0 ,   //动态加密方式
    ENCRYPT_TYPE_FIXED = 1, //固定加密方式
    
} ENCRYPT_TYPE;

NS_ASSUME_NONNULL_BEGIN

@interface BleMsg : NSObject
@property (nonatomic,assign) Byte cmdCode;      //功能码
@property (nonatomic,assign) BOOL isResponseError; //是否发生错误
@property (nonatomic,assign) int dataLength;    //数据正文字节长度
@property (nonatomic,assign) BOOL isEncrypt;
@property (nonatomic,strong) NSData * content;   //正文数据
@property (nonatomic,assign) Byte requestID;
@property (nonatomic,strong) id<IEncrypt> mEntrypt; //加密类型
@property (nonatomic,assign) ENCRYPT_TYPE encryptType; //操作类型

- (NSMutableData * )encode;

+ (BleMsg *)decode:(NSData *)data encrypt:(id<IEncrypt>)encrypt;

@end

NS_ASSUME_NONNULL_END
