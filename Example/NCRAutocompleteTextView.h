//
//  NCAutocompleteTextView.h
//  Example
//
//  Created by Daniel Weber on 9/28/14.
//  Copyright (c) 2014 Null Creature. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NCRAutocompleteTextView : NSTextView <NSTableViewDataSource, NSTableViewDelegate, NSPopoverDelegate>

@property (nonatomic, strong) NSArray *wordlist;

@end
