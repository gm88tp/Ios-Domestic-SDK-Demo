//
//  ViewController.m
//  demo
//
//  Created by rosehyird on 2020/6/3.
//  Copyright © 2020 rosehyird. All rights reserved.
//

#import "ViewController.h"
#import "loginSDK.h"
#import <shareGroup/shareContentItem.h>
#import <shareGroup/sharePlatform.h>
#import "advertisingCenter/adPlatform.h"

#define notificationName  @"adnotification"
@interface ViewController ()<tenovPayCallBack,tenovLoginCallBack,UITableViewDelegate,UITableViewDataSource>
@property (nonatomic,strong)UITableView  * tab;
@property (nonatomic,strong)NSArray      * arr;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.tab = [[UITableView alloc]initWithFrame:self.view.frame style:UITableViewStylePlain];
    [self.view addSubview:self.tab];
    self.tab.delegate = self;
    self.tab.dataSource = self;
    self.arr = @[@"登录",@"支付",@"退出",@"角色打点", @"通用打点方法",@"qq",@"空间",@"微博",@"微信好友",@"微信朋友圈",@"微信喜欢",@"广告",@"剩余时长",@"用户年龄"
    ];
    [[NSNotificationCenter defaultCenter] addObserver:self  selector:@selector(notificationFunc:) name:notificationName   object:nil];
}

#pragma mark - uitableview
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return  self.arr.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
     static   NSString * str  = @"wqewqeq";
        UITableViewCell * cell= [tableView  dequeueReusableCellWithIdentifier:str];
      if(!cell){
          cell  = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:str];
          
      }
      cell.textLabel.text = self.arr[indexPath.row];
      return cell;
}
 

 - (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView   deselectRowAtIndexPath:indexPath animated:YES];
     shareContentItem * item = [self setShareContent];
     if(indexPath.row==0){
         [self userLogin];
     }else if(indexPath.row==1){
         [self userBuy];
     }
     else if(indexPath.row==2){
         [self userExit];
         
     }
     else if(indexPath.row==3){
     
         [loginSDK setGameRoleName:@"名字" gameLevel:@"等级" serverID:@"区服ID" roleID:@"游戏角色ID" statusType:@"类型"];
     }
     else if(indexPath.row==4){
         [loginSDK LogInfo:@"ads_CXJ_request_failure" EventDic:@{}];
         
     }  else if(indexPath.row==5){
         [sharePlatform shareWithContent:item  shareType:ShareTypeQQ shareResult:^(NSInteger shareResult) {
             if(shareResult ==statusCodeSuccess){
                                      NSLog(@"分享成功");
                                  }else if (shareResult ==statusCodeCancel){
                                      NSLog(@"分享失败");
                                  }
         }];
         
             
     }  else if(indexPath.row==6){
         [sharePlatform shareWithContent:item  shareType:ShareTypeQQZone shareResult:^(NSInteger shareResult) {
             if(shareResult ==statusCodeSuccess){
                                      NSLog(@"分享成功");
                                  }else if (shareResult ==statusCodeCancel){
                                      NSLog(@"分享失败");
                                  }
         }];
                 
     }  else if(indexPath.row==7){
         [sharePlatform shareWithContent:item  shareType:ShareTypeWeiBo shareResult:^(NSInteger shareResult) {
             if(shareResult ==statusCodeSuccess){
                 NSLog(@"分享成功");
             }else if (shareResult ==statusCodeCancel){
                 NSLog(@"分享失败");
             }
         }];
                     
     }  else if(indexPath.row==8){
         
         [sharePlatform shareWithContent:item  shareType:ShareTypeWSession shareResult:^(NSInteger shareResult) {
             if(shareResult ==statusCodeSuccess){
                                      NSLog(@"分享成功");
                                  }else if (shareResult ==statusCodeCancel){
                                      NSLog(@"分享失败");
                                  }
         }];
         
     }
     else if(indexPath.row==9){
         [sharePlatform shareWithContent:item  shareType:ShareTypeWTimeline shareResult:^(NSInteger shareResult) {
             if(shareResult ==statusCodeSuccess){
                                      NSLog(@"分享成功");
                                  }else if (shareResult ==statusCodeCancel){
                                      NSLog(@"分享失败");
                                  }
         }];
         
     }
     else if(indexPath.row==10){
         [sharePlatform shareWithContent:item  shareType:ShareTypeWFavorite shareResult:^(NSInteger shareResult) {
             if(shareResult ==statusCodeSuccess){
                                      NSLog(@"分享成功");
                                  }else if (shareResult ==statusCodeCancel){
                                      NSLog(@"分享失败");
                                  }
         }];
     }else if(indexPath.row ==11){
         //广告
         [adPlatform pullAdvertisingReward];
     } else if (indexPath.row == 12) {
         NSString *str = [loginSDK remainingTime];
          //-1表示没有开启防沉迷
          [self setPromot:[NSString stringWithFormat:@"说明：-1表示未开启防沉迷，其他数值表示剩余时长。返回结果：%@",str]];
          
          
      } else if (indexPath.row == 13) {
          NSString *str = [loginSDK antiaddictionInfo];
          [self setPromot:[NSString stringWithFormat:@"说明：用户年龄 1、 未实名 2、8岁以下（不包含8岁） 3、8-16（包含8岁，不包含16岁） 4、16-18（包含16岁，不包含18岁）5、18岁以上（包含18）。返回结果：%@",str]];
      }
 }

