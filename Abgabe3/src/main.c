/*
 * main.c
 *
 *  Created on: 22.11.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include "element.h"
// #include "list.h"
// #include "myboolean.h"
// #include "test.h"


int main(void)
{
	printf("Abgabe3 \n");

	Element* pElement = elementCreate();

	printf("Adresse: %x", pElement);

	int wait;
	scanf("%d", &wait);
	return EXIT_SUCCESS;
}
