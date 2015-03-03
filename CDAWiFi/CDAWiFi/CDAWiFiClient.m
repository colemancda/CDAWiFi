//
//  CDAWiFiClient.m
//  CDAWiFi
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

#import "CDAWiFiClient.h"

@implementation CDAWiFiClient

+ (instancetype)sharedWiFiClient
{
    static CDAWiFiClient *sharedStore = nil;
    
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        sharedStore = [[self alloc] init];
        
        CDALog(@"Starting shared WiFi client");
    });
    
    return sharedStore;
}

@end
