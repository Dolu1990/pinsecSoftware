/*
 * system.c
 *
 *  Created on: Apr 28, 2016
 *      Author: clp
 */


void init_bss() {
	extern char _bss_start, _bss_end;
	memset(&_bss_start, 0, &_bss_end - &_bss_start);
	extern char _sdata, _edata, _etext;
	memcpy(&_sdata, &_etext, &_edata - &_sdata);
}