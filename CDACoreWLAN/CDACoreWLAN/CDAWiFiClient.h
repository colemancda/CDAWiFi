//
//  CDAWiFiClient.h
//  CDACoreWLAN
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

#import <ObjFW/ObjFW.h>
#import <CDACoreWLAN/CDAWiFiTypes.h>

@class CDAWiFiInterface, CDAError;

/*!
 * @protocol
 *
 * @abstract
 * Receive Wi-Fi event notifications.
 */
@protocol CDAWiFiEventDelegate

@optional

/*!
 * @method
 *
 * @abstract
 * Invoked if the connection to the Wi-Fi subsystem is temporarily interrupted.
 *
 * @discussion
 * All event notifications for which the Wi-Fi client has registered will be automatically re-registered if
 * the connection is interrupted.
 * The Wi-Fi client should re-sync any local state which is updated as a result of Wi-Fi event notifications.
 */
- (void)clientConnectionInterrupted;

/*!
 * @method
 *
 * @abstract
 * Invoked if the connection to the Wi-Fi subsystem is permanently invalidated.
 */
- (void)clientConnectionInvalidated;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the Wi-Fi power state changes.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypePowerDidChange event type
 * to register for power event notifications.
 * Use -[CDAWiFiInterface powerOn] to query the current Wi-Fi power state.
 */
- (void)powerStateDidChangeForWiFiInterfaceWithName:(NSString *)interfaceName;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the current SSID changes.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypeSSIDDidChange event type
 * to register for SSID event notifications.
 * Use -[CDAWiFiInterface ssidData] or -[CDAWiFiInterface ssid] to query the current SSID.
 */
- (void)ssidDidChangeForWiFiInterfaceWithName:(NSString *)interfaceName;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the current BSSID changes.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypeBSSIDDidChange event type
 * to register for BSSID event notifications.
 * Use -[CDAWiFiInterface bssid] to query the current BSSID.
 */
- (void)bssidDidChangeForWiFiInterfaceWithName:(NSString *)interfaceName;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the currently adopted country code changes.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypeCountryCodeDidChange event type
 * to register for country code event notifications.
 * Use -[CDAWiFiInterface countryCode] to query the currently adopted country code.
 */
- (void)countryCodeDidChangeForWiFiInterfaceWithName:(NSString *)interfaceName;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the Wi-Fi link state changes.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypeLinkDidChange event type
 * to register for link event notifications.
 */
- (void)linkDidChangeForWiFiInterfaceWithName:(NSString *)interfaceName;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @param rssi
 * The RSSI value for the currently associated network on the Wi-Fi interface.
 *
 * @param transmitRate
 * The transmit rate for the currently associated network on the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the Wi-Fi link quality changes.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypeLinkQualityDidChange event type
 * to register for link quality event notifications.
 * Use -[CDAWiFiInterface rssiValue] and -[CDAWiFiInterface transmitRate] to query the current RSSI and transmit rate, respectively.
 */
- (void)linkQualityDidChangeForWiFiInterfaceWithName:(NSString *)interfaceName rssi:(int)rssi transmitRate:(double)transmitRate;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the Wi-Fi operating mode changes.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypeModeDidChange event type
 * to register for interface mode event notifications.
 * Use -[CDAWiFiInterface interfaceMode] to query the current operating mode.
 */
- (void)modeDidChangeForWiFiInterfaceWithName:(NSString *)interfaceName;

/*!
 * @method
 *
 * @param interfaceName
 * The name of the Wi-Fi interface.
 *
 * @abstract
 * Invoked when the Wi-Fi interface scan cache is updated with new scan results.
 *
 * @discussion
 * Use -[CDAWiFiClient startMonitoringEventWithType:error:] with the CDAWiFiEventTypeScanCacheUpdated event type
 * to register for scan cache event notifications.
 * Use -[CDAWiFiInterface cachedScanResults] to query scan cache results from the last scan.
 */
- (void)scanCacheUpdatedForWiFiInterfaceWithName:(OFString *)interfaceName;

@end

