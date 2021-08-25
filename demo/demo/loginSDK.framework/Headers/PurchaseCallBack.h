//
//  PurchaseCallBack.h
//  tenovSDK
//
//  Created by tenov on 2018/7/6.
//  Copyright © 2018年 tenov. All rights reserved.
//

#import <Foundation/Foundation.h>
 

typedef NS_ENUM(NSInteger,purchaseStatus){
    /** 支付成功 */
    PURCHASE_SUCCESS = 10,
    /** 支付失败*/
    PURCHASE_FAILED = 11,
    /** 支付取消 */
    PURCHASE_CANCEL = 12,
    /** 未知支付状态*/
    PURCHASE_UNKNOWN = 13
};

/**
 返回代理，需在调用前实例化
 */
@protocol PurchaseCallBack <NSObject>

@required
/**
 接口
 @param code 状态值

 @param Data 数据
 */
-(void)purchaseOnFinish:(purchaseStatus)code   Data:(NSDictionary*)Data;
@end
