//
//  CDAWiFiTypes.h
//  CDAWiFi
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

/*!
 * @typedef CWErr
 *
 * @abstract Error codes corresponding to the CWErrorDomain domain.
 *
 * @constant CDAWiFiNoErr
 * Success.
 *
 * @constant CDAWiFiEAPOLErr
 * EAPOL-related error.
 *
 * @constant CDAWiFiInvalidParameterErr
 * Parameter error.
 *
 * @constant CDAWiFiNoMemoryErr
 * Memory allocation failed.
 *
 * @constant CDAWiFiUnknownErr
 * Unexpected error condition encountered for which no error code exists.
 *
 * @constant CDAWiFiNotSupportedErr
 * Operation not supported.
 *
 * @constant CDAWiFiInvalidFormatErr
 * Invalid protocol element field detected.
 *
 * @constant CDAWiFiTimeoutErr
 * Operation timed out.
 *
 * @constant CDAWiFiUnspecifiedFailureErr
 * Access point did not specify a reason for authentication/association failure.
 *
 * @constant CDAWiFiUnsupportedCapabilitiesErr
 * Access point cannot support all requested capabilities.
 *
 * @constant CDAWiFiReassociationDeniedErr
 * Reassociation was denied because the access point was unable to determine that an association exists.
 *
 * @constant CDAWiFiAssociationDeniedErr
 * Association was denied for an unspecified reason.
 *
 * @constant CDAWiFiAuthenticationAlgorithmUnsupportedErr
 * Specified authentication algorithm is not supported.
 *
 * @constant CDAWiFiInvalidAuthenticationSequenceNumberErr
 * Authentication frame received with an authentication sequence number out of expected sequence.
 *
 * @constant CDAWiFiChallengeFailureErr
 * Authentication was rejected because of a challenge failure.
 *
 * @constant CDAWiFiAPFullErr
 * Access point is unable to handle another associated station.
 *
 * @constant CDAWiFiUnsupportedRateSetErr
 * Interface does not support all of the rates in the basic rate set of the access point.
 *
 * @constant CDAWiFiShortSlotUnsupportedErr
 * Association denied because short slot time option is not supported by requesting station.
 *
 * @constant CDAWiFiDSSSOFDMUnsupportedErr
 * Association denied because DSSS-OFDM is not supported by requesting station.
 *
 * @constant CDAWiFiInvalidInformationElementErr
 * Invalid information element included in association request.
 *
 * @constant CDAWiFiInvalidGroupCipherErr
 * Invalid group cipher requested.
 *
 * @constant CDAWiFiInvalidPairwiseCipherErr
 * Invalid pairwise cipher requested.
 *
 * @constant CDAWiFiInvalidAKMPErr
 * Invalid authentication selector requested.
 *
 * @constant CDAWiFiUnsupportedRSNVersionErr
 * Invalid WPA/WPA2 version specified.
 *
 * @constant CDAWiFiInvalidRSNCapabilitiesErr
 * Invalid RSN capabilities specified in association request.
 *
 * @constant CDAWiFiCipherSuiteRejectedErr
 * Cipher suite rejected due to network security policy.
 *
 * @constant CDAWiFiInvalidPMKErr
 * PMK rejected by the access point.
 *
 * @constant CDAWiFiSupplicantTimeoutErr
 * WPA/WPA2 handshake timed out.
 *
 * @constant CDAWiFiHTFeaturesNotSupportedErr
 * Association was denied because the requesting station does not support HT features.
 *
 * @constant CDAWiFiPCOTransitionTimeNotSupportedErr
 * Association was denied because the requesting station does not support the PCO transition time required by the AP.
 *
 * @constant CDAWiFiReferenceNotBoundErr
 * No interface is bound to the CWInterface object.
 *
 * @constant CDAWiFiIPCFailureErr
 * Error communicating with a separate process.
 *
 * @constant CDAWiFiOperationNotPermittedErr
 * Calling process does not have permission to perform this operation.
 *
 * @constant CDAWiFiErr
 * Generic error, no specific error code exists to describe the error condition.
 */
