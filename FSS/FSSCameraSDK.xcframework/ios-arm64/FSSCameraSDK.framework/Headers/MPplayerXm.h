//
//  MPplayerXm.h
//  FSSCameraSDK
//
//  Created by Minh Phuong Nguyen on 31/10/2023.
//  Copyright © 2023 Nguyễn Minh Phương. All rights reserved.
//

@protocol MPplayerXmDelegate <NSObject>

@optional

-(void) onErrorStartPlay;
-(void) onErrorPlaying;
- (void) mpOnReconnectPlay;

- (void) startPlayVideoTimeResult:(NSInteger)startTime Time:(NSInteger)time TimeRight:(NSString *)timeRight FirstParam:(NSInteger)firstParam;

- (void) mpResultPlaySdCard:(int)paraStart withPlay:(int)paraPlay withEnd:(int)paraEnd playTime:(NSInteger)playTime stopTime:(NSInteger)stopTime TimeLeft:(NSString *)timeLeft TimeRight:(NSString*)timeRight;
- (void) playVideoInfoResult:(NSInteger)playTime stopTime:(NSInteger)stopTime TimeLeft:(NSString *)timeLeft TimeRight:(NSString*)timeRight;

-(void) onStopPlay:(int) result;
-(void) onPlayEnd;

-(void) onPausePlay:(int) result isPause:(bool) isPause;
-(void) onPlaySpeed: (int) speed;

- (void) mpSnapShotResult:(NSString *)path result:(NSInteger)result;

// download
-(void) mpDownloadThumbAnrResult:(NSDictionary *)dict isSuccess:(BOOL) isSuccess;


@end


#import <Foundation/Foundation.h>
#import "FunMsgListener.h"
#import "FunSDK/FunSDK.h"
#import "CYGLKView.h"
#import "RecordInfo.h"
#import "CLouldVideoResource.h"
#import "MPplayerModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MPplayerXm : FunMsgListener

@property (nonatomic, weak) id <MPplayerXmDelegate> delegate;
@property (nonatomic, assign) FUN_HANDLE player;
@property (nonatomic, assign) CYGLKView* renderWnd;
@property (nonatomic, assign) SDKplayerType playerType;
@property (nonatomic, assign) MPVideoState videoState;

-(void) playFullRecordWithLink:(NSString *) link;
-(void) playAnrFile:(RecordInfo *) obj;
- (void)playStreamByUrl:(NSString *) link;
-(void) stop;
-(void) pause;
-(void) continuePlay;
-(void) configSound:(int) soundValue;
-(void) setSpeed:(int)speed;
-(void) seekToTime:(NSInteger) sliderValue;
-(void) snapImage:(NSString *)path;

-(void) motionInitWithSerial: (NSString *) serial;
-(void) motionPlayVideo:(NSDate *)date toDate:(NSDate *)toDate;

- (void) downloadThumbAnr:(RecordInfo*)record serial:(NSString*) cameraSerial seq:(NSInteger) seq picFilePath:(NSString *) path;
- (void) stopDownload;
@end

NS_ASSUME_NONNULL_END
