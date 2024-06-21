#include<key.c>
#include<reg51.h>
const unsigned char seven_seg[] = 
{
	0xc0,0xf9,0xa4,0xb0,0x99,
	0x92,0x82,0xf8,0x80,0x90,
};
void display0(void)
{								
		   
	if(cp3 == 0){P2 = 0x01;P0 = seven_seg[sec % 10];}
	if(cp3 == 1){P2 = 0x02;P0 = seven_seg[sec / 10];}
	if(cp3 == 2){P2 = 0x04;P0 = 0xbf | flash;}
	if(cp3 == 3){P2 = 0x08;P0 = seven_seg[min % 10];}
	if(cp3 == 4){P2 = 0x10;P0 = seven_seg[min / 10];}
	if(cp3 == 5){P2 = 0x20;P0 = 0xbf | flash;}
	if(cp3 == 6){P2 = 0x40;P0 = seven_seg[hour % 10];}
	if(cp3 == 7){P2 = 0x80;P0 = seven_seg[hour / 10];}
}
void display1(void)
{
	if(cp3 == 0){P2 = 0x01;P0 = seven_seg[sec % 10];}
	if(cp3 == 1){P2 = 0x02;P0 = seven_seg[sec / 10];}
	if(cp3 == 2){P2 = 0x04;P0 = 0xbf;}
	if(cp3 == 3){P2 = 0x08;P0 = seven_seg[min % 10];}
	if(cp3 == 4){P2 = 0x10;P0 = seven_seg[min / 10];}
	if(cp3 == 5){P2 = 0x20;P0 = 0xbf;}
	if(cp3 == 6){P2 = 0x40;P0 = seven_seg[hour % 10] | flash;}
	if(cp3 == 7){P2 = 0x80;P0 = seven_seg[hour / 10] | flash;}
}
void display2(void)
{
	if(cp3 == 0){P2 = 0x01;P0 = seven_seg[sec % 10];}
	if(cp3 == 1){P2 = 0x02;P0 = seven_seg[sec / 10];}
	if(cp3 == 2){P2 = 0x04;P0 = 0xbf;}
	if(cp3 == 3){P2 = 0x08;P0 = seven_seg[min % 10] | flash;}
	if(cp3 == 4){P2 = 0x10;P0 = seven_seg[min / 10] | flash;}
	if(cp3 == 5){P2 = 0x20;P0 = 0xbf;}
	if(cp3 == 6){P2 = 0x40;P0 = seven_seg[hour % 10];}
	if(cp3 == 7){P2 = 0x80;P0 = seven_seg[hour / 10];}
}

void display3(void)
{
	if(cp3 == 0){P2 = 0x01;P0 = seven_seg[sec % 10] | flash;}
	if(cp3 == 1){P2 = 0x02;P0 = seven_seg[sec / 10] | flash;}
	if(cp3 == 2){P2 = 0x04;P0 = 0xbf;}
	if(cp3 == 3){P2 = 0x08;P0 = seven_seg[min % 10];}
	if(cp3 == 4){P2 = 0x10;P0 = seven_seg[min / 10];}
	if(cp3 == 5){P2 = 0x20;P0 = 0xbf;}
	if(cp3 == 6){P2 = 0x40;P0 = seven_seg[hour % 10];}
	if(cp3 == 7){P2 = 0x80;P0 = seven_seg[hour / 10];}
}

void timer0_isr(void) interrupt 1
{
	
	TH0 = (65535 - 2000) / 255;
	TL0 = (65535 - 2000) % 255;
	cp++;
	if(cp >= 250)
	{
		cp = 0;
		cp2++;
		flash = ~flash;
	}
	if(cp2 >= 2)
	{
		cp2 = 0;
		sec++;
		if(sec >= 60){sec = 0; min++;}
		if(min >= 60){min = 0; hour++;}
		if(hour >= 24)hour=0;
	}
	
	if(guanjian == 0)display0(); 
	if(guanjian == 1)display1(); 
	if(guanjian == 2)display2();
	if(guanjian == 3)display3();
	cp3++;
	if(cp3 >= 8)cp3 = 0;
}

void timer0_init(void)
{
	TMOD = 0x01;
	
	TH0 = (65535 - 2000) / 255;
	TL0 = (65535 - 2000) % 255; 
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void main()
{
	timer0_init();
	while(1)
	{
	   	key();
	}
}
