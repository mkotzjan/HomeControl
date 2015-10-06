/*
 * Switch.cpp
 * Class to switch the RC's
 */

#include "RCSwitch.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	// The output gpio pin I use
	int output = 0;

	if (argc != 4)
	{
		printf("Usage:\nSwitch <System-code> <Unit code> <command>");
		return 1;
	}

	// Check for wiringPi
	if (wiringPiSetup () == -1) return 1;
	piHiPri(20);

	// Set input
	char* systemCode = arg[1];
	int unitCode = arg[2];
	int command = arg[3];

	RCSwitch rcSwitch = RCSwitch();
	rcSwitch.setPulseLength(300);
	rcSwitch.enableTransmit(output);

	switch(command)
	{
		case 1:
			rcSwitch.switchOnBinary(systemCode, unitCode);
			break;
		case 0:
			rcSwitch.switchOffBinary(systemCode, unitCode);
			break;
		default:
			printf("The given command (%i) is not supported", command);
			return 1;
	}
	return 0;
}