/* Error codes corresponding to the CDAWiFiErrorDomain domain. */
typedef enum
{
    CDAWiFiNoError                                      = 0,
    CDAWiFiEAPOLError									= 1,
    CDAWiFiInvalidParameterError						= -3900,
    CDAWiFiNoMemoryError								= -3901,
    CDAWiFiUnknownError                                 = -3902,
    CDAWiFiNotSupportedError							= -3903,
    CDAWiFiInvalidFormatError							= -3904,
    CDAWiFiTimeoutError                                 = -3905,
    CDAWiFiUnspecifiedFailureError                      = -3906,
    CDAWiFiUnsupportedCapabilitiesError                 = -3907,
    CDAWiFiReassociationDeniedError                     = -3908,
    CDAWiFiAssociationDeniedError						= -3909,
    CDAWiFiAuthenticationAlgorithmUnsupportedError      = -3910,
    CDAWiFiInvalidAuthenticationSequenceNumberError     = -3911,
    CDAWiFiChallengeFailureError						= -3912,
    CDAWiFiAPFullError                                  = -3913,
    CDAWiFiUnsupportedRateSetError                      = -3914,
    CDAWiFiShortSlotUnsupportedError					= -3915,
    CDAWiFiDSSSOFDMUnsupportedError                     = -3916,
    CDAWiFiInvalidInformationElementError				= -3917,
    CDAWiFiInvalidGroupCipherError                      = -3918,
    CDAWiFiInvalidPairwiseCipherError					= -3919,
    CDAWiFiInvalidAKMPError                             = -3920,
    CDAWiFiUnsupportedRSNVersionError					= -3921,
    CDAWiFiInvalidRSNCapabilitiesError                  = -3922,
    CDAWiFiCipherSuiteRejectedError                     = -3923,
    CDAWiFiInvalidPMKError                              = -3924,
    CDAWiFiSupplicantTimeoutError						= -3925,
    CDAWiFiHTFeaturesNotSupportedError                  = -3926,
    CDAWiFiPCOTransitionTimeNotSupportedError			= -3927,
    CDAWiFiReferenceNotBoundError						= -3928,
    CDAWiFiIPCFailureError                              = -3929,
    CDAWiFiOperationNotPermittedError					= -3930,
    
    /* Generic error, no specific error code exists to describe the error condition. */
    CDAWiFiGenericError									= -3931,
} CDAWiFiError;

/*!
 * @typedef CWPHYMode
 *
 * @abstract Type describing the IEEE 802.11 physical layer mode.
 *
 * @constant CDAWiFiPHYModeNone
 *
 * @constant CDAWiFiPHYMode11a
 * IEEE 802.11a physical layer mode.
 *
 * @constant CDAWiFiPHYMode11b
 * IEEE 802.11b physical layer mode.
 *
 * @constant CDAWiFiPHYMode11g
 * IEEE 802.11g physical layer mode.
 *
 * @constant CDAWiFiPHYMode11n
 * IEEE 802.11n physical layer mode.
 *
 * @constant CDAWiFiPHYMode11ac
 * IEEE 802.11ac physical layer mode.
 */
typedef enum
{
    CDAWiFiPHYModeNone		= 0,
    CDAWiFiPHYMode11a		= 1,
    CDAWiFiPHYMode11b		= 2,
    CDAWiFiPHYMode11g		= 3,
    CDAWiFiPHYMode11n		= 4,
    CDAWiFiPHYMode11ac      = 5,
} CDAWiFiPHYMode;

/*!
 * @typedef CWInterfaceMode
 *
 * @abstract Wi-Fi interface operating modes returned by -[CWInterface interfaceMode].
 *
 * @constant CDAWiFiInterfaceModeNone
 * Interface is not in any mode.
 *
 * @constant CDAWiFiInterfaceModeStation
 * Interface is participating in an infrastructure network as a non-AP station.
 *
 * @constant CDAWiFiInterfaceModeIBSS
 * Interface is participating in an IBSS network.
 *
 * @constant CDAWiFiInterfaceModeHostAP
 * Interface is participating in an infrastructure network as an access point.
 */
typedef enum
{
    CDAWiFiInterfaceModeNone			= 0,
    CDAWiFiInterfaceModeStation			= 1,
    CDAWiFiInterfaceModeIBSS			= 2,
    CDAWiFiInterfaceModeHostAP			= 3,
} CDAWiFiInterfaceMode;

