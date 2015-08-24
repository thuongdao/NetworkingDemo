//
//  APIClient.h
//  ChoVietMoi
//
//  Created by Nguyen Duc Thuan on 6/24/15.
//  Copyright (c) 2015 Nguyen Duc Thuan. All rights reserved.
//

#import "AFHTTPSessionManager.h"
#import "ResponseModel.h"
#import "Session.h"

typedef void (^ APISusscessBlock)(ResponseModel *responseModel);
typedef void (^ APIFailseBlock)(NSURLSessionDataTask *task, NSError *error);

@interface APIClient : AFHTTPSessionManager
+ (instancetype)sharedClient;

//=========== Login methods =================
- (void)registerWithFullName:(NSString *)fullName email:(NSString *)email password:(NSString *)password done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock;
- (void)loginWithFacebookToken:(NSString *)facebookTokenStr done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock;
- (void)loginWithEmail:(NSString *)email password:(NSString *)password done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock;
- (void)getFacebookProfileDone:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock;
- (void)logOutDone:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock;
- (void)changePass:(NSString *)oldPass newPass:(NSString *)newPass done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock;
@end
