//
//  AppDelegate.m
//  demo
//
//  Created by rosehyird on 2020/6/3.
//  Copyright © 2020 rosehyird. All rights reserved.
//

#import "AppDelegate.h"
#import "loginSDK/platInit.h"
#import "loginSDK/platTools.h"
#import <loginSDK/platLogin.h>
#import <pushCenter/pushPlat.h>
#import "advertisingCenter/adPlatform.h"
#import <shareCenter/sharePlatform.h>
@interface AppDelegate ()<UNUserNotificationCenterDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [platInit initSDKapplication:application didFinishLaunchingWithOptions:launchOptions Applede:self];
    [pushPlat initPush:self gameId:@"1156"];
    [adPlatform setupPlatformGameID:@"1156"];

    [[sharePlatform getInit] registerShare];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
     [platInit   applicationDidEnterBackground:application];
   
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    
     [platInit  applicationWillEnterForeground:application];
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    [platInit applicationWillTerminate:application];
}
-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{
    
    [platInit application:app openURL:url options:options];
    
    [[sharePlatform getInit] shareApplication:app openURL:url options:options];
    return YES;
}

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler {
    return [[sharePlatform getInit] application:application continueUserActivity:userActivity];


}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [pushPlat  didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

#pragma mark - UNUserNotificationCenterDelegate

- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler __API_AVAILABLE(macos(10.14), ios(10.0), watchos(3.0), tvos(10.0)) {
    //此处设置声音，角标，警告。设置了即使app在前台也可以显示推送信息
    completionHandler(UNNotificationPresentationOptionBadge|UNNotificationPresentationOptionSound|UNNotificationPresentationOptionAlert);
}


- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler __API_AVAILABLE(macos(10.14), ios(10.0), watchos(3.0)) __API_UNAVAILABLE(tvos) {
    //可以解析相关信息，做相应页面跳转
    NSDictionary *dic = response.notification.request.content.userInfo;
    NSLog(@"推送信息%@", dic);
    [pushPlat receiveRemoteNotifications:dic];
    completionHandler();
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center openSettingsForNotification:(nullable UNNotification *)notification __API_AVAILABLE(macos(10.14), ios(12.0)) __API_UNAVAILABLE(watchos, tvos) {

}


@end
