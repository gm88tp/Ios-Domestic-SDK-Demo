//
//  tenovPlat.h
//  tenovSDK
//
//  Created by tenov on 2018/3/21.
//  Copyright © 2018年 tenov. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "tenovOrderModel.h"
#import "tenovUserInfo.h"
#import "tenovLoginCallBack.h"
#import "tenovPayCallBack.h"
 
@interface tenovPlat : NSObject

/*!
 单例,预留接口
 
 @return tenovPlat
 */
+(tenovPlat*)getInstance;
/**
 SDK注册激活
 */

/**
 AppDelegate.h内的接口,主要用去支付.游戏从后台返回用
 
 @param application application
 */
+(void)applicationWillEnterForeground:(UIApplication *)application;



/**
 AppDelegate.h内的接口
 
 @param app application
 需要调用一些事件激活
 */
+ (void)applicationDidBecomeActive:(UIApplication *)app;
/**
 AppDelegate.h内的接口,进入后台
 
 @param application application
 */
+(void)applicationDidEnterBackground:(UIApplication *)application;

/*
 
 要针对所有广告系列（包括使用通用链接的广告系列）将应用内事件作为转化衡量，
 您必须将以下代码段添加到应用的 application:continueUserActivity:restorationHandler 方法。
 */
+ (BOOL)application:(UIApplication *)application  continueUserActivity:(NSUserActivity *)userActivity;

/**
 AppDelegate.
 
 @param app app
 @param url url
 @param options options
 @return BOOL
 */
+(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString *,id> *)options;

/**
 AppDelegate.h内的接口
 
 @param application application
 @param url url
 @param sourceApplication sourceApplication
 @param annotation annotation
 @return BOOL
 */
+(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

/**
 AppDelegate.h内的接口
 
 即将杀进程，用于统计热云在线时长，一定要接入
 */
+ (void)applicationWillTerminate:(UIApplication *)application;
 

/**
 必须最先接入的方法  平台初始化方法
 
 gameid 游戏的id
 promote 渠道
 
 */
+ (void) initSDK:(NSString*)gameid
      setPromote:(NSString*)promote
     application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 trackingKey:(NSString *)key
         Applede:(id) app
        Result :(void(^)(NSInteger tag))tag;


+ (void) initSDK:(NSString*)gameid
setPromote:(NSString*)promote
        trackKey:(NSString *)Key;
/**
 登录返回的传递数据
 退出返回的传递数据
 */
//+ (void)loginUserInfo:(void(^)(NSDictionary *))userInfo;
/**
 必须接入的方法  登录
 
 @param mLoginCallBack 回调
 */
+ (void) login:(id<tenovLoginCallBack>)mLoginCallBack;


/**
 支付发起与结果
 @param payInfo 支付信息
 @param callBack 支付回调
 */
+ (void) tenovpay:(tenovOrderModel *)payInfo CallBack:(id<tenovPayCallBack>) callBack;




/**
 注销账号
 */
+ (void) logout;


/**
 获取用户信息
 
 @return 用户信息
 */
+(tenovUserInfo*)getUserInfo;

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
 SDK切换账号方法
 */
+ (void)logSwitch;

/**
 判断是否已登录
 */
+ (bool)LoginStaus;

/**
 获取当前 SDK 的版本号
 
 @return SDK 版本号，用Jenkins 打包会自动加上时间戳
 */
+(NSString*)versions;





/**
 
 获取当前游戏用户注册或新手引导
 
 此接口即将废弃，请选择 setGameRoleName:gameLevel:serverID:roleID:statusType:
 */
+(void)tenovcreateTheRoleOrCompleteNewbieGuide:(selectStyle)selectStyle;






/**
 
 获取当前游戏的角色
 角色名字：name
 游戏等级：level
 区服:   serverID
 状态值默认选择<3>:status 1:创建角色 2:完成新手引导 3:等级升级
 */
+ (void)setGameRoleName:(NSString *)name  gameLevel:(NSString *)level serverID:(NSString *)serverID roleID:(NSString *)roleid statusType:(NSString *)status;


/**
 c创建角色页面 打点
 */
+ (void)createRole;
/**
 进入游戏主页面 打点
 */
+ (void)showGamePage;

/**
 选择屈服页面 打点
 关闭
 */
+ (void)selectArea;

/**
 获取语言包中的多语言
 */
+ (NSString *)setlaugulgString:(NSString *)str;

/**
 获取资源包中的配置参数
 */
+ (NSString*)getInfoString:(NSString*)str;

/**
 显示悬浮球
 */
+ (void) showToolBar ;
  
/**
 去除悬浮球
 */
+ (void) removeToolBar ;

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


/**
 此接口废弃
 */
+ (void)setCheckoutV:(int )status checkoutStr:(NSString * )str  detaileTitle:(NSString *)detaileTitle;

/**
 此接口废弃
 */
+ (void)removeCheckoutVU;

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
+ (void)agreement:(NSString * )info;

//查询和谐配置的
+ (void)SysSetting:(void(^)(NSDictionary *info))Success;

/**
 获取用户信息是否实名
 status 0 未实名 1实名 2查询失败
*/
+(void)checkRealName:(void(^)(int status))success;


/**
 唤起实名页面的
*/
+(void)bindSetInfo;


/**
 打点上报接口---SDK后台
 @param str 事件名称
*/
+(void)log:(NSString*)str;

/**
 打点上报接口---tracking
 @param param 事件参数
*/
+ (void)logTracking:(NSDictionary *)param;

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



@end


