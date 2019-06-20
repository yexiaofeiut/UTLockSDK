//
//  ResultData.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/10.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ResultData : NSObject

@property (nonatomic ,assign) int number;

@property (nonatomic ,strong) NSData *value;

@end

@interface ResultMutilData : NSObject

@property (nonatomic ,assign) int number;

@property (nonatomic ,strong) NSDictionary *values;

@end

/**
 *返回操作授权表的数据
 **/
@interface ResultAuthData : NSObject

@property (nonatomic ,assign) int operateType;

@property (nonatomic ,assign) int authId;

@property (nonatomic ,strong) NSArray *authInfos;


@property (nonatomic ,assign) int searialNum;

@property (nonatomic ,assign) int validInfoNum;//有效授权信息条目数num<=20，当num=20时说明还有授权信息未读完，主设备可以递增读取序号继续读取。

@end
/**
 *返回读取钥匙管理配置表的数据
 **/
@interface ResultReadKeyInfoData : NSObject

@property (nonatomic ,assign) int keycount;

@property (nonatomic ,assign) int searialNum;

@property (nonatomic ,assign) int validInfoNum; 

@property (nonatomic ,strong) NSMutableArray *infosArr;
@end
/**
 *返回读取钥匙管理配置表的数据
 **/
@interface ResultReadLockControlParamer : NSObject

@property (nonatomic ,assign) int parmeterTypecount;

@property (nonatomic ,assign) int searialNum;

@property (nonatomic ,assign) int validInfoNum;

@property (nonatomic ,strong) NSMutableArray *infosArr;
@end
