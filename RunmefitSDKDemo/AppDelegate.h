//
//  AppDelegate.h
//  RunmefitSDKDemo
//
//  Created by 星迈 on 2023/2/2.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

+ (AppDelegate *)shareInstance;

//MARK: 提示
- (void)alertShowTitle:(NSString *)title message:(NSString *)message;

@end

