//
//  tenovPlat.h
//  tenovSDK
// 
//  Created by tenov on 2018/3/21.
//  Copyright © 2018年 tenov. All rights reserved.
//

#import <Foundation/Foundation.h>

 
 
@interface platInit : NSObject


/*!
 单例,预留接口
 
 @return tenovPlat
 */
+(platInit*)getInstance;
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
 


+ (void) initSDKapplication:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions Applede:(id) app;






+ (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;





@end


