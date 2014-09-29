//
//  AppDelegate.m
//  Example
//
//  Created by Daniel Weber on 9/28/14.
//  Copyright (c) 2014 Null Creature. All rights reserved.
//

#import "AppDelegate.h"
#import "NCRAutocompleteTextView.h"

@interface AppDelegate ()
@property (weak) IBOutlet NSWindow *window;
@property (nonatomic, assign) IBOutlet NCRAutocompleteTextView *textView;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    
    NSURL *url = [[NSBundle mainBundle] URLForResource:@"wordlist" withExtension:@"txt"];
    NSString *countriesString = [NSString stringWithContentsOfURL:url encoding:NSUTF8StringEncoding error:nil];
    self.textView.wordlist = [countriesString componentsSeparatedByString:@"\n"];
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
