//
//  NCAutocompleteTextView.h
//  Example
//
//  Created by Daniel Weber on 9/28/14.
//  Copyright (c) 2014 Null Creature. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@protocol NCRAutocompleteTableViewDelegate <NSObject>
@optional
- (NSImage *)imageForWord:(NSString *)word;
@end

@interface NCRAutocompleteTextView : NSTextView <NSTableViewDataSource, NSTableViewDelegate, NSPopoverDelegate>

@property (nonatomic, strong) NSArray *wordlist;
@property (nonatomic, weak) id <NCRAutocompleteTableViewDelegate> delegate;

@end
