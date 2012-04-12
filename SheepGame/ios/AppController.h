//
//  SheepGameAppController.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright Greplin, Inc. 2012. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
}

@end

