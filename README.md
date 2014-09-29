NCRAutocompleteTextView
=======================

An NSTextView subclass that implements a popover to autocomplete words.

![Image](http://i.imgur.com/T7U2NPo.png)

Installation
===
Drag `NCRAutocompleteTextView.h` and `NCRAutocompleteTextView.m` files onto your project. In interface builder, change the class of your `NSTextView` to `NCRAutocompleteTextView`. I've only tested this on 10.9, but it should work on 10.7+ with ARC.

Usage
===
There are several options that are all currently set by `#define`'s at the top of the `.m` file:
+ `#define MAX_RESULTS 10`
Sets the maximum number of lines of autocomplete suggestions. You can always scroll to see the rest of the matches. A smaller number of matches will shrink the popover window.

+ `#define HIGHLIGHT_COLOR [NSColor colorWithCalibratedRed:0.474 green:0.588 blue:0.743 alpha:1]`
Sets the color of the highlight when selecting a match.

+ `#define HIGHLIGHT_RADIUS 4.0`
The highlight can have a radius. Set it to 0 if you don't won't a rounded rect.

+ `#define INTERCELL_SPACING NSMakeSize(0, 5.0)`
Specifies the amount of space between rows. The first number (the horizontal spacing) won't have an effect because there is only one column at this time.

+ `#define POPOVER_WIDTH 250.0`
The total width of the popover. The height is adjusted dynamically depending on how many matches are found.

+ `#define POPOVER_PADDING 3.0`
The amount of space between the edge of the popover and the tableview displaying the matches.

+ `#define POPOVER_APPEARANCE NSPopoverAppearanceHUD` or `#define POPOVER_APPEARANCE NSPopoverAppearanceMinimal`
Sets the appearance of the popover. Apple offers two: `NSPopoverAppearanceHUD` is shown in the screenshot and `NSPopoverAppearanceMinimal` is light. You would want to change the font color (see below) to something dark if you use `NSPopoverAppearanceMinimal`.

+ `#define POPOVER_FONT [NSFont fontWithName:@"Menlo" size:12.0]`
Sets the font used to display matches. Fixed-width fonts tend to work better.

+ `#define POPOVER_BOLDFONT [NSFont fontWithName:@"Menlo-Bold" size:13.0]`
The characters that have already been typed can be set in a different font. The default is a bold, slightly larger font.

+ `#define POPOVER_TEXTCOLOR [NSColor whiteColor]`
The text color of the matches. If you use `NSPopoverAppearanceMinimal`, you'll want to change this to a darker color
