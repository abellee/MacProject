//
//  StatusItemImageView.m
//  TofuDock
//
//  Created by Abel Lee on 13-10-14.
//  Copyright (c) 2013年 Abel Lee. All rights reserved.
//

#import "StatusItemImageView.h"

@implementation StatusItemImageView

@synthesize delegate;

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
    }
    return self;
}

- (void)mouseDown:(NSEvent *)theEvent
{
    NSRect statusRect = [[self window] frame];
    if(delegate && [delegate respondsToSelector:@selector(showWindowWithRect:)]){
        [delegate showWindowWithRect:statusRect];
    }
}

- (void)drawRect:(NSRect)dirtyRect
{
	[super drawRect:dirtyRect];
	
    // Drawing code here.
}

@end
