/*
 * test.c
 *
 *  Created on: 30.11.2022
 *      Author: student
 */

#include "list.h"

// Aufgabe 4

void test_pushPrint(void) {
	/*
	 * Die Funktion soll zunächst mit createList eine leere Liste anlegen und initialisieren.
	 * Im Anschluss soll versucht werden die Liste mittels der listPrint Funktion vorwärts auszugeben.
	 * Die Funktion soll nun 10 Knoten mit den Werten 1-10 in aufsteigender Reihenfolge mittels listPush in die
	 * leere Liste einfügen und einmal vorwärts mittels der listPrint Funktion ausgeben.
	 * Ausgabe:
	 * Liste leer!
	 * 1 2 3 4 5 6 7 8 9
	 * 9 8 7 6 5 4 3 2 1
	 */

	List* pTestListe = listCreate();
	listPrint(pTestListe);

	for (int i = 1; i < 11; i++) {
		listPush(pTestListe, i);
		printf("%i ", i);
	}
	printf("\n");
	listPrint(pTestListe);
}

void testListFindElement(void) {
	/*
	 * Die Funktion soll zunächst mit createList eine leere Liste anlegen und initialisieren.
	 * Im Anschluss soll in der leeren Liste nach dem Element mit dem Wert 0 gesucht werden.
	 * Ist der Rückgabewert gleich NULL soll „Korrekt“, sonst „Falsch“ jeweils mit Zeilenumbruch ausgegeben werden.
	 * Nun ist die Liste mit Element mit den Werten 1 bis 10 in aufsteigender Reihenfolge zu befüllen.
	 * Suchen Sie nun mit der Funktion listFindElement nach dem Element mit dem Wert 5.
	 * Ist der Schlüsselwert des zurückgegebenen Knotens gleich 5 soll „Korrekt“, sonst „Falsch“ jeweils
	 * mit Zeilenumbruch ausgegeben werden.
	 * Im Abschlusstest sollen Sie nach dem Element mit Wert 20 suchen.
	 * Ist der Rückgabewert der Funktion gleich NULL soll „Korrekt“, sonst „Falsch“ jeweils mit
	 * Zeilenumbruch ausgegeben werden.
	 * Ausgabe:
	 * Liste leer!
	 * Korrekt
	 * Korrekt
	 * Korrekt
	 */

	List* pTestListe = listCreate();

	if (listFindElement(pTestListe, 0) == NULL) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}

	for (int i = 10; i > 0; i--) {
		listPush(pTestListe, i);
	}

	Element* pResult = listFindElement(pTestListe, 5);

	if (pResult->value == 5) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}

	pResult = listFindElement(pTestListe, 20);

	if (pResult == NULL) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}
}

// Aufgabe 5

void testListGetElementAtIndex(void) {

}

unsigned testListGetIndexOfElement(void) {

}
