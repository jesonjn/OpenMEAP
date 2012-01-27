/*
 ###############################################################################
 #                                                                             #
 #    Copyright (C) 2011 OpenMEAP, Inc.                                        #
 #    Credits to Jonathan Schang & Robert Thacher                              #
 #                                                                             #
 #    Released under the GPLv3                                                 #
 #                                                                             #
 #    OpenMEAP is free software: you can redistribute it and/or modify         #
 #    it under the terms of the GNU General Public License as published by     #
 #    the Free Software Foundation, either version 3 of the License, or        #
 #    (at your option) any later version.                                      #
 #                                                                             #
 #    OpenMEAP is distributed in the hope that it will be useful,              #
 #    but WITHOUT ANY WARRANTY; without even the implied warranty of           #
 #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
 #    GNU General Public License for more details.                             #
 #                                                                             #
 #    You should have received a copy of the GNU General Public License        #
 #    along with OpenMEAP.  If not, see <http://www.gnu.org/licenses/>.        #
 #                                                                             #
 ###############################################################################
 */

#import <openmeap-slic-core.h>
#import <UIKit/UIKit.h>
#import "OmSlicAppDelegate.h"

@class OmSlicAppDelegate;

/**
 * Controller for the primary UIWebView
 */
@interface OmSlicViewController : UIViewController {
	
	/**
	 * Used to clear the app's webview cache after an update.
	 */
	int cachePolicy;
	
	/**
	 * Used for access to the OmSlicAppDelegate.
	 */
	OmSlicAppDelegate * appDelegate;
    
    NSString * updateHeaderJSON;
}

@property int cachePolicy;
@property OmSlicAppDelegate * appDelegate;
@property (retain,nonatomic) NSString * updateHeaderJSON;

- (void)setUpdateHeader:(NSString*)headerJSON;
-(NSString*) executeJavascriptInMainThread:(NSString *)javascript;
-(NSString*) executeJavascriptInMainThread:(NSString *)javascript waitUntilDone:(Boolean)waitTil;
-(NSString*) executeJSCallbackInMainThread:(NSString *)callbackJS withArguments:(NSArray*)args waitUntilDone:(Boolean)waitTil;

@end

