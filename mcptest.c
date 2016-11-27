#include <wiringPi.h>
#include <stdio.h>
#include <mcp23017.h>

#define AF_RESET	26
#define AF_BASE 	100
#define AF_GPA0		(AF_BASE + 0)
#define AF_GPA1		(AF_BASE + 1)
#define AF_GPA2		(AF_BASE + 2)
#define AF_GPA3		(AF_BASE + 3)
#define AF_GPA4		(AF_BASE + 4)
#define AF_GPA5		(AF_BASE + 5)
#define AF_GAP6		(AF_BASE + 6)
#define AF_GPA7		(AF_BASE + 7)
#define AF_GPB0		(AF_BASE + 8)
#define AF_GPB1		(AF_BASE + 9)
#define AF_GPB2		(AF_BASE + 10)
#define AF_GPB3		(AF_BASE + 11)
#define AF_GPB4		(AF_BASE + 12)
#define AF_GPB5		(AF_BASE + 13)
#define AF_GPB6		(AF_BASE + 14)
#define AF_GPB7		(AF_BASE + 15)


int main (void)
{

	printf("setup wiring pi\n");
	wiringPiSetupSys();
	printf("setup reset pin of mcp23017\n");
	pinMode(AF_RESET, OUTPUT);
	pinMode(AF_RESET, LOW);	
	printf("setup mcp23017 expecting on address 0x20\n");
	mcp23017Setup(AF_BASE, 0x20);
	pinMode(AF_GPB0, 1);
	printf("set pin at mcp address DB0 to high\n");
	digitalWrite(AF_GPB0, 1);
	sleep(5);
	digitalWrite(AF_GPB0, 0);
	printf("set pin at mcp address DB0 to low\n");
	return(0);
}
