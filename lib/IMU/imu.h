#ifndef IMU_H
#define IMU_H

    #include "I2C.h"

    #define IMU_ADDRESS 0x69 //change to 0x68 if it doesn't work, see AD0 pin
    #define GYRO_SENSITIVITY 131.0
    #define ACC_SENSITIVITY 16384.0


    /*
     *  Description: this class will hold functions for IMU communication
     * in this case the MPU-9150
     *  exemples: initialization, read gyro, read acc ....
    */
    class imu {
        public:
            imu();

            void init();
            void setLowPass(uint8_t mode);
            void calibrate();

            void getAccGyr(int16_t *ax, int16_t *ay, int16_t *az, int16_t *gx, int16_t *gy, int16_t *gz);
            void getAcc(int16_t *ax, int16_t *ay, int16_t *az);
            void getGyr(int16_t *gx, int16_t *gy, int16_t *gz);
            void getMag(int16_t *mx, int16_t *my, int16_t *mz);

            void setDelta();
            void setLast(int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz);
            void ComplementaryFilter(int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz, float *pitch, float *roll);

        private:
            uint8_t buffer[14];

    };


#endif
