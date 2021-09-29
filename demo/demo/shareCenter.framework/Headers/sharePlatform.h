//
//  sharePlatform.h
//  shareGroup
//
//  Created by xyting on 2020/3/17.
//  Copyright © 2020 com.group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "shareContentItem.h"
NS_ASSUME_NONNULL_BEGIN
typedef void(^ShareResultlBlock)(NSInteger shareResult);

typedef  NS_ENUM(NSInteger,  channelType){
    channelTypeChatq = 0,
    channelTypeChatw ,
    channelTypeWB
};

typedef NS_ENUM(NSInteger, shareType){
    
       ShareTypeWeiBo = 0,   // 新浪微博
       ShareTypeQQ,          // QQ好友
       ShareTypeQQZone,      // QQ空间
       ShareTypeWTimeline,   // 朋友圈
       ShareTypeWSession,    // 微信朋友
       ShareTypeWFavorite,   // 微信收藏
       ShareTypeDY,   // 微信收藏
};

typedef NS_ENUM(NSInteger , statusCode) {
    statusCodeSuccess=0,
    statusCodeCancel=-2
};

@interface sharePlatform : NSObject

+(sharePlatform *)getInit;
/*用户行为*/
- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity;
/*跳转*/
- (BOOL)shareApplication:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/*初始化（推荐使用）*/
- (void)registerShare;

/*
 初始化
 @param wappid    微信appid
 @param wchatlink 微信通用链接
 @param appkey  微博appkey
 @param wblink    微博通用链接
 @param tenchentId qq appid
 @param qlink      qq 通用链接
 */
- (void)registerAppwchat:(NSString *)wappid universalLinkAppwchat:(NSString *)wchatlink wbAppkey:(NSString *)appkey universalLinkWb:(NSString *)wblink tenchentId :(NSString *)qAppid universalLinkqwchat:(NSString *)qlink;


/*
 指定渠道分享
 @param contentObj  分享内容对象
 @param shareType   分享类型
 shareResult        分享结果回调
 
 此方法不支持抖音分享，如需抖音分享，请使用多渠道分享方法
 */
+ (void)shareWithContent:(shareContentItem *)contentObj
               shareType:(shareType)shareType
             shareResult:(ShareResultlBlock)shareResult;

/*
 多渠道分享
 @param contentObj  分享内容对象
 shareResult        分享结果回调
 */
+ (void)shareWithContent:(shareContentItem *)contentObj
             shareResult:(ShareResultlBlock)shareResult;


@end

NS_ASSUME_NONNULL_END
