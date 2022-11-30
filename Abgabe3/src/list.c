/*
 * list.c
 *
 *  Created on: 28.11.2022
 *      Author: student
 */

#include "list.h"
#include "element.h"
#include "myboolean.h"

// Aufgabe 1

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

	Element* pNewHead = elementCreate();

	pNewHead->value = value;
	pNewHead->pSuccessor = list->head;


	list->head = pNewHead;
}

Element* listPop(List* list) {
	/*
	 * Der Nachfolger des Kopfes der Liste wird der neue Kopf der Liste.
	 * Die Funktion gibt den alten Kopf der Liste zurück.
	 */

	Element* pOldHead = list->head;
	list->head = pOldHead->pSuccessor;

	return pOldHead;

}

void listPrint(List* list) {
	/*
	 * Die Funktion gibt die Werte der in der Liste enthaltenen Elemente durch Leerzeichen getrennt
	 * auf der Konsole aus. Die Ausgabe erfolgt dabei beginnend mit dem Kopf der Liste bis zum Ende der Liste.
	 * Ist die Liste jedoch leer (kopf==NULL) soll der Text „Liste leer!“ ausgegeben werden.
	 * Am Ende soll in jedem Fall ein Zeilenumbruch ausgegeben werden.
	 */

	if (list->head == NULL) {
		printf("Liste leer!");
	} else {
		Element* pCurrentElement = list->head;
		while (pCurrentElement != NULL) {
			printf("%i ", pCurrentElement->value);
			pCurrentElement = pCurrentElement->pSuccessor;
		}
	}
	printf("\n");
}

void listFillRandom(List* list, int seed, int anzahlWerte, int min, int max) {
	/*
	 * Die Funktion soll die übergebene Liste mit anzahlWerte Elemente füllen.
	 * Das Einfügen der Elemente soll mittels der push - Funktion erfolgen.
	 * Die Zufallszahlen sollen zwischen einschließlich min und max liegen.
	 * Für die Generierung der Zahlen soll die Funktion rand() aus der stdlib.h verwendet werden.
	 * Vor dem Ziehen der ersten Zufallszahl soll der Seed auf den übergebenen Wert gesetzt werden.
	 */

	srand(seed);

	for(int i = 0; i < anzahlWerte; i++) {
		listPush(list, (rand()%(max-min+1))+min);
	}
}

//Aufgabe 2
Element* listFindElement(List* list, unsigned int value) {
	/*
	 * Die Funktion durchsucht die übergebene Liste nach einem Element mit dem angegebenen Wert.
	 * Ist ein entsprechendes Listenelement vorhanden wird der Zeiger auf dieses Element zurückgegeben.
	 * Gibt es kein Listenelement mit diesem Wert so wird NULL zurückgegeben.
	 */

	Element* pResult = NULL;

	Element* pCurrentElement = list->head;
	while (pCurrentElement != NULL) {
		if (pCurrentElement->value == value) {
			pResult = pCurrentElement;
			break;
		}
		pCurrentElement = pCurrentElement->pSuccessor;
	}

	return pResult;
}


int listGetIndexOfElement(List* list, unsigned int value) {
	/*
	 * Die Funktion durchsucht die übergebene Liste, beginnend vom Kopf, nach einem Element mit dem angegebenen Wert.
	 * Dabei wird die Position des Elements innerhalb der Liste „mitgezählt“. Der Kopf entspricht dabei Position 0,
	 * der Nachfolger des Kopfes entspricht Position 1, usw. Ist ein entsprechendes Listenelement vorhanden wird
	 * die Position zurückgegeben.
	 * Gibt es kein Listenelement mit diesem Wert so wird -1 zurückgegeben.
	 */

	int result = -1;
	int index = 0;

	if (list->head != NULL) {
		Element* pCurrentElement = list->head;
		while (pCurrentElement != NULL) {
			if (pCurrentElement->value == value) {
				result = index;
				break;
			}
			pCurrentElement = pCurrentElement->pSuccessor;
			index++;
		}
	}

	return result;
}


Element* listGetElementAtIndex(List* list, unsigned int index) {
	/*
	 * Die Funktion durchläuft die Liste beginnend vom Kopf mit Index 0 bis zum Element mit dem entsprechenden Index
	 * und gibt einen Zeiger auf das Element zurück. Ist die Liste leer oder kürzer, so dass ein Folgeelement
	 * den Wert NULL hat, wird NULL zurückgegeben.
	 */

	Element* pResult = NULL;

	if(list->head != NULL) {
		Element* pCurrentElement = list->head;
		int currentindex = 0;

		while (currentindex < index) {
			if (pCurrentElement->pSuccessor == NULL) {
				break;
			} else {
				pCurrentElement = pCurrentElement->pSuccessor;
			}
			currentindex++;
		}

		if (currentindex == index) {
			pResult = pCurrentElement;
		}
	}

	return pResult;
}

// Aufgabe 3

boolean listSwapElements(List* list, unsigned int aIndex, unsigned int bIndex) {
	/*
	 * Die Funktion vertauscht die Werte der Elemente an Index aIndex und Index bIndex miteinander.
	 * Schlägt die Vertauschung fehl, weil eines der beiden Elemente nicht existiert (Liste ist kürzer) wird FALSE zurückgegeben.
	 * Ansonsten wird TRUE zurückgegeben. Zu Übungszwecken bietet es sich an die Vertauschung über eine zeigerbasierte Lösung durchzuführen.
	 */

	return FALSE;
}

boolean listDeleteElement(List* list, unsigned int value) {
	/*
	 * Die Funktion durchsucht die Liste beginnend vom Kopf zum Ende nach einem Element mit entsprechendem Value.
	 * Ist das Element nicht in der Liste enthalten wird FALSE zurückgegeben. Ist das Element in der Liste enthalten,
	 * so wird dieses gelöscht und sein Speicher freigegeben. Vorher ist allerdings der Nachfolgerzeiger des Vorgängerelements auf den Nachfolger
	 * des Elements zu setzen (siehe GDI Skript).
	 */

	Element* pElement = listFindElement(list, value);
	int index = listGetIndexOfElement(list, value);

	if (pElement == NULL) {
		// Element nicht gefunden
		return FALSE;
	} else {
		// Element gefunden
		if (index == 0) {
			// Element ist an erster Stelle -> Kein Vorgänger
			list->head = pElement->pSuccessor;
		} else {
			// Nicht an der ersten Stelle -> Vorgänger.Nachfolger auf Element.Nachfolger setzen
			Element* pPredecessor = listGetElementAtIndex(list, index - 1);
			pPredecessor->pSuccessor = pElement->pSuccessor;
		}
		// Speicher von Element freigeben
		free(pElement);
		return TRUE;
	}
}


