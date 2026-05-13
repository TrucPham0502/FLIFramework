//
//  MPFileConfigWrapDelegate.h
//  FSSCameraSDK
//
//  Created by Minh Phuong Nguyen on 26/10/2023.
//

#ifndef MPFileConfigWrapDelegate_h
#define MPFileConfigWrapDelegate_h

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@protocol MPFileConfigWrapDelegate <NSObject>

@optional

-(void) mpGetVideoResult:(NSInteger)result withRecordArray:(NSMutableArray *) arrayFile;
-(void) mpResultGetViByTime:(NSInteger)result;
- (void)tpGetMonthVideoDateResult:(NSInteger)result data:(NSMutableArray *)data;
- (void)downloadCloudVideoStartResult:(NSInteger)result;
- (void)downloadCloudVideoProgress:(float)progress totalSize:(float)totalSize lastProgress:(NSInteger)lastProgress;
- (void)downloadCloudVideoComplete:(NSInteger)result path:(NSString*)path;

-(void)getCmrStorageInfoCallback:(BOOL) isSuccess withTotalStorage:(float) totalMB withFreeStorage:(float) freeMB;
-(void) clearCmrStorageResult:(BOOL) isSuccess;

@end

#endif
NS_ASSUME_NONNULL_END

