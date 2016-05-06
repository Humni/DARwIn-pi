/*
 * Author: Nicholas Humphries
 * Company: University of Waikato
 * Licence: MIT Licence - Copyright (c) 2016 Nicholas Humphries
 *
 * Header file to include the darwin assistant into projects
 *
 */

#include "LinuxDARwIn.h"
#include "minIni.h"

using namespace Robot;

/*
 * Declare all Darwin helper functions
 */
CM730 DarwinInit();
void DarwinHoldHead(CM730 cm730);
void DarwinHoldLegs(CM730 cm730);
void DarwinHoldArms(CM730 cm730);

