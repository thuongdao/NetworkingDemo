//
//  TemplateModel.m
//  ChoVietMoi
//
//  Created by Nguyen Duc Thuan on 6/29/15.
//  Copyright (c) 2015 Nguyen Duc Thuan. All rights reserved.
//

#import "TemplateModel.h"

@implementation TemplateModel
- (id)initWithDefaultData{
    self = [super init];
    if(self){
        _name = @"Template áo";
        _arrProperty = @[@"Size: S, M, L, XL.",
                         @"Chất liệu: vải zen hoa.",
                         @"Màu: trắng, đỏ, hồng."];
    }
    return self;
}

- (void)setDefaultData{
    _name = @"Template balo";
    _arrProperty = @[@"Size: S, M, L, XL.",
                     @"Chất liệu: da bò, vải bò, vải thô,...",
                     @"Màu: zằn zi, bò mài, đen, xám."];
}
@end
