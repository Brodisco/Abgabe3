/*
 * main.c
 *
 *  Created on: 22.11.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "list.h"
// #include "myboolean.h"
// #include "test.h"


int main(void)
{
	printf("Abgabe3 \n");
	/*

	List* leereListe = listCreate();

	List* einerListe = listCreate();
	listPush(einerListe, 5);

	List* normaleListe = listCreate();
	listPush(normaleListe, 5);
	listPush(normaleListe, 4);
	listPush(normaleListe, 3);
	listPush(normaleListe, 2);
	listPush(normaleListe, 1);
	listPush(normaleListe, 0);

	List* randomListe = listCreate();
	listFillRandom(randomListe, 20, 20, 0, 8);

	printf("Leere Liste: \n");
	listPrint(leereListe);

	printf("\nEiner Liste: \n");
	listPrint(einerListe);

	printf("\nNormale Liste: \n");
	listPrint(normaleListe);

	unsigned int* deleted = listPop(normaleListe);
	deleted = listPop(normaleListe);

	printf("\nNormale Liste mit Pop: %i\n", *deleted);
	listPrint(normaleListe);

	printf("\nRandom Liste: \n");
	listPrint(randomListe);

	printf("Erste Adresse: %x \n", randomListe);
	printf("Zweite Adresse: %x \n", ((Element*)randomListe->head)->pSuccessor);
	printf("Dritte Adresse: %x \n", ((Element*)((Element*)randomListe->head)->pSuccessor)->pSuccessor);

	printf("Die fünf gefunden: %x an Stelle %i \n", listFindElement(randomListe, 5), listGetIndexOfElement(randomListe, 5));
	printf("Die acht gefunden: %x an Stelle %i \n", listFindElement(randomListe, 8), listGetIndexOfElement(randomListe, 8));
	printf("Die drei gefunden: %x an Stelle %i \n", listFindElement(randomListe, 3), listGetIndexOfElement(randomListe, 3));

	printf("%i\n", listGetElementAtIndex(normaleListe, 0)->value);
	printf("%i\n", listGetElementAtIndex(normaleListe, 1)->value);
	printf("%i\n", listGetElementAtIndex(normaleListe, 2)->value);
	printf("%i\n", listGetElementAtIndex(normaleListe, 3)->value);
	printf("%i\n", listGetElementAtIndex(normaleListe, 4)->value);
	printf("%i\n", listGetElementAtIndex(normaleListe, 5)->value);
	printf("%x\n", listGetElementAtIndex(normaleListe, 6));
	printf("%x\n", listGetElementAtIndex(leereListe, 6));

	printf("Ende");
	*/

	printf("\nTest 1\n");
	test_pushPrint();
	printf("\nTest 2\n");
	testListFindElement();
	printf("\nTest 3\n");

	int wait;
	scanf("%d", &wait);
	return EXIT_SUCCESS;
}
