
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "IScanDeviceProtocol.h"
#import "JOBluetoothDevice.h"


typedef NS_ENUM(NSUInteger, DeviceIdType) {
    DEVTYPE_CLOUDLOCK = 1,
    JDEVTYPE_JOLOCK,
};

@interface ScannedPeripheral : NSObject<IScanDeviceProtocol>
@property (strong, nonatomic) CBPeripheral* peripheral;

@property (strong, nonatomic) JOBluetoothDevice* joDevice;

@property (copy, nonatomic) NSString* macAddress;

@property (assign, nonatomic) int deviceType;

@property (assign, nonatomic) BOOL isActive;
/*
 *设备信号值
 */
@property (assign, nonatomic) int RSSI;

@property (assign, nonatomic) int count;

@property (nonatomic,assign) BOOL isConnected;

@property (nonatomic,assign) BOOL isAutoOpenLock;
/*
 *设备名称
 */
@property (nonatomic, strong) NSString *name;

///*
// *设备UUID
// */
//@property (nonatomic, strong) NSString *deviceUUID;

/*
 *广播数据
 */
@property (nonatomic, strong) NSData *scanRecord;

@property (nonatomic, assign) int deviceID; //0时云锁 1是家居锁

+ (ScannedPeripheral*) initWithPeripheral:(CBPeripheral*)peripheral rssi:(int)RSSI isPeripheralConnected:(BOOL)isConnected;

- (NSString*) name;

@end
