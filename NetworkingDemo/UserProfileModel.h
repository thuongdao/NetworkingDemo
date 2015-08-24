//
//  UserProfileModel.h
//  ChoVietMoi
//
//  Created by Nguyen Duc Thuan on 6/24/15.
//  Copyright (c) 2015 Nguyen Duc Thuan. All rights reserved.
//

#import "JSONModel.h"

@interface UserProfileModel : JSONModel

/*
 *  avatarImageURL = "";
 *  coverImageURL = "";
 *  createdDate = "2015-08-19T08:14:40.000Z";
 *  dateOfBirth = "0000-00-00";
 *  email = "ducthuan1990@gmail.com";
 *  fullName = thuan;
 *  gender = MALE;
 *  iShowEmail = 0;
 *  isActive = 1;
 *  isFacebookAccount = 0;
 *  isShowPhoneNumber = 0;
 *  maxShop = 5;
 *  modifiedDate = "2015-08-19T08:14:40.000Z";
 *  passWord = "******";
 *  phoneNumber = "";
 *  statusValue = BLOCK;
 *  userID = 11;
 *  userLevelID = 0;
 *  userStatusID = 1;
 */

@property (strong, nonatomic) NSString *avatarImageURL;
@property (strong, nonatomic) NSString *coverImageURL;
@property (strong, nonatomic) NSString *createdDate;
@property (strong, nonatomic) NSString *dateOfBirth;
@property (strong, nonatomic) NSString *email;
@property (strong, nonatomic) NSString *fullName;
@property (strong, nonatomic) NSString *gender;
@property BOOL iShowEmail;
@property BOOL isActive;
@property BOOL isFacebookAccount;
@property BOOL isShowPhoneNumber;
@property NSInteger maxShop;
@property (strong, nonatomic) NSString *modifiedDate;
@property (strong, nonatomic) NSString *phoneNumber;
//@property (strong, nonatomic) NSString *statusValue;
@property NSInteger userID;
@property NSInteger userLevelID;
@property NSInteger userStatusID;

- (BOOL)isBlock;
@end
