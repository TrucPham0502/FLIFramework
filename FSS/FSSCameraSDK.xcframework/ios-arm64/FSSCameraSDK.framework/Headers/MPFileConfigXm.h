//
//  MPFileConfigXm.h
//  FSSCameraSDK
//
//  Created by Minh Phuong Nguyen on 26/10/2023.
//

@protocol MPFileConfigXmDelegate <NSObject>

@optional
-(void)resultGetVideoByFile:(NSInteger)result withFileArray:(NSMutableArray*)anrList;
-(void)resultGetVideoByTime:(NSInteger)result;
-(void)tpGetMonthVideoDateResult:(NSInteger) result data:(NSMutableArray*) data;
- (void)downloadCloudVideoStartResult:(NSInteger)result;
- (void)downloadCloudVideoProgress:(float)progress totalSize:(float)totalSize lastProgress:(NSInteger)lastProgress;
- (void)downloadCloudVideoComplete:(NSInteger)result path:(NSString*)path;
-(void)getCmrStorageInfoCallback:(BOOL) isSuccess withTotalStorage:(float) totalMB withFreeStorage:(float) freeMB;
-(void)clearCmrStorageResult:(BOOL) isSuccess;

@end

#import <Foundation/Foundation.h>
#import "MPplayerModel.h"
#import "RecordInfo.h"
#import "ConfigControllerBase.h"
#import "FunSDK/FunSDK.h"
#import "RecordInfo.h"


@interface MPFileConfigXm: ConfigControllerBase

+ (instancetype)getInstance;

@property (nonatomic, weak) id <MPFileConfigXmDelegate> delegate;
@property (nonatomic, assign) RecordInfo *anrObj;
@property (nonatomic, assign) FUN_HANDLE downloader;

-(void)mpCustomizeQueryByFile:(MPdateInfo)stInfo endTime:(MPdateInfo )endInfo withType:(SDKConfigType) type;

-(void) mpGetViCustomAtTime:(RecordInfo *)obj;

- (void)tpGetMonthVideoDate:(NSDate *)date withType:(SDKConfigType) type seq:(int)seq;

- (void)downloadCloudVideoFile:(NSString *)serial date:(NSDate *)date toDate:(NSDate *)toDate fileName:(NSString *)fileName;
- (void)downloadAnrFile:(NSString *)serial record:(RecordInfo *)record fileName:(NSString *)fileName;

- (void)stopDownloadFile;

-(void)mpGetCmrStorageInfo;
-(void)mpClearCmrStorage;


@end
