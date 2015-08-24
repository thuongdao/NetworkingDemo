//
//  APIClient.m
//  ChoVietMoi
//
//  Created by Nguyen Duc Thuan on 6/24/15.
//  Copyright (c) 2015 Nguyen Duc Thuan. All rights reserved.
//

#import "APIClient.h"
#import "Constants.h"
#define keyAccessToken @"accessToken"

@implementation APIClient
+ (instancetype)sharedClient
{
    static APIClient *_sharedClient = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        _sharedClient = [[APIClient alloc] initWithBaseURL:[NSURL URLWithString:kAPIMainDefault]];
        _sharedClient.securityPolicy = [AFSecurityPolicy policyWithPinningMode:AFSSLPinningModeNone];
    });
    
    return _sharedClient;
}

#pragma mark-
#pragma mark- REGISTER
//================ REGISTER methods =================
//===================================================
- (void)registerWithFullName:(NSString *)fullName email:(NSString *)email password:(NSString *)password done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc]init];
    
    [dict setValue:email forKey:@"email"];
    [dict setValue:password forKey:@"password"];
    [dict setValue:fullName forKey:@"fullname"];
    
    [self POST:kAPIRegister parameters:dict success:^(NSURLSessionDataTask *task, id responseObject) {
        if (doneBlock) {
            ResponseModel *responseModel = [[ResponseModel alloc]initWithDictionary:responseObject error:nil];
            
            if ([responseModel isSusscessfull]) {}
            
            doneBlock(responseModel);
        }
    } failure:^(NSURLSessionDataTask *task, NSError *error) {
        if (failseBlock) {
            failseBlock(task, error);
        }
    }];
}

#pragma mark-
#pragma mark- Login
//================ Login methods =================
//===================================================
- (void)loginWithFacebookToken:(NSString *)facebookTokenStr done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc]init];
    
    [dict setValue:[Session shareInstance].deviceToken forKey:@"deviceToken"];
    [dict setValue:facebookTokenStr forKey:@"fbAccessToken"];
    
    [self POST:kAPILoginWithFacebook parameters:dict success:^(NSURLSessionDataTask *task, id responseObject) {
        if (doneBlock) {
            ResponseModel *responseModel = [[ResponseModel alloc]initWithDictionary:responseObject error:nil];
            
            if ([responseModel isSusscessfull]) {}
            
            doneBlock(responseModel);
        }
    } failure:^(NSURLSessionDataTask *task, NSError *error) {
        if (failseBlock) {
            failseBlock(task, error);
        }
    }];
}

- (void)loginWithEmail:(NSString *)email password:(NSString *)password done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc]init];
    
    [dict setValue:email forKey:@"email"];
    [dict setValue:password forKey:@"password"];
    [dict setValue:[Session shareInstance].deviceToken forKey:@"deviceToken"];
    
    [self POST:kAPILoginWithEmail parameters:dict success:^(NSURLSessionDataTask *task, id responseObject) {
        if (doneBlock) {
            ResponseModel *responseModel = [[ResponseModel alloc]initWithDictionary:responseObject error:nil];
            
            if ([responseModel isSusscessfull]) {}
            
            doneBlock(responseModel);
        }
    } failure:^(NSURLSessionDataTask *task, NSError *error) {
        if (failseBlock) {
            failseBlock(task, error);
        }
    }];
}

- (void)getFacebookProfileDone:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock
{
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    NSString *urlStr = [NSString stringWithFormat:kFacebookProfile, [Session shareInstance].accessTokenStr];
    
    [manager GET:urlStr parameters:nil success:^(NSURLSessionDataTask *task, id responseObject) {
        if (doneBlock) {
            doneBlock(responseObject);
        }
    } failure:^(NSURLSessionDataTask *task, NSError *error) {
        if (failseBlock) {
            failseBlock(task, error);
        }
    }];
}

- (void)logOutDone:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc]init];
    
    [dict setValue:[Session shareInstance].accessTokenStr forKey:keyAccessToken];
    
    [self POST:kAPILogout parameters:dict success:^(NSURLSessionDataTask *task, id responseObject) {
        if (doneBlock) {
            ResponseModel *responseModel = [[ResponseModel alloc]initWithDictionary:responseObject error:nil];
            
            if ([responseModel isSusscessfull]) {
                [[Session shareInstance]resetSession];
            }
            
            doneBlock(responseModel);
        }
    } failure:^(NSURLSessionDataTask *task, NSError *error) {
        if (failseBlock) {
            failseBlock(task, error);
        }
    }];
}

- (void)changePass:(NSString *)oldPass newPass:(NSString *)newPass done:(APISusscessBlock)doneBlock failse:(APIFailseBlock)failseBlock
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc]init];
    
    [dict setValue:[Session shareInstance].accessTokenStr forKey:keyAccessToken];
    [dict setValue:oldPass forKey:@"oldPassword"];
    [dict setValue:newPass forKey:@"newPassword"];
    
    [self POST:kAPIChangePass parameters:dict success:^(NSURLSessionDataTask *task, id responseObject) {
        if (doneBlock) {
            ResponseModel *responseModel = [[ResponseModel alloc]initWithDictionary:responseObject error:nil];
            
            if (doneBlock) {
                doneBlock(responseModel);
            }
        }
    } failure:^(NSURLSessionDataTask *task, NSError *error) {
        if (failseBlock) {
            failseBlock(task, error);
        }
    }];
}

@end
