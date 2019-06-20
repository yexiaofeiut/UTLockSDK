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

//  CrcValue.h
//  UTGateway
//
//  Created by Macmini on 2018/8/22.
//  Copyright © 2018年 chenguichun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CrcValue : NSObject

- (instancetype)init:(int)BitCount Polynominal:(UInt32)Polynominal ShiftRight:(BOOL)ShiftRight Initial:(UInt32)Initial FinalMask:(UInt32)FinalMask;

- (void)reset;

- (void)update:(Byte[])buffer start:(int)start length:(int)length;

- (UInt32)getCrc32:(Byte[])buffer start:(int)start length:(int)length;
@end
