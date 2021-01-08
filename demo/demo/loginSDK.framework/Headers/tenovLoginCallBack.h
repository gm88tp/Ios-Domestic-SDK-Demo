//
//  LoginCallBack.h  
//  tenovSDK
//
//  Created by tenov on 2018/6/11.
//  Copyright © 2018年 tenov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "tenovStatus.h"
@protocol tenovLoginCallBack <NSObject>

/**
 登录回调接口
 
 @param code 状态值
 @param Data 数据
 */
-(void)onFinish:(tenovStatus)code Data:(NSDictionary *)Data;
@end
