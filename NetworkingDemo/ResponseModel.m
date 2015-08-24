//
//  ResponseModel.m
//  iNhanh
//
//  Created by SETA International Developer on 2/2/15.
//  Copyright (c) 2015 SETA International. All rights reserved.
//

#import "ResponseModel.h"

@implementation ResponseModel
- (BOOL)isSusscessfull
{
    if (_statusErrorCode == 0) {
        return YES;
    }
    return NO;
}

- (BOOL)isAccessTokenFailse
{
    if (_statusErrorCode == 5) {
        return YES;
    }
    return NO;
}

/*
 *  results: {object result},
 *  statusErrorCode: 0
 *
 *  errorsMessage: "Connection to Database is failure!",
 *  statusErrorCode: 100
 *
 *  errorsMessage: "Query with table is failure!",
 *  statusErrorCode: 1
 *
 *  errorsMessage: "Email was Existed, please input other email!",
 *  statusErrorCode: 2
 *
 *  errorsMessage: "Username was Existed, please input other username!",
 *  statusErrorCode: 3
 *
 *  errorsMessage: "Username is not exist or password is incorrect.Please re-enter!",
 *  statusErrorCode: 4
 *
 *  errorsMessage: "Access token error!",
 *  statusErrorCode: 5
 *
 *  errorsMessage: "Old password is incorrect!",
 *  statusErrorCode: 6
 */
@end
