/*
 * Author: Nicholas Humphries
 * Company: Waikato University
 * Licence: MIT Licence - Copyright (c) 2016 Nicholas Humphries
 *
 * This has functions that allow you to initalise the Darwin-op, through
 * controlling the CM730 directly through USB. Code is setup for use on
 * a RaspberryPi Model B. Modifications to the ttyDevice may be needed 
 * for other devices
 *
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "LinuxDARwIn.h"

/*
 * Initialises the CM730 board for commands
 */
CM730 DarwinInit(){
	LinuxCM730 linux_cm730("/dev/ttyUSB0");
	CM730 cm730(&linux_cm730);
	if(cm730.Connect() == false){
		printf("Failed to connect to the darwin. Check the cable is conneted correctly and the ttyDevice is set correct");
		throw std::exception();
	}
	return cm730;
}
/*
 * Holds the head in the current position
 */
void DarwinHoldHead(CM730 cm730){
	printf("Holding the head steady \n");
	cm730.WriteWord(JointData::ID_HEAD_PAN,		MX28::P_TORQUE_ENABLE, 8, 0);
	cm730.WriteWord(JointData::ID_HEAD_TILT,	MX28::P_TORQUE_ENABLE, 8, 0);
}

/*
 * Freezes the legs in current position
 */
void DarwinHoldLegs(CM730 cm730){
	printf("Holding the legs steady \n");
	cm730.WriteWord(JointData::ID_R_HIP_YAW,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_HIP_YAW,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_R_HIP_PITCH,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_HIP_PITCH,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_R_KNEE,		MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_KNEE,		MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_R_ANKLE_PITCH,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_ANKLE_PITCH,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_R_ANKLE_ROLL,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_ANKLE_ROLL,	MX28::P_TORQUE_ENABLE, 1, 0);
}

/*
 * Freezes the arms in current position
 */
void DarwinHoldArms(CM730 cm730){
	printf("Holding the arms steady \n");
	cm730.WriteWord(JointData::ID_R_SHOULDER_PITCH,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_SHOULDER_PITCH,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_R_SHOULDER_ROLL,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_SHOULDER_ROLL,	MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_R_ELBOW,		MX28::P_TORQUE_ENABLE, 1, 0);
	cm730.WriteWord(JointData::ID_L_ELBOW,		MX28::P_TORQUE_ENABLE, 1, 0);
}


