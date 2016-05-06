/*arm movement test*/

#include "LinuxDARwIn.h"
#include "minIni.h"
#include <stdexcept>
#include <iostream>

using namespace Robot;

int main(){
	printf("/===== Arm Control Test using preset movements =====/ \n");

	///////////////////Framework Initalise///////////////////////////
	LinuxCM730 linux_cm730("/dev/ttyUSB0");
	CM730 cm730(&linux_cm730);
	if(cm730.Connect() == false){
		printf("Unable to connect \n");
		return 0;
	}
	///////////////////////////////////////////////////////////////

	int pitch = 0;
	int roll = 0;
	cm730.ReadWord(JointData::ID_R_SHOULDER_PITCH, MX28::P_PRESENT_POSITION_L, &pitch, 0);
	cm730.ReadWord(JointData::ID_R_SHOULDER_ROLL, MX28::P_PRESENT_POSITION_L, &roll, 0);

	char c = 'w';
	system("/bin/stty raw");
	while((c=getchar())!= 'q')
	{
		cm730.ReadWord(JointData::ID_R_SHOULDER_PITCH, MX28::P_PRESENT_POSITION_L, &pitch, 0);
		printf("\r");
		switch((std::getchar())){
			case 'w':
				roll += 30;
				printf("up");
				break;
			case 's':
				roll -= 30;
				printf("Down");
				break;
			case 'a':
				pitch += 30;
				printf("LEFT");
				break;
			case 'd':
				pitch -= 30;
				printf("RIGHT");
				break;
			default:
				printf("null");
				break;
		}
		cm730.WriteWord(JointData::ID_R_SHOULDER_ROLL, MX28::P_GOAL_POSITION_L, roll, 0);
		cm730.WriteWord(JointData::ID_R_SHOULDER_PITCH, MX28::P_GOAL_POSITION_L, pitch, 0);
	}
	system("/bin/stty cooked");
}
