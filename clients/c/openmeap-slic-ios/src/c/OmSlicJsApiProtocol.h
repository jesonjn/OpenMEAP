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
#import <Foundation/Foundation.h>

OM_EXPORT void ios_update_callback_func(om_update_callback_info_ptr update_status);

@class NSURLProtocolClient;

@interface OmSlicJsApiProtocol : NSURLProtocol {
}

- (NSString *) performUpdateCheck:(NSString *)callBack;

@end
