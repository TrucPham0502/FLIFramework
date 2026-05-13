//
//  MPplayerWrapDelegate.h
//  FSSCameraSDK
//
//  Created by Minh Phuong Nguyen on 31/10/2023.
//  Copyright © 2023 Nguyễn Minh Phương. All rights reserved.
//


#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@protocol MPplayerWrapDelegate <NSObject>

@optional

// play info
-(void) onErrorStartPlay;
-(void) onErrorPlaying;
-(void) mpOnReconnectPlay;

-(void) startPlayVideoTimeResult:(NSInteger)startTime Time:(NSInteger)time TimeRight:(NSString *)timeRight FirstParam:(NSInteger)firstParam;

-(void) mpResultPlaySdCard:(int)paraStart withPlay:(int)paraPlay withEnd:(int)paraEnd playTime:(NSInteger)playTime stopTime:(NSInteger)stopTime TimeLeft:(NSString *)timeLeft TimeRight:(NSString*)timeRight;
-(void) playVideoInfoResult:(NSInteger)playTime stopTime:(NSInteger)stopTime TimeLeft:(NSString *)timeLeft TimeRight:(NSString*)timeRight;

-(void) onStopPlay:(int) result;
-(void) onPlayEnd;

-(void) onPausePlay:(int) result isPause:(bool) isPause;
-(void) onPlaySpeed: (int) speed;

-(void) mpSnapShotResult:(NSString *)path result:(NSInteger)result;

// motion list

-(void) motionSearchVideoResult: (nullable NSMutableArray *) motionList;

//download

-(void) mpDownloadThumbAnrResult:(NSDictionary<NSString*, NSString*> *)dict isSuccess:(BOOL) isSuccess;



@end


NS_ASSUME_NONNULL_END
