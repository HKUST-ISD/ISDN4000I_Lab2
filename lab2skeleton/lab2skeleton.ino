#include <Wire.h>

// Period between sensor data reading, in milliseconds
#define SAMPLING_TIME       100              

/********************************* TASK 1 *********************************/
// Refer to page 35 of the datasheet, what is the 7-bit i2c address of the IMU? 
// SDO/SA0 pin of the IMU is connected to GND 
#define IMU_I2C_ADDR               

// Number of bytes needed to store all raw readings from the IMU
#define SENSOR_DATA_LEN     12

typedef struct imuData_t {
    int16_t gyro[3];
    int16_t accel[3];
} imuData_t;

typedef struct imuDataScaled_t {
    float gyro[3];
    float accel[3];
} imuDataScaled_t;

// rawData should be used to store binary values read from the IMU data registers
byte rawData[SENSOR_DATA_LEN];

// imuData should be used to store the 16 bit word obtained by combining the 
// low byte and high byte of each sensor axis reading
imuData_t imuData;

// imuDataScaled should be used to store scaled sensor reading, 
// so that gyro data is in unit of degree per second,
// and accel data in unit of g (Earth's gravitation acceleration constant)
imuDataScaled_t imuDataScaled;

/********************************* TASK 2 *********************************/
// Refer to "Table 12. Transfer when master is writing one byte to slave" in page 35 
// of the datasheet, complete this function, where
// devAddr      is the 7-bit i2c address of the IMU
// regAddr      is the 8-bit address of the register to write into
// data         is the byte of data to be written into the specified register
// You will find these functions useful:    Wire.beginTransmission(byte)
//                                          Wire.write(const uint8_t *data, size_t quantity)
//                                          Wire.endTransmission()
void writeByteToRegister(byte devAddr, byte regAddr, byte data) {

}

/********************************* TASK 5 *********************************/
// Refer to "Table 15. Transfer when master is writing one byte to slave" in page 36 
// of the datasheet, complete this function, where
// devAddr      is the 7-bit i2c address of the IMU
// regAddr      is the 8-bit address of the register to start reading from
// data         is an array of bytes where the data read from the IMU will be stored into
// length       is the amount of bytes to read from the IMU
// You will find these functions useful:    Wire.beginTransmission(byte)
//                                          Wire.write(byte)
//                                          Wire.endTransmission()
//                                          Wire.requestFrom(uint8_t address, size_t quantity)
//                                          Wire.readBytes(uint8_t *buffer, size_t length)
void readBytesFromRegisters(byte devAddr, byte regAddr, byte *data, int length) {

}

void setup() {
    Serial.begin(9600);
    Wire.begin();

    /********************************* TASK 3 *********************************/
    // Write to CTRL1_XL register, so that the accelerometer starts operation, and
    // is configered for 6.66kHz sampling rate, +-4g range and no filtering.
    // Refer to page 54 of the datasheet
    writeByteToRegister(IMU_I2C_ADDR, , );

    /********************************* TASK 4 *********************************/
    // Write to CTRL2_G register, so that the gyroscope starts operation, and
    // is configered for 1.66kHz sampling rate and +-500dps.
    // Refer to page 55 of the datasheet
    writeByteToRegister(IMU_I2C_ADDR, , );
}

unsigned long lastTime = 0;

void loop() {
    if (millis() - lastTime > SAMPLING_TIME) {
        
        /********************************* TASK 6 *********************************/
        // Starting from register OUTX_L_G, read 12 bytes of data, so that data from
        // OUTX_L_G to OUTZ_H_XL is stored the rawData array.
        // Refer to page 65 of the datasheet
        readBytesFromRegisters(IMU_I2C_ADDR, , rawData, SENSOR_DATA_LEN);

        // Print all data in the rawData array 


        /********************************* TASK 7 *********************************/
        // Combine the low and high byte of each sensor axis, and store it into imuData
        // You can access the storage elements of imuData like this: imuData.gyro[0] = someNum,
        // where 0 = x axis, 1 = y axis, 2 = z axis

        // Print the six datum in imuData 


        /********************************* TASK 8 *********************************/
        // Refer to page 20 of the datasheet, scale the data stored in imuData and store it 
        // into imuDataScaled, so that the gyro data is stored in unit of deg per second, 
        // and accel data is stored in unit of g (Earth's gravitation acceleration constant)

        // Print the six datum in imuDataScaled
        

        Serial.println();
    }
}