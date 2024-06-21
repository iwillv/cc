#include<reg51.h>
sbit key_set = P1^0;
sbit key_add = P1^1;
sbit key_sub = P1^2;
sbit key_rst = P1^3;
unsigned char cp,cp2,cp3,guanjian,flash,sec,min = 49,hour = 11;
void key(void)
{
	if(key_set == 0)
	{
		guanjian++;
		if(guanjian >= 4)guanjian = 1;
		while(key_set == 0);	
	}
	if(key_add == 0)
	{
		if(guanjian == 1){hour++;if(hour >= 24)hour = 23;}
		if(guanjian == 2){min++;if(min >= 60)min = 59;}
		if(guanjian == 3){sec++;if(sec >= 60)sec = 59;}	
		while(key_add == 0);	
	}
	if(key_sub == 0)
	{
		if(guanjian == 1){hour--;if(hour <= 0)hour = 0;}
		if(guanjian == 2){min--;if(min <= 0)min = 0;}
		if(guanjian == 3){sec--;if(sec <= 0)sec = 0;}
		while(key_sub == 0);	
	}
	if(key_rst == 0)
	{
		guanjian = 0;
		while(key_rst == 0);	
	}
}
