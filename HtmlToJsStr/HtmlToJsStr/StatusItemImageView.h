//
//  StatusItemImageView.h
//  TofuDock
//
//  Created by Abel Lee on 13-10-14.
//  Copyright (c) 2013年 Abel Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "StatusItemImageViewDelegate.h"

@interface StatusItemImageView : NSImageView

@property (assign) id <StatusItemImageViewDelegate> delegate;


@end
