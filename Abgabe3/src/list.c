/*
 * list.c
 *
 *  Created on: 28.11.2022
 *      Author: student
 */

#include "list.h"


List* listCreate() {
	/*Die Funktion erzeugt eine leere Liste auf dem Heap und setzt den Kopf der Liste auf NULL.
	 * Abschließend wird der Zeiger auf die Liste zurückgegeben.
	 */

	List* pNewList = (List*)malloc(sizeof(List));
	pNewList->head = NULL;

	return pNewList;
}

void listPush(List* list, unsigned int value) {
	/*
	 * Die Funktion erzeugt ein Listenelement auf dem Heap und setzt das Strukturelement value auf den übergebenen Wert.
	 * Das erzeugte Listenelement wird neuer Kopf der Liste.
	 * Der alte Kopf der Liste wird der Nachfolger des neuen Kopfes.
	 */

	Element* pNewHead = createElement();

	pNewHead->value = value;
	pNewHead->pSuccessor = list->head;
	pNewHead.pSuccessor

	list->head = pNewHead;
}

Element* listPop(List* list) {

}

void listPrint(List* list) {

}
