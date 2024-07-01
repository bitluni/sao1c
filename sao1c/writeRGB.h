void writeGRB(const uint8_t *grb)
{
	asm volatile(
		"ldi  r20, 75"				"\n"	//25 leds * 3 bytes
		"ldi  r19, 0"				"\n"
		"ldi  r18, 4"				"\n"
		"ld   r21, %a[ptr]+"		"\n"
		"rol  r21"					"\n"
		"rol  r21"					"\n"
		"rol  r21"					"\n"
		"rol  r21"					"\n"
		"byteLoop:"					"\n"
		
		"out  %[port] , r18"		"\n"
		"mov  r17, r21"				"\n"		
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r21"					"\n"
		"mov  r16, r21"				"\n"	//switch registers to be able to load next byte			
		"out  %[port] , r19"		"\n"
		"nop"						"\n"
		"nop"						"\n"
		"nop"						"\n"

		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r16"					"\n"
		"nop"						"\n"
		"out  %[port] , r19"		"\n"
		"nop"						"\n"
		"nop"						"\n"
		"nop"						"\n"

		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r16"					"\n"
		"nop"						"\n"
		"out  %[port] , r19"		"\n"
		"nop"						"\n"
		"nop"						"\n"
		"nop"						"\n"

		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r16"					"\n"
		"nop"						"\n"
		"out  %[port] , r19"		"\n"
		"nop"						"\n"
		"nop"						"\n"
		"nop"						"\n"

		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r16"					"\n"
		"nop"						"\n"
		"out  %[port] , r19"		"\n"
		"nop"						"\n"
		"nop"						"\n"
		"nop"						"\n"

		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r16"					"\n"
		"nop"						"\n"
		"out  %[port] , r19"		"\n"
		"nop"						"\n"
		"nop"						"\n"
		"nop"						"\n"

		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r16"					"\n"
		"dec r20"					"\n"		//decrementing loop counter
		"out  %[port] , r19"		"\n"
		
		"breq lastBit"				"\n"
		"ld   r21, %a[ptr]+"		"\n"		//starting to match cycles while preloading next byte
		
		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"rol  r21"					"\n"
		"rol  r21"					"\n"
		"out  %[port] , r19"		"\n"
		"rol  r21"					"\n"		//still rolling
		"rol  r21"					"\n"		//rolling byte to have bit 8 at right position
		//"nop"						"\n"		//some cycles needed for looong jump
		//"nop"						"\n"
		"rjmp byteLoop"				"\n"
		"lastBit:"					"\n"
		"nop"						"\n"
		"nop"						"\n"
		"out  %[port] , r18"		"\n"
		"mov  r17, r16"				"\n"
		"and  r17, r18"				"\n"
		"out  %[port] , r17"		"\n"
		"nop"						"\n"
		"nop"						"\n"
		"out  %[port] , r19"		"\n"
		: 
		: [port] "I" (_SFR_IO_ADDR(PORTB)), [ptr] "e" (grb)
		: "r18", "r16", "r17", "r19", "r20", "r21");
}
