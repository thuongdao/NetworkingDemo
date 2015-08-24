//
//  Constants.h
//  iNhanh
//
//  Created by SETA International Developer on 1/27/15.
//  Copyright (c) 2015 SETA International. All rights reserved.
//

#ifndef iNhanh_Constants_h
#define iNhanh_Constants_h

#define dateFormatDefaultStyle		@"dd/MM/yyyy"

#define kAPIMainDefault				@"http://104.236.31.239:5005/api/"
#define kAPIRegister				@"user/register-email"
#define kAPILoginWithEmail			@"user/login-email"
#define kAPILoginWithFacebook		@"user/login-fb"
#define kAPILogout					@"user/logout"
#define kAPIChangePass				@"user/changePassword"

#define kFacebookAvatarURLformat	@"https://graph.facebook.com/%@/picture?type=small" //graph.facebook.com/%@/picture?type=large
#define kFacebookProfile			@"https://graph.facebook.com/me?access_token=%@"
//=========== COLOR ===========
#pragma mark-
#pragma mark- COLOR
#define kNavigationBackgroundColor	RGB(28, 145, 149)        //RGB(25, 192, 194)
#define kNavigationBarTintColor		RGB(255, 255, 255)
#define kNavigationBarTitleFont		[UIFont fontWithName:@"HelveticaNeue-Light" size:22.0f]
#define kBarButtonTitleFont			[UIFont fontWithName:@"HelveticaNeue-Light" size:20.0f]

#define kColorPink					RGB(253.0, 105.0, 166.0)

//=========== API ===========
#pragma mark-
#pragma mark- API

#endif /* ifndef iNhanh_Constants_h */
