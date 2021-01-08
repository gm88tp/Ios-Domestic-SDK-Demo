//
//  PurchaseCallBack.h
//  tenovSDK
//
//  Created by tenov on 2018/7/6.
//  Copyright © 2018年 tenov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "tenovStatus.h"
@protocol tenovPayCallBack <NSObject>
/**
 purchase回调接口
 
 @param code 状态值
 @param Data 数据
 */
-(void)onFinish:(tenovStatus)code Data:(NSDictionary *)Data;
@end
