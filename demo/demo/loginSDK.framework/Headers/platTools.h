//
//  platTools.h
//  loginSDK
//
//  Created by xy on 2020/11/11.
//  Copyright © 2020 gumo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
//#if __has_include("shareCenter/sharePlatform.h")
//#import <shareCenter/sharePlatform.h>
//#endif
 
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger , agreementStatusCode) {
    agreementStatusCodeAgree=0,
    agreementStatusCodeUNAgree=1
};
@interface platTools : NSObject
/**
 获取当前 SDK 的版本号
 
  */
+(NSString*)versions;
/**
 
 获取当前游戏的角色
 @param name 角色名字
 @param level 游戏等级
 @param serverID 区服
 @param status 状态值默认选择<3>: 1:创建角色 2:完成新手引导 3:等级升级
 @param vipLevel 游戏VIP等级
 @param zone 大区id
 */
 

+ (void)platRoleName:(NSString *)name
            gameLevel:(NSString *)level
             serverID:(NSString *)serverID
               roleID:(NSString *)roleID
               status:(NSString *)status
            vipLevel:(NSString *)vipLevel
                zone:(NSString *)zone;

 

/**
 获取资源包中的配置参数
 */
+ (NSString*)getInfoString:(NSString*)str;
 

/**
 显示loading页面
 @param image loading背景图片
 @param color 设置loading颜色
 @param style 设置loading动画效果
 @param rec   设置loading背景图大小
 */
+ (void)setLoadingImg:(UIImage *)image Color:(UIColor *)color loadingStyle:(NSInteger )style imgRect:(CGRect)rec;

/**
 移除loading动画
 */
+ (void)removeLoadingImg;

 
+ (void)evaluate;
 

/**
 打点接口 ----Tracking
 @param eventName 事件名称
 @param info      事件参数，没有可以传空
*/
+ (void)LogInfo:(NSString *)eventName EventDic:(NSDictionary *)info;



/**
 返回渠道号
*/
+ (NSString *)returnChannelID;

/**
 返回设备号
*/
+ (NSString *) returnIDFV ;

/**
 返回idfa
*/
+ (NSString *) returnIDFA ;

/**
 唤起页面
 @param info 链接地址
*/
+ (void)showInfo:(NSString * )info;

/**
 唤起协议页面
 @param  链接地址
*/
+ (void)agreementWithResult:(void(^)(agreementStatusCode code))result;

//查询和谐配置的
 



 
 

 

//客服
+ (void)custom;

//NSDictionary类型转json格式方法
+ (NSString *)jsonStringWithDictionary:(NSDictionary *)dic;

//json格式转成字典类型方法
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;



+ (void)showWith:(NSString *)str;
@end

NS_ASSUME_NONNULL_END