/*!
 * @typedef CWSecurity
 *
 * @abstract Wi-Fi security types.
 *
 * @constant CDAWiFiSecurityNone
 * Open System authentication.
 *
 * @constant CDAWiFiSecurityWEP
 * WEP security.
 *
 * @constant CDAWiFiSecurityWPAPersonal
 * WPA Personal authentication.
 *
 * @constant CDAWiFiSecurityWPAPersonalMixed
 * WPA/WPA2 Personal authentication.
 *
 * @constant CDAWiFiSecurityWPA2Personal
 * WPA2 Personal authentication.
 *
 * @constant CDAWiFiSecurityDynamicWEP
 * Dynamic WEP security.
 *
 * @constant CDAWiFiSecurityWPAEnterprise
 * WPA Enterprise authentication.
 *
 * @constant CDAWiFiSecurityWPAEnterpriseMixed
 * WPA/WPA2 Enterprise authentication.
 *
 * @constant CDAWiFiSecurityWPA2Enterprise
 * WPA2 Enterprise authentication.
 *
 * @constant CDAWiFiSecurityUnknown
 * Unknown security type.
 */
typedef enum
{
    CDAWiFiSecurityNone                 = 0,
    CDAWiFiSecurityWEP                  = 1,
    CDAWiFiSecurityWPAPersonal          = 2,
    CDAWiFiSecurityWPAPersonalMixed     = 3,
    CDAWiFiSecurityWPA2Personal         = 4,
    CDAWiFiSecurityPersonal             = 5,
    CDAWiFiSecurityDynamicWEP           = 6,
    CDAWiFiSecurityWPAEnterprise        = 7,
    CDAWiFiSecurityWPAEnterpriseMixed   = 8,
    CDAWiFiSecurityWPA2Enterprise       = 9,
    CDAWiFiSecurityEnterprise           = 10,
    CDAWiFiSecurityUnknown              = INTMAX_MAX,
} CDAWiFiSecurity;

/*!
 * @typedef CWIBSSModeSecurity
 *
 * @abstract IBSS security types used in -[CWInterface startIBSSModeWithSSID:security:channel:password:error:].
 *
 * @constant CDAWiFiIBSSModeSecurityNone
 * Open System authentication.
 *
 * @constant CDAWiFiIBSSModeSecurityWEP40
 * WEP security.
 *
 * @constant CDAWiFiIBSSModeSecurityWEP104
 * WPA Personal authentication.
 */
typedef enum
{
    CDAWiFiIBSSModeSecurityNone         = 0,
    CDAWiFiIBSSModeSecurityWEP40		= 1,
    CDAWiFiIBSSModeSecurityWEP104       = 2,
} CDAWiFiIBSSModeSecurity;

/*!
 * @typedef CWChannelWidth
 *
 * @abstract Channel width values returned by -[CWChannel channelWidth].
 *
 * @constant CDAWiFiChannelWidthUnknown
 * Unknown channel width.
 *
 * @constant CDAWiFiChannelWidth20MHz
 * 20MHz channel width.
 *
 * @constant CDAWiFiChannelWidth40MHz
 * 40MHz channel width.
 *
 * @constant CDAWiFiChannelWidth80MHz
 * 80MHz channel width.
 *
 * @constant CDAWiFiChannelWidth160MHz
 * 160MHz channel width.
 */
typedef enum
{
    CDAWiFiChannelWidthUnknown	= 0,
    CDAWiFiChannelWidth20MHz	= 1,
    CDAWiFiChannelWidth40MHz	= 2,
    CDAWiFiChannelWidth80MHz	= 3,
    CDAWiFiChannelWidth160MHz	= 4,
} CDAWiFiChannelWidth;

/*!
 * @typedef CWChannelBand
 *
 * @abstract Channel band values returned by -[CWChannel channelBand].
 *
 * @constant CDAWiFiChannelBandUnknown
 * Unknown channel band.
 *
 * @constant CDAWiFiChannelBand2GHz
 * 2.4GHz channel band.
 *
 * @constant CDAWiFiChannelBand5GHz
 * 5GHz channel band.
 */
