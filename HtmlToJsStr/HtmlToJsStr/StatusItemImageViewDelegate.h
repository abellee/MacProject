//
//  StatusItemImageViewDelegate.h
//  TofuDock
//
//  Created by Abel Lee on 13-10-14.
//  Copyright (c) 2013年 Abel Lee. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol StatusItemImageViewDelegate <NSObject>

@optional
- (void)showWindowWithRect:(NSRect)rect;

@end
