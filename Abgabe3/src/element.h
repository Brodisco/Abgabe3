/*
 * element.h
 *
 *  Created on: 28.11.2022
 *      Author: student
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <stdlib.h>
#include <stdio.h>

struct Element
{
       unsigned int value;
       void* pSuccessor;
};
typedef struct Element Element;

Element* elementCreate();

#endif /* ELEMENT_H_ */
