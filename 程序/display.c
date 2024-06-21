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

