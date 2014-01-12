//
//  UIApplication+Permissions.h
//  UIApplication+Permissions Sample
//
//  Created by Jack Rostron on 12/01/2014.
//  Copyright (c) 2014 Rostron. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    kPermissionTypeBluetoothLE,
    kPermissionTypeCalendar,
    kPermissionTypeContacts,
    kPermissionTypeLocation,
    kPermissionTypeMicrophone,
    kPermissionTypeMotion,
    kPermissionTypePhotos,
    kPermissionTypeReminders,
} kPermissionType;

typedef enum {
    kPermissionAccessDenied, //User has rejected feature
    kPermissionAccessGranted, //User has accepted feature
    kPermissionAccessRestricted, //Blocked by parental controls or system settings
    kPermissionAccessUnknown, //Cannot be determined
    kPermissionAccessUnsupported, //Device doesn't support this - e.g Core Bluetooth
    kPermissionAccessMissingFramework, //Developer didn't import the required framework to the project
} kPermissionAccess;

@interface UIApplication (Permissions)

//Check permission of service. Cannot check microphone or motion without asking user for permission
+(kPermissionAccess)hasAccessToBluetoothLE;
+(kPermissionAccess)hasAccessToCalendar;
+(kPermissionAccess)hasAccessToContacts;
+(kPermissionAccess)hasAccessToLocation;
+(kPermissionAccess)hasAccessToPhotos;
+(kPermissionAccess)hasAccessToReminders;

//Request permission with callback
+(void)requestAccessToBluetoothLEWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
+(void)requestAccessToCalendarWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
+(void)requestAccessToContactsWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
+(void)requestAccessToLocationWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
+(void)requestAccessToMicrophoneWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
+(void)requestAccessToMotionWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
+(void)requestAccessToPhotosWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
+(void)requestAccessToRemindersWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;

@end
