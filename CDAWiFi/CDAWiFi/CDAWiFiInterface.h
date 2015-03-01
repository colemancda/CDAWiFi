//
//  CDAWiFiInterface.h
//  CDAWiFi
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

#import <ObjFW/ObjFW.h>
#import <CDAFoundation/CDAFoundation.h>
#import <CDAWiFi/CDAWiFiTypes.h>

@class CDAWiFiChannel, CDAWiFiNetwork, CDAWiFiConfiguration;

/*!
 * @class
 *
 * @abstract
 * Control and query a Wi-Fi interface.
 *
 * @discussion
 * All actions performed by a CDAWiFiInterface object are executed on the Wi-Fi device with the corresponding interface name.
 */
@interface CDAWiFiInterface: OFObject

/*!
 * @property
 *
 * @abstract
 * Returns the BSD name of the Wi-Fi interface (e.g. "en0").
 */
@property (readonly) OFString *interfaceName;

/*!
 * @method
 *
 * @result
 * YES if the Wi-Fi interface is on, NO otherwise.
 *
 * @abstract
 * Indicates the Wi-Fi interface power state.
 *
 * @discussion
 * Returns NO if an error occurs.
 */
- (BOOL)powerOn;

/*!
 * @method
 *
 * @result
 * An NSSet of CDAWiFiChannel objects.
 *
 * @abstract
 * Returns the set of channels supported by the Wi-Fi interface for the currently adopted country code.
 *
 * @discussion
 * Returns nil if an error occurs.
 */
- (OFSet *)supportedWLANChannels;

/*!
 * @method
 *
 * @abstract
 * Returns the current channel of the Wi-Fi interface.
 *
 * @discussion
 * Returns nil if an error occurs.
 */
- (CDAWiFiChannel *)wlanChannel;

/*!
 * @method
 *
 * @abstract
 * Returns the currently active physical layer (PHY) mode of the Wi-Fi interface.
 *
 * @discussion
 * ReturnsCDAWiFiPHYModeNone if an error occurs.
 */
- (CDAWiFiPHYMode)activePHYMode;

/*!
 * @method
 *
 * @abstract
 * Returns the current service set identifier (SSID) of the Wi-Fi interface, encoded as a string.
 *
 * @discussion
 * Returns nil if an error occurs, or if the interface is not participating in a Wi-Fi network,
 * or if the SSID can not be encoded as a valid UTF-8 or WinLatin1 string.
 */
- (OFString *)ssid;

/*!
 * @method
 *
 * @abstract
 * Returns the current service set identifier (SSID) for the interface, encapsulated in an NSData object.
 *
 * @discussion
 * Returns nil if an error occurs, or if the interface is not participating in a Wi-Fi network.
 */
- (OFDataArray *)ssidData;

/*!
 * @method
 *
 * @abstract
 * Returns the current basic service set identifier (BSSID) of the Wi-Fi interface, returned as an UTF-8 string.
 *
 * @discussion
 * Returns a UTF-8 string using hexadecimal characters formatted as XX:XX:XX:XX:XX:XX.
 * Returns nil if an error occurred, or if the interface is not participating in a Wi-Fi network.
 */
- (NSString *)bssid;

/*!
 * @method
 *
 * @abstract
 * Returns the current received signal strength indication (RSSI) measurement (dBm) for the Wi-Fi interface.
 *
 * @discussion
 * Returns 0 if an error occurs, or if the interface is not participating in a Wi-Fi network.
 */
- (int)rssiValue;

/*!
 * @method
 *
 * @abstract
 * Returns the current noise measurement (dBm) for the Wi-Fi interface.
 *
 * @discussion
 * Returns 0 if an error occurs, or if the interface is not participating in a Wi-Fi network.
 */
- (int)noiseMeasurement;

/*!
 * @method
 *
 * @abstract
 * Returns the current security type of the Wi-Fi interface.
 *
 * @discussion
 * ReturnsCDAWiFiSecurityUnknown if an error occurs, or if the interface is not participating in a Wi-Fi network.
 */
- (CDAWiFiSecurity)security;

/*!
 * @method
 *
 * @abstract
 * Returns the current transmit rate (Mbps) for the Wi-Fi interface.
 *
 * @discussion
 * Returns 0 if an error occurs, or if the interface is not participating in a Wi-Fi network.
 */
