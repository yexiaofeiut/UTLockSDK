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
//  NSString+GNString.h
//  UTGateway
//
//  Created by Macmini on 2018/8/20.
//  Copyright © 2018年 chenguichun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TextFiledType) {
    TF_PHONENUMBER_,
    TF_PASSWORD_,
    TF_MESSAGECODE_,
};

@interface NSString (GNString)

/*
 *检查输入到字符串是否正确
 *
 */
- (NSString *)formatOfTextFieldString:(TextFiledType)type;

/*
 *打印16进制字符串
 *
 */
+ (void)toHexSting:(NSData *)data;
@end
