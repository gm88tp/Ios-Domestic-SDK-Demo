## 广告-接入说明文档

#### 适用范围

本文档适用于IOS 9.0及以上的操作系统。
SDK放在SDK文件夹内

#### 接入流程

### 准备

#### 1.导入SDK

```objectivec
将目录中的(根据给到SDK添加).framework  和(根据给到SDK添加).bundle导入到您的工程中。
```

#### 导入方法：在工程目录结构中，右键选择Add->Existing Files...，

```objectivec
选择(根据给到SDK添加).framework, (根据给到SDK添加).bundle（或将文件拖入Xcode工程目录结构中）文件，在弹出的界面中勾选Copy items into destination group's folder(if needed)，并确保Add To Targets勾选相应target。
```

**注：**

- 在General—— >>Frameworks,Libraries,and Embedded Content—— >>将添加的framework设置成Embed & Sign
- 在Build Settings——>> Other linker Flags 设置-ObjC

### 接入方法说明

#### AppDelegate导入头文件

 引入头文件  `

```objectivec
#import "advertisingCenter/adPlatform.h"
```

### 方法用途：

#### 初始化

用于应用启动后，初始化广告SDK。

###### 使用地方

在-(**BOOL**)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions方法中调用

###### 参数

此参数表适用于SDK v3.8.1及以上版本

| 参数名 | 类型     | 必需 | 示例 | 说明   |
| ------ | -------- | ---- | ---- | ------ |
| gameID | NSString | 是   | 2780 | 游戏id |

###### 方法

```objective-c
+ (void)setupPlatformGameID:(NSString *)gameID;
```

###### 示例

```objective-c
[adPlatform setupPlatformGameID:@"2780"];
```

**注：`+ (void)setupPlatformReyunKey:(NSString *)key gameID:(NSString *)gameID  GDTID:(NSString *)gdtID GDTKey:(NSString *)gdtkey;` 此方法在v3.8.3废弃**

## 

#### 激励视频

用于调用激励视频。

###### 使用地方

在需要调用激励视频的地方使用

###### 方法

```objectivec
+ (void)pullAdvertisingReward;
```

###### 示例

```objectivec
[adPlatform pullAdvertisingReward];
```

**注：`+(void)pulladvertisingCenterRequest;`此方法在v3.8.3废弃**



---

#### 获取设备标识

用户获取设备标识符

###### 方法

```objectivec
+ (NSString *)getUserSing;
```

###### 示例

```objectivec
[adPlatform getUserSing];
```

## 

#### 上传用户分数

用于上传用户信息，可以用于排行榜

###### 参数

| 参数名    | 类型     | 必需 | 示例   | 说明                              |
| :-------- | :------- | ---- | ------ | --------------------------------- |
| name      | NSString | 是   | @"***" | 百度广告的key，没有可以传空字符串 |
| userScore | NSString | 是   | @"100" | 分数                              |
| userSing  | NSString | 是   | @"***" | 设备标识符                        |

###### 方法

```objectivec
+(void)uploadRanklistUserName:(NSString *)name userScore:(NSString *)score userSing:(NSString *)usersing resultInfo:(void(^)(NSDictionary *info))result;
```

###### 示例

```objectivec
[adPlatform uploadRanklistUserName:@"xx" userScore:@"xx" userSing:@"xx" resultInfo:{
  //输出结果
}];
```

## 

#### 获取排行榜信息

用于获取排行榜信息

###### 参数

| 参数名   | 类型     | 必需 | 示例   | 说明       |
| :------- | :------- | ---- | ------ | ---------- |
| userSing | NSString | 是   | @"***" | 设备标识符 |

###### 方法

```objectivec
+ (void)getRanklistuserSing:(NSString * )usersing resultInfo:(void(^)(NSDictionary *info))result;
```

###### 示例

```objectivec
[adPlatform getRanklistuserSing:@"xx"  resultInfo:{
  //输出结果
}];
```

## 