/*!
 * @class
 *
 * @abstract
 * The interface to the Wi-Fi subsystem.
 *
 * @discussion
 * Provides access to all Wi-Fi interfaces and allows Wi-Fi clients to setup event notifications.
 *
 * CDAWiFiClient objects are heavy objects, therefore, clients of the CDAWiFi framework should use a single,
 * long-running instance rather than creating several short-lived instances.
 * For convenience, +[CDAWiFiClient sharedWiFiClient] can be used to return a singleton instance.
 *
 * The CDAWiFiClient object should be used to instantiate CDAWiFiInterface objects rather than using a CDAWiFiInterface
 * initializer directly.
 */

@interface CDAWiFiClient : OFObject

/*! @functiongroup Setting the Delegate */

/*!
 * @property
 *
 * @abstract
 * Sets the delegate to the specified object, which may implement CDAWiFiEventDelegate protocol for Wi-Fi event handling.
 *
 * @discussion
 * Clients may register for specific Wi-Fi events using -[CDAWiFiClient startMonitoringEventWithType:error:].
 */
@property(nonatomic, weak) id delegate;

/*! @functiongroup Getting a Wi-Fi Client */

/*!
 * @method
 *
 * @abstract
 * Returns the shared CDAWiFiClient instance. There is a single shared instance per process.
 */
+ (instancetype)sharedWiFiClient;

/*!
 * @method
 *
 * @abstract
 * Initializes a CDAWiFiClient object.
 */
- (instancetype)init;

/*! @functiongroup Getting a Wi-Fi Interface */

/*!
 * @method
 *
 * @abstract
 * Returns the CDAWiFiInterface object for the default Wi-Fi interface.
 */
- (CDAWiFiInterface *)interface;

/*!
 * @method
 *
 * @result
 * An NSArray of NSString objects corresponding to Wi-Fi interface names.
 *
 * @abstract
 * Returns the list of available Wi-Fi interface names (e.g. "en0").
 *
 * @discussion
 * If no Wi-Fi interfaces are available, this method will return an empty array.
 * Returns nil if an error occurs.
 */
+ (NSArray *)interfaceNames;

/*!
 * @method
 *
 * @param interfaceName
 * The name of an available Wi-Fi interface.
 *
 * @abstract
 * Get the CDAWiFiInterface object bound to the Wi-Fi interface with a specific interface name.
 *
 * @discussion
 * Use +[CDAWiFiClient interfaceNames] to get a list of available Wi-Fi interface names.
 * Returns a CDAWiFiInterface object for the default Wi-Fi interface if no interface name is specified.
 */
- (CDAWiFiInterface *)interfaceWithName:(NSString *)interfaceName;

/*!
 * @method
 *
 * @result
 * An NSArray of CDAWiFiInterface objects.
 *
 * @abstract
 * Returns all available Wi-Fi interfaces.
 *
 * @discussion
 * If no Wi-Fi interfaces are available, this method will return an empty array.
 * Returns nil if an error occurs.
 */
- (NSArray *)interfaces;

/*! @functiongroup Register for Wi-Fi Events */

/*!
 * @method
 *
 * @param type
 * A CDAWiFiEventType value.
 *
 * @param error
 * An NSError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Register for specific Wi-Fi event notifications.
 */
- (BOOL)startMonitoringEventWithType:(CDAWiFiEventType)type error:(out CDAError **)error;

/*!
 * @method
 *
 * @param type
 * A CDAWiFiEventType value.
 *
 * @param error
 * An NSError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Unregister for specific Wi-Fi event notifications.
 */
- (BOOL)stopMonitoringEventWithType:(CDAWiFiEventType)type error:(out CDAError **)error;

/*!
 * @method
 *
 * @param error
 * An NSError object passed by reference, which upon return will contain the error if an error occurs.
 * This parameter is optional.
 *
 * @result
 * A BOOL value indicating whether or not an error occurred. YES indicates no error occurred.
 *
 * @abstract
 * Unregister for all Wi-Fi event notifications.
 */
- (BOOL)stopMonitoringAllEventsAndReturnError:(out CDAError **)error;

@end
