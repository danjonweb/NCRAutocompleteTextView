Yosemite Update
===

![NSPopoverAppearanceHUD](http://i.imgur.com/2OzegJf.png)

![NSPopoverAppearanceMinimal](http://i.imgur.com/GBcKfoY.png)

I have updated `NCRAutocompleteTextView` in several ways. First, if you tried to build the previous version with the 10.10 SDK, it would compile and run, but there were rendering issues. This is because Apple deprecated cell-based `NSTableView`s in Yosemite and a few APIs no longer worked (which is a bug). I have fixed these issues, but now this class will *only* build with the 10.10 SDK. If you really want to use it with older SDKs, you need to change the `POPOVER_APPEARANCE` constant back to the pre-10.10 values of `NSPopoverAppearanceMinimal` or `NSPopoverAppearanceHUD` instead of `NSAppearanceNameVibrantLight` or `NSAppearanceNameVibrantDark`.

**Please read this list of other changes, as there are many big differences in this version.**

- I have switched to a view-based NSTableView in this version. Because I use a standard `NSTableViewCell`, the ability to customize the spacing of the image view is gone (although I don't consider this a big loss because the defaults look good). View-based tableviews are worse in worse in one way, though. Because of the way the selection highlight is drawn, there seems to be some small amount of "flicker" when the popover is shown. I have minimized this as much as I can, but it still doesn't look quite as good as before. I'm not sure if it's worth switching back to a cell-based `NSTableView`, however.
- I have also changed a few other defaults. The highlight radius and popover padding now default to zero to give it a more compact and native appearance (although you can still customize them).
- I fixed a major bug where the popover would only show if a space preceded the word. This was not a good choice because it didn't show up in a number of circumstances, such as when the word was the first word of a line or came after a comma. I changed it so the word must be preceded by a character in the `WORD_BOUNDARY_CHARS` character set. The default is `[[NSCharacterSet alphanumericCharacterSet] invertedSet]`, so any non-alphanumeric character will signify a new word.
- I changed the way completions are supplied. Instead of setting the `wordlist` property, I now use the same delegate API that Apple uses for autocomplete. There are now two (optional) delegate methods: `textView:imageForCompletion:` and `textView:completions:forPartialWordRange:charRange indexOfSelectedItem:`. The first is just a slightly different name for the delegate method that supplies images for word completions. The second is how you now supply an array of completions for a partial word and should work the same way it does in Apple's implementation. See the included app for an example of how to use it or look online.

Known Issues
===
- For some reason when the list is scrolled, there is a dark spot under the scrollbar:
  
  ![Rendering bug](http://i.imgur.com/Kl1lYQI.png)
      
  It's worse for the dark theme. I'm not sure how to work around this -- if anyone has any suggestions, let me know.

NCRAutocompleteTextView (old, but still useful as a reference)
=======================

An NSTextView subclass that implements a popover to autocomplete words.

![NSPopoverAppearanceHUD](http://i.imgur.com/jypp1UW.png)

![NSPopoverAppearanceMinimal](http://i.imgur.com/3v36oFC.png)

Installation
===
Drag `NCRAutocompleteTextView.h` and `NCRAutocompleteTextView.m` files onto your project. In interface builder, change the class of your `NSTextView` to `NCRAutocompleteTextView`. I've only tested this on 10.9, but it should work on 10.7+ with ARC.

Usage
===
Set the property `wordlist` on the `NCRAutocompleteTextView` to an array of words you want to autocomplete. That's it! Note about capitalization: words will match even if they aren't the same case. When a match is selected from the autocomplete popover, the case from the suggestion will replace the case the user typed.

You can (optionally) supply images for word suggestions. Just set the `delegate` property of the `NCRAutocompleteTextView` and implement the method `-(NSImage *)imageForWord:(NSString *)word` in your delegate. The `word` parameter is the full word that is suggested in the autocomplete popover. You just need to return the appropriate image. See the example project.

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
Sets the appearance of the popover. Apple offers two: `NSPopoverAppearanceHUD` is dark and `NSPopoverAppearanceMinimal` is light. You would want to change the font color (see below) to something dark if you use `NSPopoverAppearanceMinimal`.

+ `#define POPOVER_FONT [NSFont fontWithName:@"Menlo" size:12.0]`
Sets the font used to display matches. Fixed-width fonts tend to work better.

+ `#define POPOVER_BOLDFONT [NSFont fontWithName:@"Menlo-Bold" size:13.0]`
The characters that have already been typed can be set in a different font. The default is a bold, slightly larger font.

+ `#define POPOVER_TEXTCOLOR [NSColor whiteColor]`
The text color of the matches. If you use `NSPopoverAppearanceMinimal`, you'll want to change this to a darker color

+ `#define IMAGE_ORIGIN_X_OFFSET 5`
The number of px that the image is moved over to the right. When the image is moved, it moves the text to the right as well. This has the effect of left padding for the entire cell.

+ `#define IMAGE_ORIGIN_Y_OFFSET -2`
The number of px that the image is moved down. If it's negative, the image gets moved up. You will want to change this value to get the image and text to line up, depending on the size of the images. It would be possible to find a good value for this algorithmically, but for now it's easy to make manual adjustments.

+ `#define IMAGE_PADDING 3`
The number of pixels between the image and text.
