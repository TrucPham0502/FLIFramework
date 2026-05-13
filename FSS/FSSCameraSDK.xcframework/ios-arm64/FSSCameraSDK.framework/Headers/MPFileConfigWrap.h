//
//  MPFileConfigWrap.h
//  FSSCameraSDK
//
//  Created by Minh Phuong Nguyen on 26/10/2023.
//  Copyright © 2023 Nguyễn Minh Phương. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RecordInfo.h"
#import "MPplayerModel.h"
#import "MPFileConfigWrapDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface MPFileConfigWrap: NSObject

+ (MPFileConfigWrap *) shared;

@property (nonatomic, weak) id <MPFileConfigWrapDelegate> delegate;

@property (nonatomic, assign) RecordInfo *anrObj;

@property (nonatomic, assign) NSInteger sdStH;
@property (nonatomic, assign) NSInteger sdStM;
@property (nonatomic, assign) NSInteger sdStS;
@property (nonatomic, assign) NSDate *sdStD;

@property (nonatomic, assign) NSInteger sdEnH;
@property (nonatomic, assign) NSInteger sdEnM;
@property (nonatomic, assign) NSInteger sdEnS;
@property (nonatomic, assign) NSDate *sdEnD;

-(void) mpGetVideoBetweenTimeRange:(SDKConfigType) type;
-(void) mpGetSdByTime;
- (void)tpGetMonthVideoDate:(NSDate *)date withType:(SDKConfigType) type seq:(int)seq;

-(void)downloadCloudVideoFile:(NSString *)serial date:(NSDate *)date toDate:(NSDate *)toDate fileName:(NSString *)fileName;
- (void)downloadAnrFile:(NSString *)serial record:(RecordInfo *)record fileName:(NSString *)fileName;

- (void)stopDownloadFile;

-(void)getCmrStorageInfo;
-(void)clearCmrStorage;

@end

NS_ASSUME_NONNULL_END
