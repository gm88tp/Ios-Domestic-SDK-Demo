//
//  LoginCallBack.h  
//  tenovSDK
//
//  Created by tenov on 2018/6/11.
//  Copyright © 2018年 tenov. All rights reserved.
//

#import <Foundation/Foundation.h>
 

typedef NS_ENUM(NSInteger,loginStatus) {
    /** 登陆成功 */
    LOGIN_SUCCESS = 0,
   
    /** 切换账号*/
    LOGIN_SWITCH = 4,
    /** 退出成功*/
    LOGOUT_SUCCESS = 5,
    /** 账号被封*/
    LOGIN_UNUSE = 6,
    /**  绑定成功 **/
    BIND_SUCCESS,
    
};
/**
 登录回调代理
 */
@protocol LoginCallBack <NSObject>

@required

/**
 登录回调接口

 @param code 状态值
 
 @param Data 数据
 */
-(void)loginOnFinish:(loginStatus)code   Data:(NSDictionary*)Data;
@end
