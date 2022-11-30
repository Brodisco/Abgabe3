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
	/*
	 * Die Funktion soll zunächst eine leere Liste anlegen und mit der Funktion init initialisieren.
	 * Versuchen Sie nun mit der Funktion listGetElementAtIndex auf das Element an Index 5 zuzugreifen.
	 * Ist der Rückgabewert gleich NULL soll „Korrekt“, sonst „Falsch“ jeweils mit Zeilenumbruch ausgegeben werden.
	 * Nun ist die Liste mit Elementen mit den Werten 1 bis 10 in aufsteigender Reihenfolge zu befüllen.
	 * Suchen Sie nun erneut nach dem Element an Index 5. Ist der Schlüsselwert des zurückgegebenen
	 * Elementes gleich 6 soll „Korrekt“, sonst „Falsch“ jeweils mit Zeilenumbruch ausgegeben werden.
	 * Suchen Sie jetzt erneut nach dem Element an Index 15 für einen Überlauftest. Ist der Schlüsselwert
	 * des zurückgegebenen Elementes gleich NULL soll „Korrekt“, sonst „Falsch“ jeweils mit Zeilenumbruch
	 * ausgegeben werden.
	 * Ausgabe:
	 * Liste leer!
	 * Korrekt
	 * Korrekt
	 * Korrekt
	 */

	List* pTestListe = listCreate();

	listPrint(pTestListe);

	if (listGetElementAtIndex(pTestListe, 5) == NULL) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}

	for (int i = 10; i > 0; i--) {
		listPush(pTestListe, i);
	}

	if (listGetElementAtIndex(pTestListe, 5)->value == 6) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}

	if (listGetElementAtIndex(pTestListe, 15) == NULL) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}
}

void testListGetIndexOfElement(void) {
	/*
	 * Die Funktion soll zunächst mit createList eine leere Liste anlegen und initialisieren.
	 * Suchen Sie nun mit der Funktion listGetIndexOfElement nach dem Index des Elementes mit Schlüsselwert 0.
	 * Ist der Rückgabewert der Funktion gleich -1 soll „Korrekt“, sonst „Falsch“ jeweils mit
	 * Zeilenumbruch ausgegeben werden. Nun ist die Liste mit Elementen mit den Werten 1 bis 10 in
	 * aufsteigender Reihenfolge zu befüllen. Suchen Sie mit der Funktion listGetIndexOfElement nach dem Index
	 * des Elements mit Schlüsselwert 1. Ist der Rückgabewert der Funktion gleich 0 soll „Korrekt“, sonst „Falsch“
	 * jeweils mit Zeilenumbruch ausgegeben werden. Führen Sie den gleichen Test für den Schlüsselwert 4 durch und
	 * überprüfen Sie, ob der Index mit 3 korrekt zurückgegeben wird. Im Abschlusstest sollen Sie nach dem Element
	 * mit Wert 25 suchen. Ist der Rückgabewert der Funktion gleich -1 soll „Korrekt“, sonst „Falsch“ jeweils mit
	 * Zeilenumbruch ausgegeben werden.
	 *
	 * Ausgabe:
	 * Liste leer!
	 * Korrekt
	 * Korrekt
	 * Korrekt
	 * Korrekt
	 */

	List* pTestListe = listCreate();

	listPrint(pTestListe);

	if (listGetIndexOfElement(pTestListe, 0) == -1) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}

	for (int i = 10; i > 0; i--) {
		listPush(pTestListe, i);
	}

	if (listGetIndexOfElement(pTestListe, 1) == 0) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}

	if (listGetIndexOfElement(pTestListe, 4) == 3) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}

	if (listGetIndexOfElement(pTestListe, 25) == -1) {
		printf("Korrekt\n");
	} else {
		printf("Falsch\n");
	}
}
