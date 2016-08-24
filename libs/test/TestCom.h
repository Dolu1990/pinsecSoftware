/*
 * TestCom.h
 *
 *  Created on: Aug 22, 2016
 *      Author: clp
 */

#ifndef TESTCOM_H_
#define TESTCOM_H_

#include "../Pinsec.h"

namespace testCom{
	void writeValue(uint32_t value){
		TEST_COM_BASE[0] = value;
	}
}


#endif /* TESTCOM_H_ */
