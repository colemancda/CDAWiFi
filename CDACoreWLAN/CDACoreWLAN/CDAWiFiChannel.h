//
//  CDAWiFiChannel.h
//  CDACoreWLAN
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

#import <ObjFW/ObjFW.h>
#import <CDACoreWLAN/CDAWiFiTypes.h>

/*!
 * @class
 *
 * @abstract
 * Represents an IEEE 802.11 channel.
 *
 * @discussion
 * The CDAWiFiChannel class is used by both CWInterface and CWNetwork as a representation of an IEEE 802.11 Wi-Fi channel.
 */
@interface CDAWiFiChannel : OFObject <OFCopying, OFSerialization>

/*!
 * @property
 *
 * @abstract
 * The channel number represented as an integer value.
 */
@property (readonly) int channelNumber;

/*!
 * @property
 *
 * @abstract
 * The channel width as indicated by the CWChannelWidth type.
 */
@property (readonly) CDAWiFiChannelWidth channelWidth;

/*!
 * @property
 *
 * @abstract
 * The channel band as indicated by the CWChannelBand type.
 */
@property (readonly) CDAWiFiChannelBand channelBand;

/*! @functiongroup Comparing Wi-Fi Channels */

/*!
 * @method
 *
 * @param channel
 * The CWChannel with which to compare the receiver.
 *
 * @result
 * YES if the objects are equal, otherwise NO.
 *
 * @abstract
 * Determine CWChannel equality.
 *
 * @discussion
 * CWChannel objects are considered equal if all their corresponding properties are equal.
 */
- (BOOL)isEqualToChannel:(CDAWiFiChannel *)channel;

@end
