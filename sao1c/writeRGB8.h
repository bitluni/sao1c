inline void writeGRB8mid(const uint8_t *grb)
{
	asm volatile(
	"ldi  r20, 25"				"\n"	//25 leds
	"ldi  r19, 0"				"\n"
	"ldi  r18, 4"				"\n"
	"ld   r21, %a[ptr]+"		"\n"	//cbbrrrggg
	"byteLoop8:"				"\n"
	//g0
	"out  %[port], r18"			"\n"
	"mov  r17, r21"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//g2
	"rol  r21"					"\n"	//bbrrrgggc
	"mov  r16, r21"				"\n"	//switch registers to be able to load next byte
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//g1
	"rol  r16"					"\n"	//brrrgggcb
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//g0
	"ror  r16"					"\n"	//bbrrrgggc
	"ror  r16"					"\n"	//cbbrrrggg
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r16"					"\n"	//bbrrrgggc
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"rol  r16"					"\n"	//brrrgggcb
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g0
	"ror  r16"					"\n"	//bbrrrgggc
	"ror  r16"					"\n"	//cbbrrrggg
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r16"					"\n"	//bbrrrgggc
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"ror  r16"					"\n"	//cbbrrrggg
	"ror  r16"					"\n"	//gcbbrrrgg
	"out  %[port] , r19"		"\n"
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"nop"						"\n"
	//red
	//r0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"				"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//r1
	"rol  r16"					"\n"	//gcbbrrrgg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//r0
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"rol  r16"					"\n"	//gcbbrrrgg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r0
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"ror  r16"					"\n"	//gggcbbrrr
	"ror  r16"					"\n"	//rgggcbbrr
	"out  %[port] , r19"		"\n"
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"nop"						"\n"
	//blue
	//b0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b6
	//last two bits
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"ld   r21, %a[ptr]+"		"\n"	//starting to match cycles while preloading next byte
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"nop"						"\n"
	"dec r20"					"\n"	//decrementing loop counter
	"out  %[port] , r19"		"\n"
	"breq done8"				"\n"
	"rjmp byteLoop8"			"\n"
	"done8:"					"\n"
	:
	: [port] "I" (_SFR_IO_ADDR(PORTB)), [ptr] "e" (grb)
	: "r18", "r16", "r17", "r19", "r20", "r21");
}

inline void writeGRB8low(const uint8_t *grb)
{
	asm volatile(
	"ldi  r20, 25"				"\n"	//25 leds
	"ldi  r19, 0"				"\n"
	"ldi  r18, 4"				"\n"
	"ld   r21, %a[ptr]+"		"\n"	//cbbrrrggg
	"byteLoop8:"				"\n"
	//g0
	"out  %[port], r18"			"\n"
	"mov  r17, r21"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"mov  r16, r21"				"\n"	//switch registers to be able to load next byte
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"	
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"	
	"nop"						"\n"	
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r16"					"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"rol  r16"					"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g0
	"rol  r16"					"\n"	//rrrgggcbb
	"rol  r16"					"\n"	//rrgggcbbr
	"out  %[port] , r19"		"\n"
	"rol  r16"					"\n"	//rgggcbbrr
	"ror  r16"					"\n"	//gggcbbrrr
	"nop"						"\n"
	//red
	//r0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"rol  r16"					"\n"	//gcbbrrrgg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r0
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"out  %[port] , r19"		"\n"
	"ror  r16"					"\n"	//rgggcbbrr
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	//blue
	//b0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"	
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//0
	"nop"						"\n"
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r19"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b6
	//last two bits
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"ld   r21, %a[ptr]+"		"\n"	//starting to match cycles while preloading next byte
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"nop"						"\n"
	"dec r20"					"\n"	//decrementing loop counter
	"out  %[port] , r19"		"\n"
	"breq done8"				"\n"
	"rjmp byteLoop8"			"\n"
	"done8:"					"\n"
	:
	: [port] "I" (_SFR_IO_ADDR(PORTB)), [ptr] "e" (grb)
	: "r18", "r16", "r17", "r19", "r20", "r21");
}

