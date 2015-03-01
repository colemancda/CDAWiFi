//
//  CDAWiFiChannel.m
//  CDAWiFi
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

#import "CDAWiFiChannel.h"

@implementation CDAWiFiChannel

#pragma mark - Equality

-(BOOL)isEqualToChannel:(CDAWiFiChannel *)channel
{
    if (!channel) {
        return NO;
    }
    
    return (self.channelNumber == channel.channelNumber &&
            self.channelWidth == channel.channelWidth &&
            self.channelBand == channel.channelBand);
}

- (bool)isEqual:(id)other
{
    if (other == self) {
        return YES;
    } else if (![super isEqual:other]) {
        return NO;
    } else {
        return [self isEqualToChannel:other];
    }
}

- (uint32_t)hash
{
    return (_channelNumber ^ _channelWidth ^ _channelBand);
}

@end
