//
//  MacroDefinitionHeader.h
//  CloudLock
//
//  Created by chen guichun on 2018/12/3.
//  Copyright © 2018年 叶小飞. All rights reserved.
//

#ifndef MacroDefinitionHeader_h
#define MacroDefinitionHeader_h

#define UTWeakSelf(weakSelf) __weak __typeof(&*self)  weakSelf  = self;
#define UTStrongSelf(strongSelf)  __strong __typeof(&*self)  strongSelf = weakSelf;

#pragma mark - 单例模式 .h文件内容
#define SingleInterface(name) +(instancetype)share##name;

#pragma mark - 单例模式 .m文件内容
#if __has_feature(objc_arc)
#define SingleImplementation(name) +(instancetype)share##name {return [[self alloc]init];} \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
static id instance; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
instance = [super allocWithZone:zone]; \
}); \
return instance; \
} \
- (id)copyWithZone:(NSZone *)zone{return self;} \
- (id)mutableCopyWithZone:(NSZone *)zone {return self;}

#else

#define SingleImplementation(name) +(instancetype)share##name {return [[self alloc]init];} \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
static id instance; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
instance = [super allocWithZone:zone]; \
}); \
return instance; \
} \
- (id)copyWithZone:(NSZone *)zone{return self;} \
- (id)mutableCopyWithZone:(NSZone *)zone {return self;} \
- (instancetype)retain {return self;} \
- (instancetype)autorelease {return self;} \
- (oneway void)release {} \
- (NSUInteger)retainCount {return MAXFLOAT;} \

#endif

#endif /* MacroDefinitionHeader_h */
