//
//  abelleeAppDelegate.h
//  HtmlToJsStr
//
//  Created by Abel Lee on 14-5-22.
//  Copyright (c) 2014年 Abel Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "StatusItemImageViewDelegate.h"

@class StatusItemImageView;

@interface abelleeAppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate, StatusItemImageViewDelegate, NSTextViewDelegate, NSTextFieldDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (retain) NSStatusItem* statusItem;
@property (retain) StatusItemImageView* imageView;
@property (assign) NSString *curMode;

@property (retain) IBOutlet NSTextView* htmlTextField;
@property (retain) IBOutlet NSTextView* jsTextField;
@property (retain) IBOutlet NSButton* fuzhiBtn;
@property (retain) IBOutlet NSButton* htmlToJsBtn;
@property (retain) IBOutlet NSTextField *spriteSheetPath;

@end