inline void writeGRB8(const uint8_t *grb)
{
	asm volatile(
	"ldi  r20, 25"				"\n"	//25 leds
	"ldi  r19, 0"				"\n"
	"ldi  r18, 4"				"\n"
	"ld   r21, %a[ptr]+"		"\n"	//cbbrrrggg
	"byteLoop8:"				"\n"
//g0
	"out  %[port], r18"			"\n"
	"mov  r17, r21"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r21"					"\n"	//bbrrrgggc
	"mov  r16, r21"				"\n"	//switch registers to be able to load next byte
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//g1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"rol  r16"					"\n"	//brrrgggcb
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//g2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g0
	"ror  r16"					"\n"	//bbrrrgggc
	"ror  r16"					"\n"	//cbbrrrggg
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//g3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r16"					"\n"	//bbrrrgggc
	"nop"						"\n"	
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//g4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"rol  r16"					"\n"	//brrrgggcb
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//g5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g0
	"ror  r16"					"\n"	//bbrrrgggc
	"ror  r16"					"\n"	//cbbrrrggg
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//g6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r16"					"\n"	//bbrrrgggc
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//g7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"ror  r16"					"\n"	//cbbrrrggg
	"ror  r16"					"\n"	//gcbbrrrgg
	"out  %[port] , r19"		"\n"
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"nop"						"\n"
//red
//r0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"				"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//r1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"rol  r16"					"\n"	//gcbbrrrgg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//r2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r0
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//r3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//r4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"rol  r16"					"\n"	//gcbbrrrgg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//r5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r0
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//r6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//r7	
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"ror  r16"					"\n"	//gggcbbrrr
	"ror  r16"					"\n"	//rgggcbbrr
	"out  %[port] , r19"		"\n"
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"nop"						"\n"
//blue
//b0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//b1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//b2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//b3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//b4	
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//b5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//b6	
//last two bits
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"ld   r21, %a[ptr]+"		"\n"	//starting to match cycles while preloading next byte
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
//b7	
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"nop"						"\n"
	"dec r20"					"\n"	//decrementing loop counter
	"out  %[port] , r19"		"\n"
	"breq done8"				"\n"
	"rjmp byteLoop8"			"\n"
	"done8:"					"\n"
	:
	: [port] "I" (_SFR_IO_ADDR(PORTB)), [ptr] "e" (grb)
	: "r18", "r16", "r17", "r19", "r20", "r21");
}


inline void writeGRB8mapped(const uint8_t *grb, const uint8_t *map, const uint8_t *lineOffset)
{
	
	asm volatile(
	"ldi  r20, 25"				"\n"	//25 leds
	"ldi  r19, 0"				"\n"
	"ldi  r18, 4"				"\n"
	"ld   r22, %a[map]+"		"\n"
	"mov  r23, r30"				"\n"	
	"mov  r24, r31"				"\n"
	"add  r30, r22"				"\n"
	"adc  r31, r19"				"\n"
	"ld   r21, %a[ptr]"			"\n"	//cbbrrrggg
	"byteLoop8:"				"\n"
	//g0
	"out  %[port], r18"			"\n"
	"mov  r17, r21"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r21"					"\n"	//bbrrrgggc
	"mov  r16, r21"				"\n"	//switch registers to be able to load next byte
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"rol  r16"					"\n"	//brrrgggcb
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g0
	"ror  r16"					"\n"	//bbrrrgggc
	"ror  r16"					"\n"	//cbbrrrggg
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r16"					"\n"	//bbrrrgggc
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"rol  r16"					"\n"	//brrrgggcb
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g0
	"ror  r16"					"\n"	//bbrrrgggc
	"ror  r16"					"\n"	//cbbrrrggg
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g2
	"rol  r16"					"\n"	//bbrrrgggc
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//g7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//g1
	"ror  r16"					"\n"	//cbbrrrggg
	"ror  r16"					"\n"	//gcbbrrrgg
	"out  %[port] , r19"		"\n"
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"nop"						"\n"
	//red
	//r0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"				"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"rol  r16"					"\n"	//gcbbrrrgg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r0
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"rol  r16"					"\n"	//gcbbrrrgg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r0
	"ror  r16"					"\n"	//ggcbbrrrg
	"ror  r16"					"\n"	//gggcbbrrr
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r6
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r2
	"rol  r16"					"\n"	//ggcbbrrrg
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//r7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//r1
	"ror  r16"					"\n"	//gggcbbrrr
	"ror  r16"					"\n"	//rgggcbbrr
	"out  %[port] , r19"		"\n"
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"nop"						"\n"
	//blue
	//b0
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b1
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b2
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b3
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"mov  r30, r23"				"\n"
	"mov  r31, r24"				"\n"	
//	"nop"						"\n"
//	"nop"						"\n"
	//b4
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	"ld   r22, %a[map]+"		"\n"	//two clocks from rom
	"add  r30, r22"				"\n"
//	"nop"						"\n"
//	"nop"						"\n"
//	"nop"						"\n"

	//b5
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"ror  r16"					"\n"	//rrgggcbbr
	"nop"						"\n"
	"out  %[port] , r19"		"\n"
	
	"adc  r31, r19"				"\n"	
//	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	
	//b6
	//last two bits
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b1
	"rol  r16"					"\n"	//rgggcbbrr
	"ld   r21, %a[ptr]"			"\n"
//	"ld   r21, %a[ptr]+"		"\n"	//starting to match cycles while preloading next byte (2 cycles from rom)
	"out  %[port] , r19"		"\n"
	"nop"						"\n"
	"nop"						"\n"
	"nop"						"\n"
	//b7
	"out  %[port] , r18"		"\n"
	"mov  r17, r16"				"\n"
	"and  r17, r18"				"\n"
	"out  %[port] , r17"		"\n"	//b0
	"nop"						"\n"
	"dec r20"					"\n"	//decrementing loop counter
	"out  %[port] , r19"		"\n"
	"breq done8"				"\n"
	"rjmp byteLoop8"			"\n"
	"done8:"					"\n"
	:
	: [port] "I" (_SFR_IO_ADDR(PORTB)), [ptr] "e" (grb), [map] "e" (map)
	: "r18", "r16", "r17", "r19", "r20", "r21", "r22", "r23", "r24");
}