typedef enum
{
    CDAWiFiChannelBandUnknown	= 0,
    CDAWiFiChannelBand2GHz		= 1,
    CDAWiFiChannelBand5GHz		= 2,
} CDAWiFiChannelBand;

/*!
 * @typedef CWCipherKeyFlags
 *
 * @abstract Cipher key flags used in -[CWInterface setWEPKey:flags:index:error:].
 *
 * @constant CDAWiFiCipherKeyFlagsNone
 * Open System authentication.
 *
 * @constant CDAWiFiCipherKeyFlagsUnicast
 * Cipher key will be used for unicast packets.
 *
 * @constant CDAWiFiCipherKeyFlagsMulticast
 * Cipher key will be used for multicast packets.
 *
 * @constant CDAWiFiCipherKeyFlagsTx
 * Cipher key will be used for packets sent from the interface.
 *
 * @constant CDAWiFiCipherKeyFlagsRx
 * Cipher key will be used for packets received by the interface.
 */
typedef enum
{
    CDAWiFiCipherKeyFlagsNone			= 0,
    CDAWiFiCipherKeyFlagsUnicast		= (1UL << 1),
    CDAWiFiCipherKeyFlagsMulticast		= (1UL << 2),
    CDAWiFiCipherKeyFlagsTx				= (1UL << 3),
    CDAWiFiCipherKeyFlagsRx				= (1UL << 4),
} CDAWiFiCipherKeyFlags;

/*!
 * @typedef CWKeychainDomain
 *
 * @abstract Keychain domain types used by CoreWLAN keychain methods.
 *
 * @constant CDAWiFiKeychainDomainNone
 * No keychain domain specified.
 *
 * @constant CDAWiFiKeychainDomainUser
 * The user keychain domain. If iCloud Keychain is enabled, the iCloud keychain is the user keychain.
 *
 * @constant CDAWiFiKeychainDomainSystem
 * The system keychain domain.
 */
typedef enum
{
    CDAWiFiKeychainDomainNone       = 0,
    CDAWiFiKeychainDomainUser       = 1,
    CDAWiFiKeychainDomainSystem     = 2,
} CDAWiFiKeychainDomain;

/*!
 * @typedef CWEventType
 *
 * @abstract Wi-Fi event types used in -[CWWiFiClient startMonitoringEventWithType:error:].
 *
 * @constant CWEventTypeNone
 * No event type specified.
 *
 * @constant CWEventTypePowerDidChange
 * Posted when the power state of any Wi-Fi interface changes.
 *
 * @constant CWEventTypeSSIDDidChange
 * Posted when the current SSID of any Wi-Fi interface changes.
 *
 * @constant CWEventTypeBSSIDDidChange
 * Posted when the current BSSID of any Wi-Fi interface changes.
 *
 * @constant CWEventTypeCountryCodeDidChange
 * Posted when the adopted country code of any Wi-Fi interface changes.
 *
 * @constant CWEventTypeLinkDidChange
 * Posted when the link state for any Wi-Fi interface changes.
 *
 * @constant CWEventTypeLinkQualityDidChange
 * Posted when the RSSI or transmit rate for any Wi-Fi interface changes.
 *
 * @constant CWEventTypeModeDidChange
 * Posted when the operating mode of any Wi-Fi interface changes.
 *
 * @constant CWEventTypeScanCacheUpdated
 * Posted when the scan cache of any Wi-Fi interface is updated with new scan results.
 *
 * @constant CWEventTypeUnknown
 * Unknown event type.
 */
typedef enum
{
    CDAWiFiEventTypeNone                     = 0,
    CDAWiFiEventTypePowerDidChange           = 1,
    CDAWiFiEventTypeSSIDDidChange            = 2,
    CDAWiFiEventTypeBSSIDDidChange           = 3,
    CDAWiFiEventTypeCountryCodeDidChange     = 4,
    CDAWiFiEventTypeLinkDidChange            = 5,
    CDAWiFiEventTypeLinkQualityDidChange     = 6,
    CDAWiFiEventTypeModeDidChange            = 7,
    CDAWiFiEventTypeScanCacheUpdated         = 8,
    CDAWiFiEventTypeUnknown                  = INTMAX_MAX
} CDAWiFiEventType;

