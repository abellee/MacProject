//
//  abelleeAppDelegate.m
//  HtmlToJsStr
//
//  Created by Abel Lee on 14-5-22.
//  Copyright (c) 2014年 Abel Lee. All rights reserved.
//

#import "abelleeAppDelegate.h"
#import "StatusItemImageView.h"

@implementation abelleeAppDelegate

@synthesize statusItem;
@synthesize imageView, htmlTextField, jsTextField;
@synthesize fuzhiBtn;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    statusItem = [[NSStatusBar systemStatusBar] statusItemWithLength:NSVariableStatusItemLength];
    NSImage* image = [NSImage imageNamed:@"20x20.png"];
    imageView = [[StatusItemImageView alloc] initWithFrame:NSMakeRect(0, 0, image.size.width, image.size.height)];
    [imageView setDelegate:self];
    [imageView setImage:image];
    [statusItem setView:imageView];
    
    [jsTextField setEditable:NO];
    [htmlTextField setDelegate:self];
    [htmlTextField setRichText:NO];
    
    [self.window setHidesOnDeactivate:YES];
    [self.window setDelegate:self];
}

- (IBAction) fuzhiBtnClicked:(id)sender{
    [[NSPasteboard generalPasteboard] clearContents];
    [[NSPasteboard generalPasteboard] setString:[[jsTextField textStorage] string] forType:NSStringPboardType];
}

- (void) textDidChange:(NSNotification *)notification{
    NSString* text = [[htmlTextField textStorage] string];
    text = [text stringByReplacingOccurrencesOfString:@"\t" withString:@""];
    NSArray* arr = [text componentsSeparatedByString:@"\n"];
    NSString* res = @"var str = '';\n";
    for(NSString* s in arr){
        res = [res stringByAppendingString:[NSString stringWithFormat:@"str += '%@';\n", s]];
    }
    [jsTextField setString:res];
}

- (void)applicationDidResignActive:(NSNotification *)notification
{
    [self.window close];
}

- (void)showWindowWithRect:(NSRect)rect
{
    if(self.window.isVisible){
        [self.window close];
    }else{
        self.window.alphaValue = 0.0;
        [self.window.animator setAlphaValue:0];
        [[NSApplication sharedApplication] activateIgnoringOtherApps:YES];
        [self.window makeKeyAndOrderFront:self];
        
        NSRect wr = self.window.frame;
        NSPoint point = NSMakePoint(rect.origin.x - wr.size.width / 2 + rect.size.width / 2, rect.origin.y - wr.size.height);
        [[NSApplication sharedApplication] activateIgnoringOtherApps:YES];
        [self.window makeKeyAndOrderFront:self];
        [self.window setFrameOrigin:point];
        
        [self.window.animator setAlphaValue:1];
    }
}

@end
