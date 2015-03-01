//
//  CDAWiFiNetworkProfile.h
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
 * Encapsulates a preferred network entry.
 */
@interface CDAWiFiNetworkProfile : OFObject

/*!
 * @property
 *
 * @abstract
 * Returns the service set identifier (SSID) for the Wi-Fi network profile, encoded as a string.
 *
 * @discussion
 * Returns nil if the SSID can not be encoded as a valid UTF-8 or WinLatin1 string.
 */
@property(readonly, copy) NSString *ssid;

/*!
 * @property
 *
 * @abstract
 * Returns the service set identifier (SSID) for the Wi-Fi network profile, encapsulated in an NSData object.
 *
 * @discussion
 * The SSID is 1-32 octets.
 */
@property(readonly, copy) OFDataArray *ssidData;

/*!
 * @property
 *
 * @abstract
 * Returns the security type of the Wi-Fi network profile.
 */
@property(readonly) CDAWiFiSecurity security;

/*! @functiongroup Creating a Network Profile */

/*!
 * @method
 *
 * @abstract
 * Convenience method for getting a CWNetworkProfile object.
 */
+ (instancetype)networkProfile;

/*!
 * @method
 *
 * @abstract
 * Initializes a CWNetworkProfile object.
 */
- (instancetype)init;

/*!
 * @method
 *
 * @param networkProfile
 * A CWNetworkProfile object.
 *
 * @result
 * A CWNetworkProfile object.
 *
 * @abstract
 * Initializes a CWNetworkProfile object with the properties of an existing CWNetworkProfile object.
 */
- (instancetype)initWithNetworkProfile:(CDAWiFiNetworkProfile *)networkProfile;

/*!
 * @method
 *
 * @param networkProfile
 * A CWNetworkProfile object.
 *
 * @result
 * A CWNetworkProfile object.
 *
 * @abstract
 * Convenience method for getting a CWNetworkProfile object initialized with the properties of an existing CWNetworkProfile object.
 */
+ (instancetype)networkProfileWithNetworkProfile:(CDAWiFiNetworkProfile *)networkProfile;

/*! @functiongroup Comparing Network Profiles */

/*!
 * @method
 *
 * @param network
 * A CWNetworkProfile object.
 *
 * @result
 * YES if the objects are equal, NO otherwise.
 *
 * @abstract
 * Determine CWNetworkProfile equality.
 *
 * @discussion
 * CWNetworkProfile objects are considered equal if their corresponding <i>ssidData</i> and <i>security</i> properties are equal.
 */
- (BOOL)isEqualToNetworkProfile:(CDAWiFiNetworkProfile *)networkProfile;

@end

/*!
 * @class
 *
 * @abstract
 * Mutable subclass of CWNetworkProfile.  Use this class for changing profile properties.
 *
 * @discussion
 * To commit Wi-Fi network profile changes, use -[CWMutableConfiguration setNetworkProfiles:] and
 * -[CWInterface commitConfiguration:authorization:error:].
 */

@interface CDAWiFiMutableNetworkProfile : CDAWiFiNetworkProfile

/*!
 * @property
 *
 * @abstract
 * Set the service set identifier (SSID).
 */
@property (copy) OFDataArray *ssidData;

/*!
 * @property
 *
 * @abstract
 * Set the security type.
 */
@property CDAWiFiSecurity security;

@end
