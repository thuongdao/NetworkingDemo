//
//  ResponseModel.h
//  iNhanh
//
//  Created by SETA International Developer on 2/2/15.
//  Copyright (c) 2015 SETA International. All rights reserved.
//

#import "JSONModel.h"

@interface ResponseModel : JSONModel
@property NSInteger statusErrorCode;
@property (strong, nonatomic) NSString* errorsMessage;
@property (strong, nonatomic) NSDictionary* results;
@property (strong, nonatomic) NSDictionary* errorsObject;

- (BOOL)isSusscessfull;
- (BOOL)isAccessTokenFailse;
@end
