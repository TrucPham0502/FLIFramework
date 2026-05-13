//
//  MPplayerModel.h
//  FSSCameraSDK
//
//  Created by Minh Phuong Nguyen on 18/10/2023.
//  Copyright © 2023 Nguyễn Minh Phương All rights reserved.
//

typedef NS_ENUM(NSInteger, SDKplayerType) {
    Other,
    Motion
};

typedef NS_ENUM(NSInteger, MPVideoState){
    Bufferring,
    Playing,
    Pause,
    Stop
};

typedef struct  {
    NSDate *mpdate;
    NSInteger h;
    NSInteger m;
    NSInteger s;
}MPdateInfo;

typedef NS_OPTIONS(NSInteger, SDKConfigType) {
    COther = 1 << 0,// lay tat ca du lieu bao gom motion va full record
    CRecordManual = 1 << 4,// lay du lieu video full record
    CMotion = 1 << 2,// lay du lieu motion detection
    CRecordRegular = 1 << 3
    //    SDK_RECORD_ALL = 0,         // 全部录像(查询类型:h264/子类型:*)
    //    SDK_RECORD_ALARM = 1,       // 外部报警录像(查询类型:h264/子类型:A)
    //    SDK_RECORD_DETECT = 2,      // 视频侦测录像(查询类型:h264/子类型:M)
    //    SDK_RECORD_REGULAR = 3,     // 普通录像(查询类型:h264/子类型:*)
    //    SDK_RECORD_MANUAL = 4,      // 手动录像(查询类型:h264//子类型:H)
    //    SDK_RECORD_KEY = 5,         // 关键录像(查询类型:h264/子类型:K)
    //    SDK_RECORD_URGENT = 6,      // 紧急录像(查询类型:h264/子类型:V)
    //    SDK_RECORD_ORIGINAL = 7,
};
