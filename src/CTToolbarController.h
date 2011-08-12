#import <Cocoa/Cocoa.h>

@class CTBrowser;
@class CTTabContents;

// A controller for the toolbar in the browser window.
//
// This class is meant to be subclassed -- the default implementation will load
// a placeholder/dummy nib. You need to do two things:
//
// 1. Create a new subclass of CTToolbarController.
//
// 2. Copy the Toolbar.xib into your project (or create a new) and modify it as
//    needed (add buttons etc). Make sure the "files owner" type matches your
//    CTToolbarController subclass.
//
// 3. Implement createToolbarController in your CTBrowser subclass to initialize
//    and return a CTToolbarController based on your nib.
//
@interface CTToolbarController : NSViewController

- (id)initWithNibName:(NSString*)nibName
               bundle:(NSBundle*)bundle
              browser:(CTBrowser*)browser;

// Set the opacity of the divider (the line at the bottom) *if* we have a
// |ToolbarView| (0 means don't show it); no-op otherwise.
- (void)setDividerOpacity:(CGFloat)opacity;

// Called when the current tab is changing. Subclasses should implement this to
// update the toolbar's state.
- (void)updateToolbarWithContents:(CTTabContents*)contents
               shouldRestoreState:(BOOL)shouldRestore;

@end
