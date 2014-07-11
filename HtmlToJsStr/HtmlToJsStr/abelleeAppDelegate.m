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
@synthesize fuzhiBtn, htmlToJsBtn;

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
    
    self.curMode = @"htmlToJs";
    [self.spriteSheetPath setEnabled:NO];
    [self.spriteSheetPath setDelegate:self];
    
    [self.window setHidesOnDeactivate:YES];
    [self.window setDelegate:self];
}

- (IBAction) htmlToJsMode:(id)sender{
    if([self.curMode isEqualToString:@"htmlToJs"]) return;
    self.curMode = @"htmlToJs";
    [self.window setTitle:@"HtmlToJs"];
    [htmlTextField setString:@""];
    [jsTextField setString:@""];
    [self.spriteSheetPath setEnabled:NO];
}

- (IBAction) spriteSheetToCssMode:(id)sender{
    if([self.curMode isEqualToString:@"spriteSheetToCss"]) return;
    self.curMode = @"spriteSheetToCss";
    [self.window setTitle:@"SpriteSheetToCss"];
    [htmlTextField setString:@""];
    [jsTextField setString:@""];
    [self.spriteSheetPath setEnabled:YES];
}

- (IBAction) fuzhiBtnClicked:(id)sender{
    [[NSPasteboard generalPasteboard] clearContents];
    [[NSPasteboard generalPasteboard] setString:[[jsTextField textStorage] string] forType:NSStringPboardType];
}

- (void)controlTextDidChange:(NSNotification *)obj{
    [self doChange];
}

- (void) textDidChange:(NSNotification *)notification{
    [self doChange];
}

- (void) doChange{
    NSString* text = [[htmlTextField textStorage] string];
    if([self.curMode isEqual:@"htmlToJs"]){
        text = [text stringByReplacingOccurrencesOfString:@"\t" withString:@""];
        NSArray* arr = [text componentsSeparatedByString:@"\n"];
        NSString* res = @"var str = '';\n";
        for(NSString* s in arr){
            res = [res stringByAppendingString:[NSString stringWithFormat:@"str += '%@';\n", s]];
        }
        [jsTextField setString:res];
    }else if([self.curMode isEqual:@"spriteSheetToCss"]){
        NSString *path = [self.spriteSheetPath stringValue];
        NSLog(@"%@", text);
        NSError *error;
        NSData *nsData = [text dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:NO];
        NSDictionary *obj = [NSJSONSerialization JSONObjectWithData:nsData options:NSJSONReadingMutableContainers error:&error];
        NSMutableString *resStr = [NSMutableString stringWithString:@""];
        for(NSString *key in [obj objectForKey:@"frames"]){
            NSDictionary *dict = [[obj objectForKey:@"frames"] objectForKey:key];
            NSMutableString *str = [NSMutableString stringWithFormat:@".%@{", key];
            NSDictionary *frameObject = [dict objectForKey:@"frame"];
            int x = [[frameObject objectForKey:@"x"] intValue];
            int y = [[frameObject objectForKey:@"y"] intValue];
            int w = [[frameObject objectForKey:@"w"] intValue];
            int h = [[frameObject objectForKey:@"h"] intValue];
            [str appendString:[NSString stringWithFormat:@"background:url(%@) no-repeat -%dpx -%dpx;display:block;width:%dpx;height:%dpx;}\n", path, x, y, w, h]];
            [resStr appendString:str];
        }
        [jsTextField setString:resStr];
    }
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
