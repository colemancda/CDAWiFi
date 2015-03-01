//
//  CDAWiFiNetwork.h
//  CDAWiFi
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

#import <ObjFW/ObjFW.h>
#import <CDAWiFi/CDAWiFiTypes.h>

@class CDAWiFiChannel;

@interface CDAWiFiNetwork : OFObject <OFCopying, OFSerialization>

/*!
 * @property
 *
 * @abstract
 * Returns the service set identifier (SSID) for the Wi-Fi network device, encoded as a string.
 *
 * @discussion
 * Returns nil if the SSID can not be encoded as a valid UTF-8 or WinLatin1 string.
 */
@property (readonly) OFString *ssid;


/*!
 * @property
 *
 * @abstract
 * Returns the service set identifier (SSID) for the Wi-Fi network device, encapsulated in an NSData object.
 *
 * @discussion
 * The SSID is defined as 1-32 octets.
 */
@property (readonly) OFDataArray *ssidData;

/*!
 * @property
 *
 * @abstract
 * Returns the basic service set identifier (BSSID) for the Wi-Fi network device, returned as UTF-8 string.
 *
 * @discussion
 * Returns a UTF-8 string using hexadecimal characters formatted as XX:XX:XX:XX:XX:XX.
 */
@property (readonly) NSString *bssid;

/*!
 * @property
 *
 * @abstract
 * The operating channel of the Wi-Fi device.
 */
@property (readonly) CDAWiFiChannel *wlanChannel;

/*!
 * @property
 *
 * @abstract
 * Returns the received signal strength indication (RSSI) measurement (dBm) for the Wi-Fi device.
 */
@property (readonly) int rssiValue;

/*!
 * @property
 *
 * @abstract
 * Returns the noise measurement (dBm) for the Wi-Fi device.
 */
@property (readonly) int noiseMeasurement;

/*!
 * @property
 *
 * @abstract
 * Returns information element data included in beacon or probe response frames.
 */
@property (readonly) OFBigDataArray *informationElementData;

/*!
 * @property
 *
 * @abstract
 * Returns the advertised country code (ISO/IEC 3166-1:1997) for the Wi-Fi device.
 */
@property (readonly) OFString *countryCode;

/*!
 * @property
 *
 * @abstract
 * Returns the beacon interval (ms) for the Wi-Fi device.
 */
@property (readonly) int beaconInterval;

/*!
 * @property
 *
 * @result
 * YES if the Wi-Fi device is part of an IBSS network, NO otherwise.
 *
 * @abstract
 * Indicates whether or not the Wi-Fi device is participating in an independent basic service set (IBSS), or ad-hoc Wi-Fi network.
 */
@property (readonly) BOOL ibss;

/*! @functiongroup Comparing Networks */

/*!
 * @method
 *
 * @param network
 * A CWNetwork object.
 *
 * @result
 * YES if the objects are equal, NO otherwise.
 *
 * @abstract
 * Determine CWNetwork equality.
 *
 * @discussion
 * CWNetwork objects are considered equal if their corresponding <i>ssidData</i> and <i>bssid</i> properties are equal.
 */
- (BOOL)isEqualToNetwork:(CDAWiFiNetwork *)network;

/*! @methodgroup Getting Supported Security Types */

/*!
 * @method
 *
 * @param security
 * A CWSecurity type value.
 *
 * @result
 * <i>YES</i> if the Wi-Fi device supports the specified security type, <i>NO</i> otherwise.
 *
 * @abstract
 * Determine which security types a Wi-Fi device supports.
 */
- (BOOL)supportsSecurity:(CDAWiFiSecurity)security;

/*! @methodgroup Getting Supported PHY Modes */

/*!
 * @method
 *
 * @param phyMode
 * A CWPHYMode type value.
 *
 * @result
 * YES if the Wi-Fi device supports the specified PHY mode, NO otherwise.
 *
 * @abstract
 * Determine which PHY modes a Wi-Fi device supports.
 */
- (BOOL)supportsPHYMode:(CDAWiFiPHYMode)phyMode;

@end
