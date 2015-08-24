//
//  TemplateModel.h
//  ChoVietMoi
//
//  Created by Nguyen Duc Thuan on 6/29/15.
//  Copyright (c) 2015 Nguyen Duc Thuan. All rights reserved.
//

#import "JSONModel.h"

@interface TemplateModel : JSONModel

@property (strong, nonatomic) NSString* name;
@property (strong, nonatomic) NSArray* arrProperty;

- (id)initWithDefaultData;
- (void)setDefaultData;
@end
