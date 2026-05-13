//
//  LiveStreamViewDelegate.h
//  FSSCameraSDK
//
//  Created by LamMacM1 on 5/16/22.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class LiveStreamView;
@protocol LiveStreamViewDelegate <NSObject>
@optional
    //callback dành cho grid livestream
    -(void)didTapScreen:(LiveStreamView*)cameraLiveStreamView;
    -(void)changeQuality:(LiveStreamView*)cameraLiveStreamView;

/// Description kết quả quay phim thành công
/// @param result result description
/// @param path path description
    -(void)stopRecordResult:(LiveStreamView*)cameraLiveStreamView result:(int)result path:(NSString*)path;

    -(void)startRecordResult:(LiveStreamView*)cameraLiveStreamView result:(int)result path:(NSString*)path;


/// Description
/// @param result result description
/// @param path path description
/// @param time time description thời gian của hình ảnh
    -(void)snapImageResult:(LiveStreamView*)cameraLiveStreamView result:(int)result path:(NSString*)path nSeq:(int) nSeq;
    

    -(void)stopRecordVideo:(LiveStreamView*)cameraLiveStreamView result:(BOOL)result;
    -(void)startedPlay:(LiveStreamView*)cameraLiveStreamView result:(int)result dssResult:(int)dssResult;//start livestream thành công
    -(void)startedPlayInfo:(LiveStreamView*)cameraLiveStreamView;
    -(void)errorStartPlay:(LiveStreamView*)cameraLiveStreamView;

    -(void)onReconnectPlay:(LiveStreamView*)cameraLiveStreamView;
    -(void)onStopPlay:(LiveStreamView*)cameraLiveStreamView;

    - (void) talkBackControlStart:(int)result;
    - (void) talkBackControlStop:(int)result;
    - (void) talkBackControlError:(int)param1;

    -(void)frameLoss:(LiveStreamView*)cameraLiveStreamView;
-(void)bitrate:(LiveStreamView*)cameraLiveStreamView bitrate:(NSString*)bitrate;
@end
NS_ASSUME_NONNULL_END
