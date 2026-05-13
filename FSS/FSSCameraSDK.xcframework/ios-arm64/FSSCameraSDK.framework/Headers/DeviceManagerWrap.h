//
//  DeviceManagerWrap.h
//  FunSDKDemo
//
//  Created by Pham Chi Hieu on 10/25/19.
//  Copyright © 2019 Pham Chi Hieu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ChannelObject.h"
#import "DeviceObject.h"
#import "DeviceManagerWrapDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface DeviceManagerWrap : NSObject
+ (DeviceManagerWrap *) shared;
@property (nonatomic, weak) id <DeviceManagerWrapDelegate> delegate;
@property (nonatomic) NSString *token;
- (void)logoutCamera:(NSString *)devMac;
- (void)deleteDeviceWithDevMac:(NSString *)devMac;
- (void)addDeviceByDeviseSerialnumber:(NSString*)serialNumber deviceName:(NSString *)deviceName devType:(int)type;//通过输入设备序列号添加
- (void)addDeviceByDeviseSerialnumber:(NSString*)serialNumber deviceName:(NSString *)deviceName devType:(int)type seq:(int)seq;
- (NSMutableArray*)currentDeviceArray;
- (void)clearDeviceArray;
- (void)changeDevicePsw:(NSString *)devMac loginName:(NSString *)name password:(NSString *)psw;
- (void)getDeviceChannel:(NSString *)devMac seq:(int)seq;
- (void)getDeviceChannel:(NSString *)devMac;
- (void)cleanSelectChannel;
- (void)setSelectChannel:(ChannelObject *)channel;
- (void)startConfigWithSSID:(NSString*)ssid password:(NSString*)password timeout:(int) timeOut;
- (void)stopConfig;
- (void)stopTimer;
- (void)LinkAlarm:(NSString *)deviceMac DeviceName:(NSString *)devName Username:(NSString *)username Password:(NSString *)password;
- (nullable DeviceObject *)GetDeviceObjectBySN:(NSString *)devSN;
- (NSString *)devThumbnailFile:(NSString*)devId andChannle:(int)channle;
-(void)getdeviceState:(NSString*)deviceMac seq:(int)seq;
// MARK - Video Cloud
- (void)initDelegateVideoConfig;
- (NSMutableArray*)getVideoTimeArray;
- (NSMutableArray*)getVideoArray;
- (void)initServerAlam: (NSString *)token;
#pragma mark - lamnhs lấy cấu hình camera để phân tích lỗi camera đang gặp phải
- (void)getConfigByJson: (NSString *)serial strConfigName:(NSString *)name;
#pragma mark - lamnhs set cấu hình camera để phân tích lỗi camera đang gặp phải
- (void)setConfigByJson: (NSString *)serial strConfigName:(NSString *)name strJsonConfig:(NSString *) config;
#pragma mark - lamnhs tiến hành gọi sdk để lấy danh sách camera cùng mạng
- (void)searchDevice;
-(void)startConfigWifiByAPMode:(NSString*)userName userPassword:(NSString*)userPassword ssid:(NSString*)ssid password:(NSString*)password;
-(void)startConfigTimer: (int) timeOut;
@end

NS_ASSUME_NONNULL_END
