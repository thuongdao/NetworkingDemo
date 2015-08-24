//
//  Session.h
//  ChoVietMoi
//
//  Created by Nguyen Duc Thuan on 6/24/15.
//  Copyright (c) 2015 Nguyen Duc Thuan. All rights reserved.
//

#import "JSONModel.h"
#import "UserProfileModel.h"

@interface Session : JSONModel

+ (instancetype)shareInstance;

@property (strong, nonatomic) NSString *deviceToken;
@property (strong, nonatomic) NSString *accessTokenStr;
@property (strong, nonatomic) UserProfileModel *userProfile;
@property BOOL isLogin;
@property (readonly) NSArray *arrProductStatus;
@property (strong, nonatomic) NSString *email;
@property (strong, nonatomic) NSString *passWord;

- (void)resetSession;
- (void)saveSesstion;
@end
