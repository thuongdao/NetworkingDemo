//
//  Session.m
//  ChoVietMoi
//
//  Created by Nguyen Duc Thuan on 6/24/15.
//  Copyright (c) 2015 Nguyen Duc Thuan. All rights reserved.
//

#import "Session.h"
#import "Macros.h"

@implementation Session
+ (instancetype)shareInstance
{
    static Session *sessionModel = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        sessionModel = [[Session alloc] init];
    });
    
    return sessionModel;
}

- (id)init
{
    self = [super init];
    
    if (self) {
        _arrProductStatus = @[@"Bày bán",
                              @"Chưa bày bán",
                              @"Hết hàng"];
        
        if ([_userProfile toDictionary] != nil) {
            NSDictionary *dictUser = [userDefault objectForKey:@"_userProfile"];
            _userProfile = [[UserProfileModel alloc]initWithDictionary:dictUser error:nil];
        }
        _deviceToken = @"_deviceToken";
        _accessTokenStr = [userDefault objectForKey:@"_accessTokenStr"];
        _isLogin = [userDefault boolForKey:@"_isLogin"];
        _email = [userDefault objectForKey:@"_email"];
        _passWord = @"";
    }
    return self;
}

- (void)resetSession
{
    _userProfile = nil;
    _accessTokenStr = @"";
    _isLogin = NO;
    _passWord = @"";
}

- (void)saveSesstion
{
    [userDefault setObject:[_userProfile toDictionary] forKey:@"_userProfile"];
    [userDefault setObject:_accessTokenStr forKey:@"_accessTokenStr"];
    [userDefault setBool:_isLogin forKey:@"_isLogin"];
    [userDefault setObject:_email forKey:@"_email"];
    [userDefault synchronize];
}

@end
