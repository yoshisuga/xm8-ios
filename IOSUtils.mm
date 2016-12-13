//
//  IOSUtils.m
//  xm8-ios
//
//  Created by Yoshi Sugawara on 12/12/16.
//
//

#import "IOSUtils.h"

#include "ios-glue.h"

void ios_get_base_path(char *path) {
    NSArray *paths;
    NSString *DocumentsDirPath;
    
    paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    DocumentsDirPath = [paths objectAtIndex:0];
    sprintf(path, "%s/", [DocumentsDirPath UTF8String]);
}

@implementation IOSUtils


@end

