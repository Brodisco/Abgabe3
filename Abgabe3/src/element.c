/*
 * element.c
 *
 *  Created on: 28.11.2022
 *      Author: student
 */


#include "element.h"


Element* elementCreate() {
	/*
	 * Die Funktion erzeugt ein leeres Element auf dem Heap
	 * und setzt den Nachfolger pSuccessor auf nullptr und den value auf 0.
	 * Anschließend ist der Zeiger auf das Element zurückzugeben.
	 */

	Element* pNewElement = (Element*) malloc(sizeof(Element));

	pNewElement->value = 0;
	pNewElement->pSuccessor = NULL;

	return pNewElement;
}
