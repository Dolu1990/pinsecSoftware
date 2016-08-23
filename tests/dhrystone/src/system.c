
#include <stdint.h>


void init_sections() {
	extern char _bss_start, _bss_end;
	memset(&_bss_start, 0, &_bss_end - &_bss_start);
	extern char _sdata, _edata, _etext;
	memcpy(&_sdata, &_etext, &_edata - &_sdata);


	typedef void(*ctor_t)();
	extern uint32_t _ctors_start;
	extern uint32_t _ctors_end;


	uint32_t ctor = (uint32_t)&_ctors_start;
	while( ctor < (uint32_t)&_ctors_end )
	{
		//(*ctor)();
		void (*ptr)() = (void (*)())(*((uint32_t*)ctor));
		(*ptr)();
		ctor += 4;
	}
}

int     times (){
 return 0;
}
#include <time.h>
clock_t	clock(){
  return times();
}

int close(int fd) {
	return 0;
}

int fstat(int fd, struct _stat *buffer) {
	return 0;
}

int isatty(int fd) {
	return 0;
}

long lseek(int fd, long offset, int origin) {
	return 0;
}

int read(int fd, void *buffer, unsigned int count) {
	return 0;
}


void writeChar(char value) {
	 ((volatile uint32_t*)(0xF0010000))[0] = value;
}

void writeChars(char* value) {
	while (*value) {
		writeChar(*(value++));
	}
}

int write(int fd, const void *buffer, unsigned int count) {
	for (int idx = 0; idx < count; idx++) {
		writeChar(((char*) buffer)[idx]);
	}
	return count;
}
