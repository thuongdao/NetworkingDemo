//
//  Macros.h
//  iNhanh
//
//  Created by SETA International Developer on 1/27/15.
//  Copyright (c) 2015 SETA International. All rights reserved.
//
#import "AppDelegate.h"
#ifndef iNhanh_Macros_h
#define iNhanh_Macros_h

#define iOS8AndLater SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")

#define appDelegateAccessor ((AppDelegate*)[[UIApplication sharedApplication] delegate])

#pragma mark - COLOR

/** UIColor: Color From Hex **/
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed : ((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 green : ((float)((rgbValue & 0xFF00) >> 8)) / 255.0 blue : ((float)(rgbValue & 0xFF)) / 255.0 alpha : 1.0]

#define COLOR_FROM_HEX(rgbValue) (UIColorFromRGB(rgbValue))

/** UIColor: Color from RGB **/

#define RGB(r, g, b)[UIColor colorWithRed : r / 255.0 green : g / 255.0 blue : b / 255.0 alpha : 1]

/** UIColor: Color from RGBA **/

#define COLOR_FROM_RGBA(r, g, b, a) ([UIColor colorWithRed:r / 255.0 green:g / 255.0 blue:b / 255.0 alpha:a])

#define RGBA(r, g, b, a)[UIColor colorWithRed : r / 255.0 green : g / 255.0 blue : b / 255.0 alpha : a]

#pragma mark - DLOG

#ifdef DEBUG
# define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ## __VA_ARGS__);
#else
# define DLog(...)
#endif
#define ALog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ## __VA_ARGS__);
#ifdef DEBUG
# define ULog(fmt, ...){ UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ## __VA_ARGS__] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil]; [alert show]; }
#else
# define ULog(...)
#endif

#define userDefault [NSUserDefaults standardUserDefaults]
#define iOSVersion [[UIDevice currentDevice].systemVersion floatValue]

#define IS_IPHONE_5 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)568) < DBL_EPSILON)
#define IS_IPHONE_6 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)667) < DBL_EPSILON)
#define IS_IPHONE_6_PLUS (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)960) < DBL_EPSILON)
#define IS_IPHONE_6_PLUS_STANDARD (fabs((double) [UIScreen mainScreen].scale - (double)2.1) > DBL_EPSILON)

#define SHOW_TOAST(message) [MBProgressHUD showMessageAlert:message inView:AppDelegateAccessor.window.rootViewController.view]
#define SHOW_PROGRESS [MBProgressHUD showHUDAddedTo:self.tabBarController.view animated:YES];
#define HIDE_PROGRESS [MBProgressHUD hideAllHUDsForView:self.tabBarController.view animated:YES];

#endif
