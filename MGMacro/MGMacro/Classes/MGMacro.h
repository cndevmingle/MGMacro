//
//  MGMacro.h
//  MGMacro
//
//  Created by Mingle on 2018/4/9.
//  Copyright © 2018年 Mingle. All rights reserved.
//

#ifndef MGMacro_h
#define MGMacro_h

// 一些缩写
#define MGApplication        [UIApplication sharedApplication]
#define MGKeyWindow          [UIApplication sharedApplication].keyWindow
#define MGAppDelegate        [UIApplication sharedApplication].delegate
#define MGUserDefaults       [NSUserDefaults standardUserDefaults]
#define MGNotificationCenter [NSNotificationCenter defaultCenter]

// 颜色
#define MGRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
#define MGRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define MGRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define MGColorWithAHex(rgbValue, a) \
    [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
                    green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \
                     blue:((float)(rgbValue & 0xFF)) / 255.0 \
                    alpha:a]
#define MGColorWithHex(rgbValue)  \
    [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
                    green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \
                     blue:((float)(rgbValue & 0xFF)) / 255.0 \
                    alpha:1.0]
#define MGClearColor [UIColor clearColor]

// 日志打印
#ifdef DEBUG
#define MGLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define MGLog(...)
#endif

// 弱/强引用
#define MGWeakSelf __weak typeof(self) weakSelf = self;
#define MGWeakObj(type)  __weak typeof(type) weak##type = type;
#define MGStrongObj(type)  __strong typeof(type) type = weak##type;

// 设置 view 圆角和边框
#define MGViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// 由角度转换弧度 由弧度转换角度
#define MGDegreesToRadian(x) (M_PI * (x) / 180.0)
#define MGRadianToDegrees(radian) (radian*180.0)/(M_PI)

// 获取图片资源
#define MGGetImageWithNamed(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

//APP版本号
#define MGAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
//系统版本号
#define MGSystemVersion [[UIDevice currentDevice] systemVersion]
//获取当前语言
#define MGCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])
//判断是否为iPhone
#define MGISiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad
#define MGISiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


//判断是否为ipod
#define MGISiPod ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

// 判断是否为 iPhone 4S
#define MGISiPhone4S [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 480.0f

// 判断是否为 iPhone 5SE
#define MGISiPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

// 判断是否为iPhone 6/6s
#define MGISiPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

// 判断是否为iPhone 6Plus/6sPlus
#define MGISiPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

// 判断是否是iPhoneX
#define MGISiPhoneX [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 812.0f

//获取temp
#define MGPathTemp NSTemporaryDirectory()

//获取沙盒 Document
#define MGPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒 Cache
#define MGPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

// 字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )

//获取一段时间间隔
#define MGStartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define MGEndTime   NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

// 屏幕
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上
#define MGSCREEN_WIDTH ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define MGSCREEN_HEIGHT ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define MGSCREEN_SIZE ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define MGSCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define MGSCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define MGSCREEN_SIZE [UIScreen mainScreen].bounds.size
#endif
#define MGSTATUSBAR_HEIGHT [[UIApplication sharedApplication] statusBarFrame].size.height
#define MGNAVIGATIONBAR_HEIGHT 44
#define MGNAV_ADD_STATUS_HEIGHT (MGISiPhoneX ? 88 : (MGSTATUSBAR_HEIGHT + MGNAVIGATIONBAR_HEIGHT))
#define MGTABBAR_HEIGHT 49
#define MGIPHONEXBOTTOM_HEIGHT 34

#endif /* MGMacro_h */