- (double)transmitRate;

/*!
 * @method
 *
 * @abstract
 * Returns the currently adopted country code (ISO/IEC 3166-1:1997) for the Wi-Fi interface.
 *
 * @discussion
 * Returns nil if an error occurs, or if the Wi-Fi interface is off.
 */
- (NSString *)countryCode;

/*!
 * @method
 *
 * @abstract
 * Returns the current operating mode for the Wi-Fi interface.
 *
 * @discussion
 * ReturnsCDAWiFiInterfaceModeNone if an error occurs, or if the interface is not participating in a Wi-Fi network.
 */
- (CDAWiFiInterfaceMode)interfaceMode;

/*!
 * @method
 *
 * @abstract
 * Returns the current transmit power (mW) for the Wi-Fi interface.
 *
 * @discussion
 * Returns 0 if an error occurs.
 */
- (int)transmitPower;

/*!
 * @method
 *
 * @abstract
 * Returns the hardware media access control (MAC) address for the Wi-Fi interface, returned as an UTF-8 string.
 *
 * @discussion
 * The standard format for printing a MAC-48 address XX:XX:XX:XX:XX:XX is used to represent
 * the MAC address as a string.
 * Returns nil if an error occurs.
 */
- (NSString *)hardwareAddress;

/*!
 * @method
 *
 * @result
 * YES if the corresponding network service is active, NO otherwise.
 *
 * @abstract
 * Indicates the network service state of the Wi-Fi interface.
 *
 * @discussion
 * Returns NO if an error occurs.
 */
- (BOOL)serviceActive;

/*!
 * @method
 *
 * @result
 * An NSSet of CDAWiFiNetwork objects.
 *
 * @abstract
 * Returns the scan results currently in the scan cache for the Wi-Fi interface.
 *
 * @discussion
 * Returns nil if an error occurs.
 */
- (OFSet *)cachedScanResults;

/*!
 * @method
 *
 * @abstract
 * Returns the current configuration for the Wi-Fi interface.
 *
 * @discussion
 * Returns nil if an error occurs.
 */
- (CDAWiFiConfiguration *)configuration;

/*! @functiongroup Setting the Power State */

/*!
 * @method
 *
 * @param power
 * A BOOL value indicating Wi-Fi power state. Specify YES to turn on the Wi-Fi interface.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Sets the Wi-Fi interface power state.
 *
 * @discussion
 */
- (BOOL)setPower:(BOOL)power error:(out CDAError **)error;

/*! @functiongroup Setting the Channel */

/*!
 * @method
 *
 * @param channel
 * A CDAWiFiChannel object.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Sets the Wi-Fi interface channel.
 *
 * @discussion
 * Setting the channel while the interface is associated to a Wi-Fi network is not permitted.
 */
- (BOOL)setWLANChannel:(CDAWiFiChannel *)channel error:(out CDAError **)error;

/*! @functiongroup Setting Keys */

/*!
 * @method
 *
 * @param key
 * An NSData object containing the pairwise master key (PMK).
 * Passing nil clear the PMK for the Wi-Fi interface.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Sets the Wi-Fi interface pairwise master key (PMK).
 *
 * @discussion
 * The specified key must be exactly 32 octets.
 */
- (BOOL)setPairwiseMasterKey:(OFDataArray *)key error:(out CDAError **)error;

/*!
 * @method
 *
 * @param key
 * An NSData object containing the WEP key.
 * Passing nil clears the WEP key for the Wi-Fi interface.
 *
 * @param flags
 * A bitmask indicating which CDAWiFiCipherKeyFlags to use for the specified WEP key.
 *
 * @param index
 * An int indicating which default key index (1-4) to use for the specified key.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Sets the Wi-Fi interface WEP key.
 */
- (BOOL)setWEPKey:(OFDataArray *)key flags:(CDAWiFiCipherKeyFlags)flags index:(int)index error:(out CDAError **)error;

/*! @functiongroup Scanning for Networks */

