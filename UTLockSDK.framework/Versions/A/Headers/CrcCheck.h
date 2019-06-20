//
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| : |||// \
//                     / _||||| -:- |||||- \
//                       | | \\\ - /// | |
//                     | \_| ''\---/'' | |
//                      \ .-\__ `-` ___/-. /
//                   ___`. .' /--.--\ `. . __
//                ."" '< `.___\_<|>_/___.' >'"".
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  佛祖保佑             永无BUG
//

//  CrcCheck.h
//  UTGateway
//
//  Created by Macmini on 2018/8/22.
//  Copyright © 2018年 chenguichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CrcCheckBase <NSObject>

///<>
//对数据checkdata进行校验，数据符合校验计算，则返回true，否则返回false
///<param><name="checkData">被校验到一个完整的帧</param>
///</summary>
- (BOOL)check:(NSData *)checkData;

///<summary>
//计算数据的校验码，将检验码保存到目标数据checkData中，获取成功则返回true
///<param><name="checkData">呗校验到数据帧</param>
///</summary>
- (BOOL)getCheckCode:(NSData *)checkData;

@end

@interface CrcCheck : NSObject <CrcCheckBase>

- (instancetype)init:(int)bitCount :(UInt32)polynominal :(BOOL)shitRight :(UInt32)initial :(UInt32)finalMask :(int)startCheck;
@end
