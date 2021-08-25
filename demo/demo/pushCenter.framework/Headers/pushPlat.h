//
//  pushPlat.h
//  pushCenter
//
//  Created by cm on 2021/8/23.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
NS_ASSUME_NONNULL_BEGIN
static NSString * const PUSH_SDK_VERSION     = @"3.9.2";

@interface pushPlat : NSObject <UNUserNotificationCenterDelegate>
//初始化sdk
+ (void)initPush:(id)delegate gameId:(NSString *)gameId;

//请求授权 callback 回调：1允许；2不允许
+ (void)requestAuthorizationForRemoteNotifications:(void(^)(NSInteger result))callback;

//获取设备token
+ (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

//向SDK服务端上报，请在登陆之后将用户识别调用 userInfo：登陆sdk登陆后的token
+ (void)upDeviceTokenWithUser:(NSString *)userInfo;

//上报通知
+ (void)receiveRemoteNotifications:(NSDictionary *)dic;

//清除红点
+ (void)applicationIconBadgeClear;

@end

NS_ASSUME_NONNULL_END
