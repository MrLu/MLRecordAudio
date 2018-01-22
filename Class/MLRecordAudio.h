//
//  RecordAudio.h
//
//  Created by Randy on 14-11-27.
//  Copyright (c) 2014年 com.bjhl. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 MLRecordAudioFinish

 @param tempFilePath 文件目录
 @param message message
 @param timeLength 时长
 @param isSuc 录制是否成功
 @param isFinish 是否已完成，可能是录制正在执行其他操作，会返回两次，第一次是录制完 isFinish=NO,第二次是处理完其他操作 isFinish= YES
 */
typedef void(^MLRecordAudioFinish)( NSString * _Nullable tempFilePath, NSString * _Nullable message,NSInteger timeLength,BOOL isSuc,BOOL isFinish);
typedef void (^BJRecordRemainingTime)(NSTimeInterval time);


/**
 MLRecordAudio use AVAudioRecorder, generate caf audioFile
 */
@interface MLRecordAudio : NSObject

@property (assign, nonatomic)NSTimeInterval duration;
@property (copy, nonatomic, nullable) BJRecordRemainingTime remainingCallback;
@property (copy, nonatomic, nullable) MLRecordAudioFinish finishCallback;

- (void)stopRecord;
- (void)startRecord;
- (void)cancelRecord;
- (BOOL)isRecording;

- (void)setFinishCallBack:(MLRecordAudioFinish _Nullable)finishCallback;
- (void)setRemainingCallBack:(BJRecordRemainingTime _Nullable)remainingCallback;

@end
