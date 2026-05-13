//
//  LiveStreamView.h
//  FunSDKDemo
//
//  Created by Pham Chi Hieu on 10/25/19.
//  Copyright © 2019 Pham Chi Hieu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PlayView.h"
#import "JHRotatoUtil.h"
#import "ChannelObject.h"
#import "LiveStreamViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface LiveStreamView : PlayView <UIGestureRecognizerDelegate>
@property (nonatomic, weak) id <LiveStreamViewDelegate> delegate;

@property (nonatomic,strong)UITapGestureRecognizer *singleTap;
@property (nonatomic,strong)UISwipeGestureRecognizer *swipeleft;
@property (nonatomic,strong)UISwipeGestureRecognizer *swiperight;
@property (nonatomic,strong)UISwipeGestureRecognizer *swipeup;
@property (nonatomic,strong)UISwipeGestureRecognizer *swipedown;
@property (nonatomic) UIInterfaceOrientation lastOrientation;
@property (nonatomic) bool isRecording;
@property (nonatomic, assign) CGRect playViewBound;
@property (nonatomic) BOOL isHighPixel;
@property (nonatomic) BOOL bIsSound;
@property (nonatomic) BOOL isSplitMode;
@property (nonatomic) int index;
@property (nonatomic) NSString *serial;
@property (nonatomic) BOOL isStreaming;
- (void)createPlayView;

/// Description lamnhs xoá sự kiện single tap vì grid view camera không cần dùng. để khỏi đụng sự kiện click
- (void)removeSingleTap;

- (void)initDataSource:(int)stream;

/// Description lamnhs func này sử dụng cho grid view livestream
/// @param channelObject channelObject description
/// @param stream stream description
- (void)initDataSource:(ChannelObject*) channelObject stream:(int)stream;

- (void)startRealPlay;
- (void)stopRealPlay;
- (void)stop;
- (int)pause;
- (int)resume;
- (NSString*)startRecord;
- (void)stopRecord;
//- (NSString*)snapImage:(UIImage *)image;
/// Description lamnhs chụp ảnh sử dụng sdk
- (NSString*)snapImageSDK;
//- (NSString*)snapImageWhenTapButtonBack:(UIImage *)image serial:(NSString*)serial;
/// Description lamnhs chụp ảnh sử dụng sdk
- (NSString*)snapImageWhenTapButtonBackSDK:(NSString*)serial phone:(NSString*)phone;
- (void)changeStreamType:(int)stream;
// TODO: Swipe Camera
- (void)swipeCamera:(int)direction;
- (void)setupSwipeGesture;
- (void)removeSwipeGesture;
- (void)fullScreenMode;

-(void) mpSnapImage:(NSString *)path nSeq:(int) nSeq;
-(void) mpStartRecord:(NSString *)path;
-(void) mpConfigSound:(int)soundValue;

-(void)controZStartlPTAction:(int)type;
-(void)controZStopIPTAction:(int)type;
- (void)startDouTalk;
- (void)stopDouTalk;
//
@end


NS_ASSUME_NONNULL_END
