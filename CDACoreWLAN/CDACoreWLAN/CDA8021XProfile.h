//
//  CDA8021XProfile.h
//  CDACoreWLAN
//
//  Created by Alsey Coleman Miller on 2/28/15.
//  Copyright (c) 2015 ColemanCDA. All rights reserved.
//

#import <ObjFW/ObjFW.h>
#import <CoreWLAN/CoreWLAN.h>

@interface CDA8021XProfile: OFObject

#pragma mark - Class Methods

+ (NSArray *)allUser8021XProfiles;
+ (instancetype)profile;

#pragma mark - Properties

@property (nonatomic) BOOL alwaysPromptForPassword;

@property (nonatomic, copy) OFString *password;

@property (nonatomic, copy) OFString *ssid;

@property (nonatomic, copy) OFString *userDefinedName;

@property (nonatomic, copy) OFString *password;


#pragma mark - Methods

- (BOOL)isEqualToProfile:(CDA8021XProfile *) profile;


@end
