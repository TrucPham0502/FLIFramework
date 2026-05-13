//
//  MPplayerWrap.h
//  FSSCameraSDK
//
//  Created by Minh Phuong Nguyen on 31/10/2023.
//  Copyright © 2023 Nguyễn Minh Phương. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CYGLKView.h"
#import "RecordInfo.h"
#import "MPplayerModel.h"
#import "MPplayerWrapDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface MPplayerWrap : UIView

@property (nonatomic, weak) id <MPplayerWrapDelegate> delegate;
-(void) initUIAndPlayer;
-(void) initWithPlayerType:(SDKplayerType)mpType withCmrSerial:(NSString *)serial;

-(void) playFullRecordWithLink:(NSString *) link;
-(void) mpPlayStreamWithLink:(NSString *) link;
-(void) playAnrFile:(RecordInfo *) anr;
-(void) stop;
-(void) pause;
-(void) continuePlay;
-(void) setSpeed:(int)speed;
-(void) configSound:(int) soundValue;
-(void) seekToTime:(NSInteger) sliderValue;
-(void) snapImage:(NSString *)path;
-(MPVideoState) getCurrentState;

//TODO: motion
-(void) motionSearchVideo:(NSDate *)fromDate toDate:(NSDate*)toDate deviceSerial:(NSString *) serial;

-(void) motionPlayVideo:(NSDate *)fromDate toDate:(NSDate *)toDate;

//TODO: download
-(void) downloadThumbAnr:(RecordInfo*)info serial:(NSString*)cameraSerial seq:(NSInteger) seq picFilePath:(NSString *) path;
- (void) stopDownload;


@end


NS_ASSUME_NONNULL_END
