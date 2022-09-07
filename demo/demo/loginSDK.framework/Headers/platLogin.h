//
//  platLogin.h
//  loginSDK
//
//  Created by xy on 2020/11/11.
//  Copyright © 2020 gumo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "loginCallBack.h"
#import "UserInfoModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface platLogin : NSObject
#pragma 登陆
/**
 必须接入的方法  登录
 
 @param mLoginCallBack 回调
 */
+ (void) login:(id<LoginCallBack>)mLoginCallBack;


#pragma 退出

/**
 注销账号
 */
+ (void) logout;


/**
 获取用户信息
 
 @return 用户信息
 */
+(UserInfoModel*)getUserInfo;

/**
 获取游戏用户的唯一ID
 
 @return uid
 */
+ (NSString*) getUid;


/**
 获取用户名
 
 @return Nickname
 */
+ (NSString*) getNickname;

/**
 获取Token
 
 @return Token
 */
+ (NSString*) getToken;

/**
 获取 accessToken
 
 */
+ ( void)accessToken:(void(^)( NSDictionary * info))success;

/**
 SDK切换账号方法
 */
+ (void)logSwitch;

/**
 判断是否已登录
 */
+ (bool)LoginStaus;



/**
 获取用户信息是否实名
 status 0 未实名 1实名 2查询失败
*/
+(void)checkRealName:(void(^)(int status))success;
+(void)realNameView;

/**
 唤起实名页面的
*/
+(void)bindSetInfo;


/**
 剩余时长
 @return 剩余时长 -1表示没有开启防沉迷
*/
+ (NSString *)remainingTime;

/**
 防沉迷信息
 @return 用户年龄 1、 未实名 2、8岁以下（不包含8岁） 3、8-16（包含8岁，不包含16岁） 4、16-18（包含16岁，不包含18岁）5、18岁以上（包含18）
*/
+ (NSString *)antiaddictionInfo;

//显示用户中心
+ (void)usercenter;

//删除账号
+ (void)deleteAccount;


//phonebing

+(void)checkPhoneNumber:(void(^)(int status))success;
+(void)phoneBindView;


/*
  手机绑定 实名认证 使用一个通知
 通知名：GameID
 返回参数：status  0 手机绑定失败
                 1 手机绑定成功
                 2 实名认证失败
                 3 实名认证成功
                 4 当前无新消息
                 5 当前有新消息
            
 */

@end

NS_ASSUME_NONNULL_END
