//
//  DeviceManagerWrapDelegate.h
//  FSSCameraSDK
//
//  Created by LamMacM1 on 5/16/22.
//

#ifndef DeviceManagerWrapDelegate_h
#define DeviceManagerWrapDelegate_h

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@protocol DeviceManagerWrapDelegate <NSObject>

@optional
- (void)getDeviceChannel:(NSString *)sId result:(int)result seq:(int)seq;
- (void)getDeviceState:(NSString *)sId result:(int)result seq:(int)seq;
- (void)quickConfiguration:(id)device result:(int)resurt;
- (void)errorQuickConfiguration:(NSString *)error;
- (void)countdown:(int)time;
- (void)deleteDevice:(NSString *)sId result:(int)result;
- (void)addDeviceResult:(NSString *)sId result:(int)result seq:(int)seq;
- (void)changeDeviceResult:(int)result;
//lamnhs lắng nghe kết quả config của camera do sdk trả về
- (void)getConfigByJson: (NSString *)serial jsonResult:(NSString *)result;
//lamnhs lắng nghe kết quả cấu hình config cho camera thành công hay thất bại
- (void)setConfigByJson: (int)errorCode;
//lamnhs lắng nghe sdk trả về danh sách camera cùng mạng
- (void)searchDevice:(NSMutableArray*)searchArray result:(int)result;
@end
#endif /* DeviceManagerWrapDelegate_h */
NS_ASSUME_NONNULL_END