/*!
 * @method
 *
 * @param ssid
 * Probe request SSID.
 * Pass an SSID to perform a directed scan for hidden Wi-Fi networks.
 * This parameter is optional.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * An NSSet of CDAWiFiNetwork objects, or nil if an error occurs.
 *
 * @abstract
 * Performs a scan for Wi-Fi networks and returns scan results to the caller.
 *
 * @discussion
 * This method will block for the duration of the scan.
 * Requires the <i>com.apple.wifi.scan</i> entitlement.
 */
- (OFSet *)scanForNetworksWithSSID:(OFDataArray *)ssid error:(out CDAError **)error;

/*!
 * @method
 *
 * @param networkName
 * Probe request SSID, encoded as an UTF-8 string.
 * Pass a networkName to perform a directed scan for hidden Wi-Fi networks.
 * This parameter is optional.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * An NSSet of CDAWiFiNetwork objects, or nil if an error occurs.
 *
 * @abstract
 * Performs a scan for Wi-Fi networks and returns scan results to the caller.
 *
 * @discussion
 * This method will block for the duration of the scan.
 * Requires the <i>com.apple.wifi.scan</i> entitlement.
 */
- (OFSet *)scanForNetworksWithName:(OFString *)networkName error:(out CDAError **)error;

/*! @functiongroup Joining a Network */

/*!
 * @method
 *
 * @param network
 * The network to which the Wi-Fi interface will associate.
 *
 * @param password
 * The network passphrase or key. Required for association to WEP, WPA Personal, and WPA2 Personal networks.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Associates to a W-Fi network using the specified passphrase.
 *
 * @discussion
 * This method will block for the duration of the association.
 * Requires the <i>com.apple.wifi.associate</i> entitlement.
 */
- (BOOL)associateToNetwork:(CDAWiFiNetwork *)network password:(OFString *)password error:(out CDAError **)error;

/*!
 * @method
 *
 * @abstract
 * Disassociates from the current Wi-Fi network.
 *
 * @discussion
 * Requires the <i>com.apple.wifi.associate</i> entitlement.
 */
- (void)disassociate;

/*!
 * @method
 *
 * @param network
 * The network to which the Wi-Fi interface will associate.
 *
 * @param username
 * The username to use for 802.1X authentication.
 *
 * @param password
 * The password to use for 802.1X authentication.
 *
 * @param identity
 * The identity to use for IEEE 802.1X authentication. Holds the corresponding client certificate.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Associates to an enterprise W-Fi network using the specified 802.1X credentials.
 *
 * @discussion
 * This method will block for the duration of the association.
 * Requires the <i>com.apple.wifi.associate</i> entitlement.
 */
//- (BOOL)associateToEnterpriseNetwork:(CDAWiFiNetwork *)network identity:(SecIdentityRef)identity username:(NSString *)username password:(NSString *)password error:(out CDAError **)error;

/*! @functiongroup Creating an IBSS Network */

/*!
 * @method
 *
 * @param ssidData
 * The SSID to use for the IBSS network.
 * Pass nil to use the machine name as the IBSS network name.
 *
 * @param security
 * The CDAWiFiIBSSModeSecurity type.
 *
 * @param channel
 * The channel on which the IBSS network will be created.
 *
 * @param password
 * The password to be used. This paramter is required for CDAWiFiIBSSModeSecurityWEP40 or CDAWiFiIBSSModeSecurityWEP104 security types.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Creates a computer-to-computer (IBSS) network.
 *
 * @discussion
 * Requires the <i>com.apple.wifi.ibss</i> entitlement.
 */
//- (BOOL)startIBSSModeWithSSID:(NSData *)ssidData security:(CDAWiFiIBSSModeSecurity)security channel:(uint)channel password:(NSString *)password error:(out CDAError **)error;

/*! @functiongroup Committing a Wi-Fi Configuration */

/*!
 * @method
 *
 * @param configuration
 * The Wi-Fi configuration to commit to disk.
 *
 * @param authorization
 * An SFAuthorization object to use for authorizing the commit.
 * This parameter is optional.
 *
 * @param error
 * An CDAError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Commits a CDAWiFiConfiguration for the given Wi-Fi interface.
 *
 * @discussion
 * This method requires the caller have root privileges
 * or obtain administrator privileges using the SFAuthorization API.
 */
- (BOOL)commitConfiguration:(CDAWiFiConfiguration *)configuration error:(out CDAError **)error;

@end
