//
//  STBlueToothSender.h
//  RunmefitSDK
//
//  Created by 星迈 on 2022/8/2.
//  🍎发送指令集

#import <Foundation/Foundation.h>

#import <RunmefitSDK/STMath.h>
#import <RunmefitSDK/STDeviceState.h>
#import <RunmefitSDK/STlUserInfo.h>
#import <RunmefitSDK/STlSportGoal.h>
#import <RunmefitSDK/STMessageNotice.h>
#import <RunmefitSDK/STHealthSwitch.h>
//#import <RunmefitSDK/STIntervalTime.h>
#import <RunmefitSDK/STConfigMeasureHR.h>
#import <RunmefitSDK/STNoDisturb.h>
#import <RunmefitSDK/STAlarmInterval.h>
#import <RunmefitSDK/STAlarmClock.h>
#import <RunmefitSDK/STContacts.h>
#import <RunmefitSDK/STWeather.h>
#import <RunmefitSDK/STAlarmEvent.h>
#import <RunmefitSDK/STRealTimeSwitchs.h>
#import <RunmefitSDK/STSportConfig.h>

//#import <RunmefitSDK/STBlueToothString.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    /// 进入拍照
    STlPhotoContrlStart = 0x01,
    /// 退出拍照
    STlPhotoContrlEnd = 0x02,
    /// 点击拍照
    STlPhotoContrlTakePhoto = 0x03,
    
}STlPhotoContrl;


typedef enum : NSUInteger {
    ST_History_Sport       =   0x61,     //同步运动
    ST_History_Step        =   0x62,     //同步记步/睡眠
    ST_History_HR          =   0x63,     //同步心率
    ST_History_BP          =   0x64,     //同步血压
    ST_History_BQ          =   0x65,     //同步血氧
    ST_History_Pressure    =   0x66,     //同步压力
    ST_History_Met         =   0x67,     //同步梅脱
    ST_History_Temp        =   0x68,     //同步温度
    ST_History_Mai         =   0x6E,     //同步Mai

}STHistoryCmd;


NS_ASSUME_NONNULL_BEGIN

@interface STBlueToothSender : NSObject

#pragma mark - 简单设置类

//绑定设备
+ (NSData *)writeDeviceBind;

//设备状态
+ (NSData *)readDeviceState;
+ (NSData *)writeDeviceState:(STDeviceState *)model;

//查找设备
+ (NSData *)writeFindDevice;

//停止查找设备
+ (NSData *)writeEndFindDevice;

//拍照控制
+ (NSData *)writePhotoContrl:(STlPhotoContrl)contrl;

//获取电池电量
+ (NSData *)readDeviceBattery;

//获取设备版本信息
+ (NSData *)readDeviceVersion;

//时间时区
+ (NSData *)readDeviceDateTime;
+ (NSData *)writeDeviceDateTime;

//用户信息
+ (NSData *)readUserInfo;
+ (NSData *)writeUserInfo:(STlUserInfo *)model;

//一天运动目标
+ (NSData *)readSportGoal;
+ (NSData *)writeSportGoal:(STlSportGoal *)model;

//蓝牙系统配对
+ (NSData *)writeDevicePair;

//消息推送开关
+ (NSData *)readMessageNotice;
+ (NSData *)writeMessageNotice:(STMessageNotice *)model;

//获取当前设备展示数据
+ (NSData *)readCurrentHealth;

//健康数据检测开关
+ (NSData *)readHealthSwitch;
+ (NSData *)writeHealthSwitch:(STHealthSwitch *)model;

//恢复出厂设置
+ (NSData *)writeFactorySetting;

#pragma mark - 复杂设置类

//心率检测间隔和范围
+ (NSData *)readConfigMeasureHR;
+ (NSData *)writeConfigMeasureHR:(STConfigMeasureHR *)model;

//常用联系人
+ (NSData *)readCommonContacts;
+ (NSData *)writeCommonContacts:(NSArray<STContacts *> *)modelArr;

//紧急联系人
+ (NSData *)readSosContacts;
+ (NSData *)writeSosContacts:(NSArray<STContacts *> *)modelArr;

//勿扰
+ (NSData *)readNoDisturb;
+ (NSData *)writeNoDisturb:(STNoDisturb *)model;

//闹钟
+ (NSData *)readAlarmClocks;
+ (NSData *)writeAlarmClocks:(NSArray<STAlarmClock *> *)modelArr;

//久坐提醒
+ (NSData *)readSedentaryAlarmInterval;
+ (NSData *)writeSedentaryAlarmInterval:(STAlarmInterval *)model;

//喝水提醒
+ (NSData *)readDrinkWaterAlarmInterval;
+ (NSData *)writeDrinkWaterAlarmInterval:(STAlarmInterval *)model;

//推送天气
+ (NSData *)writeWeather:(NSArray<STWeather *> *)modelArr;

//事件提醒
+ (NSData *)readAlarmEvens;
//+ (NSArray<NSData *> *)writeAlarmEvens:(NSArray<STAlarmEvent *> *)modelArr DeviceMtu:(NSUInteger)deviceMtu;

//运动模式配置
+ (NSData *)readSportConfig;
+ (NSData *)writeSportConfig:(STSportConfig *)sportConfig;

#pragma mark - 数据同步类

//同步运动数据(是否重发  1：重发，0：不重发)
+ (NSData *)readSportModeHistory:(BOOL)resend;

//同步计步/卡路里/距离/睡眠数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readStepAndSleepHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步心率数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readHeartRateHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步血压数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readBloodPressureHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步血氧数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readBloodOxygenHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步压力数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readPhysicalPressureHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步梅脱数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readMetsHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步温度数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readTemperatureHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步Mai数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readMaiHistoryWithDate:(NSString * _Nonnull)dateStr;

//同步血糖数据
///
/// 获取某一天的历史记录数据
/// \param dateStr 日期yyyyMMdd
///
+ (NSData *)readSugarHistoryWithDate:(NSString * _Nonnull)dateStr;

//获取数据有效日期列表(对应数据类型)
+ (NSData *)readHistoryValidDate:(STHistoryCmd)cmd;

#pragma mark - 表盘设置类

//获取表盘信息
+ (NSData *)readDeviceDialInfo;

//切换当前显示表盘
+ (NSData *)writeCurrentDeviceDial:(int)Id;

#pragma mark - UIImage转RGB565
+ (NSData *)getRGB656DataWith:(UIImage*)image;

//RGB888转RGB565数组
+ (NSData *)getRGB656DataWithR:(unsigned char)r G:(unsigned char)g B:(unsigned char)b;

#pragma mark - 实时上报
//实时数据开关(获取)
+ (NSData *)readRealTimeSwitchs;

//实时数据开关(设置)
+ (NSData *)writeRealTimeSwitchs:(STRealTimeSwitchs *)model;

@end

NS_ASSUME_NONNULL_END
