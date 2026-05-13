//
//  FLI-FFmpeg.h
//  FLISDK
//
//  Created by TrucPham on 08/04/2025.
//

#ifndef FLI_FFmpeg_h
#define FLI_FFmpeg_h


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FLIFFmpeg : NSObject

+ (instancetype)shared; // Singleton

- (void)execute:(NSString *)command completion:(void (^)(int result))completion;

@end

NS_ASSUME_NONNULL_END


#endif /* FLI_FFmpeg_h */