- (void)setPromot:(NSString *)strPro{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示" message:strPro preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"确认" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [alert addAction:cancel];
    [self presentViewController:alert animated:YES completion:nil];
}

- (shareContentItem *)setShareContent {
    shareContentItem * item = [[shareContentItem alloc]init];
    item.share_title = @"分享测试";
    item.share_targeturl = @"https://www.baidu.com";
    item.share_imgurl =@"123";//https://dl03.gm88.com/xmjlogo/fxxz.png";
    item.share_msg = @"一般情况新浪微博的Summary和微信,QQ的是不同的,新浪微博的是一般带链接的,而且总共字数不能超过140字";
    return item;
}

#pragma mark - 方法
//登录
- (void)userLogin  {
    
    [loginSDK login:self];
 
}

//登出
- (void)userExit  {
    [loginSDK logout];
}

//支付
- (void)userBuy  {
    UIAlertController *buy = [UIAlertController alertControllerWithTitle:@"支付" message:@"请输入相关商品信息" preferredStyle:UIAlertControllerStyleAlert];
    __block UITextField *goodId,*price,*name;
    [buy addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"请输入商品id";
        goodId = textField;
    }];
    [buy addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"请输入价格";
        price = textField;
    }];
    [buy addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"请输入商品名称";
        name = textField;
    }];
    
    
    
    UIAlertAction *sure = [UIAlertAction actionWithTitle:@"支付" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //新手引导
        [self  pay:goodId.text withPrice:price.text withName:name.text];
    }];

    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [buy addAction:sure];
    [buy addAction:cancel];
    [self presentViewController:buy animated:YES completion:nil];
    
}

- (void)pay:(NSString *)goodid withPrice:(NSString *)price withName:(NSString *)name {
    tenovOrderModel* mPayInfo = [[tenovOrderModel alloc] init];
    /** 商品id *///1101
    mPayInfo.productID = goodid;
    /** Y 商品名 */
    mPayInfo.productName = name;
    /** Y 商品价格 */
    mPayInfo.productPrice = price;
    /** 商品描述（不传则使用productName） */
    mPayInfo.productDes=@"商品描述";
    /** Y 商品订单号 透传数据*/
    int y =100 +  (arc4random() % 100000000);
    mPayInfo.gameReceipts=[NSString stringWithFormat:@"%d",y];//[[collestTools dicTransformStr:@{@"gameAttach":@{@"activityId":@"54658",@"levelId":@"0"},@"orderId":@"15w w669wqwqq63697791115988"}] stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    /** Y 游戏角色id */
    mPayInfo.roleID=@"554";
    /** Y 游戏角色名 */
    mPayInfo.roleName=@"这是角色名字";
    /** Role_Name */
    mPayInfo.roleLevel=@"10";
    /** Y Vip等级 */
    mPayInfo.vipLevel=@"10";
    /** Y 帮派、公会等 */
    mPayInfo.partyName=@"这是工会";
    /** Y 服务器id，若无填“1” */
    mPayInfo.zoneID=@"1";
    /** Y 服务器名 */
    mPayInfo.zoneName=@"这是服务器";
    /** N 扩展字段 */
    mPayInfo.text=@"这是扩展字段";
    /**
     回调地址 可传可不传，不传使用默认
     */
    //mPayInfo.tenovnotifyURL = @"http://demo.gm88.com/ok.php?gameid=1156&promote=2";
    [tenovPlat tenovpay:mPayInfo CallBack:self];

}


#pragma mark -通知回调
- (void)notificationFunc:(NSNotification*)notification{
    NSDictionary * shearInfo = (NSDictionary *)notification.object;
    if([[shearInfo objectForKey:@"type"] isEqualToString:@"1"]){
        //成功
        NSLog(@"=========成功========");
        
          NSLog(@"shearInfo==%@",shearInfo);
    }else{
        //失败
        NSLog(@"shearInfo==%@",shearInfo);
        NSLog(@"=========失败========");
      
    }
}


#pragma mark -wfnjiLoginCallBack,wfnjiPayCallBack
-(void)onFinish:(tenovStatus)code Data:(NSDictionary *)Data {
    NSLog(@"%ld",code);
    NSLog(@"用户信息info==%@\n"   , Data);
    if(code== LOGIN_SUCCESS){
       NSLog(@"登录成功");
    }else if(code== LOGOUT_SUCCESS){
      //需要自己调用登录方法
        [self userLogin];
         NSLog(@"退出成功");
    }else if  (code == LOGIN_SWITCH){
         NSLog(@"切换账号");
    }else if(code==PAY_SUCCESS){
        NSLog(@"支付成功");
    }else if (code ==PAY_FAILED){
        
        NSLog(@"支付失败");
    }else if (code==PAY_CANCEL){
        
        NSLog(@"支付取消");
    }else if (code==PAY_UNKNOWN){
        NSLog(@"未知错误");
    }
}

@end
