/*
 * MPU6050Accelerometer.h
 *
 *  Created on: Oct 25, 2023
 *      Author: tymehopkins
 */

#ifndef SRC_MPU6050ACCELEROMETER_H_
#define SRC_MPU6050ACCELEROMETER_H_


#include "stm32f7xx_hal.h"

void MPU6050_init(void); //Initialize the MPU
void MPU6050_Read_Accel (void); //Read MPU Accelerator
void MPU6050_Read_Gyro (void); //Read MPU Gyroscope



#endif /* SRC_MPU6050ACCELEROMETER_H_ */
