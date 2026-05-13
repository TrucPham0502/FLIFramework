//
//  ISCCameraUserAccountModel.h
//  FunSDKDemo
//
//  Created by Pham Chi Hieu on 10/25/19.
//  Copyright © 2019 Pham Chi Hieu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UserAccountModelWrapDelegate <NSObject>
- (void)loginWithNameDelegate:(long)reslut;
@optional

@end

@interface UserAccountModelWrap : NSObject
+ (UserAccountModelWrap *) shared;
@property (nonatomic, weak) id <UserAccountModelWrapDelegate> delegate;
- (void)loginWithTypeLocal;
- (void)logout;
@end

NS_ASSUME_NONNULL_END
