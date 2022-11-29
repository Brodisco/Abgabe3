#include "list.h"
#include "element.h"

//Aufgabe 1
/* b)
 * Die Funktion erzeugt eine leere Liste auf dem Heap
 * und setzt den Kopf der Liste auf NULL. Abschließend
 * wird der Zeiger auf die Liste zurückgegeben.
 */

List* listCreate()
{
	List* list = (List*) malloc(sizeof(List));
	list->head = NULL;
	return list;
}

/* c)
 * Die Funktion erzeugt ein Listenelement auf dem Heap
 * und setzt das Strukturelement value auf den übergebenen
 * Wert. Das erzeugte Listenelement wird neuer Kopf der Liste.
 * Der alte Kopf der Liste wird der Nachfolger des neuen Kopfes.
 */

void listPush(List* list, unsigned int value)
{
	Element* newHead = (Element*) malloc(sizeof(Element));
	newHead->value = value;
	newHead->pSuccessor = list->head;
	list->head = newHead;
}

/* d)
 * Der Nachfolger des Kopfes der Liste wird der neue Kopf der Liste.
 * Die Funktion gibt den alten Kopf der Liste zurück.
 */

Element* listPop(List* list)
{
	/*
	 * Element* element = list->head;
	 * list->head = list->head->pSuccessor;
	 * return element;
	*/

	return list->head->pSuccessor;
}

/* e)
 * Die Funktion gibt die Werte der in der Liste enthaltenen Elemente
 * durch Leerzeichen getrennt auf der Konsole aus. Die Ausgabe erfolgt
 * dabei beginnend mit dem Kopf der Liste bis zum Ende der Liste. Ist
 * die Liste jedoch leer (kopf==NULL) soll der Text „Liste leer!“ ausgegeben
 * werden. Am Ende soll in jedem Fall ein Zeilenumbruch ausgegeben werden.
 */


void listPrint(List* list)
{
	Element* element = list->head;

	if(element == 0)
	{
		printf("Liste leer!\n");
	}

	while(element != NULL)
	{
		printf("%d ", element->value);

		element = element->pSuccessor;

		if(element == NULL)
		{
			printf("\n");
		}
	}

}

/* f)
 * Die Funktion soll die übergebene Liste mit anzahlWerte Elemente füllen.
 * Das Einfügen der Elemente soll mittels der push - Funktion erfolgen.
 * Die Zufallszahlen sollen zwischen einschließlich min und max liegen.
 * Für die Generierung der Zahlen soll die Funktion rand() aus der stdlib.h
 * verwendet werden. Vor dem Ziehen der ersten Zufallszahl soll der Seed
 * auf den übergebenen Wert gesetzt werden.
 */

void listFillRandom(List* list, int seed, int anzahlWerte, int min, int max)
{
	srand(seed);
	int randomNumber = 0;

		for (int i = 0; i < anzahlWerte; i++)
		{
			do
			{
				randomNumber = rand() % max;
			}
			while(!(randomNumber >= min));

			listPush(list, randomNumber);
		}
}

//Aufgabe 2
/* a)
 * Die Funktion durchsucht die übergebene Liste nach einem Element mit
 * dem angegebenen Wert. Ist ein entsprechendes Listenelement vorhanden
 * wird der Zeiger auf dieses Element zurückgegeben. Gibt es kein
 * Listenelement mit diesem Wert so wird NULL zurückgegeben.
 */

Element* listFindElement(List* list, unsigned int value)
{
	Element* element = list->head;

	while(element != NULL)
	{
		if(element->value == value)
		{
			break;
		}
		else{
			element = element->pSuccessor;
		}
	}
	return element;
}

/* b)
 * Die Funktion durchsucht die übergebene Liste, beginnend vom Kopf,
 * nach einem Element mit dem angegebenen Wert. Dabei wird die Position
 *  des Elements innerhalb der Liste „mitgezählt“. Der Kopf entspricht dabei
 * Position 0, der Nachfolger des Kopfes entspricht Position 1, usw.
 * Ist ein entsprechendes Listenelement vorhanden wird die Position zurückgegeben.
 * Gibt es kein Listenelement mit diesem Wert so wird -1 zurückgegeben.
 */

int listGetIndexOfElement(List* list, unsigned int value)
{
	Element* element = list->head;
	int index = 0;

	while(element != NULL)
	{
		if(element->value == value)
		{
			break;
		}
		element = element->pSuccessor;

		index++;
	}
	if(element == NULL)
	{
		index = -1;
	}
	return index;
}

/* c)
 * Die Funktion durchläuft die Liste beginnend vom Kopf mit Index 0 bis zum
 * Element mit dem entsprechenden Index und gibt einen Zeiger auf das Element
 * zurück. Ist die Liste leer oder kürzer, so dass ein Folgeelement den Wert
 * NULL hat, wird NULL zurückgegeben.
 */

Element* listGetElementAtIndex(List* list, unsigned index)
{
	Element* element = list->head;
	for (int i = 0; i < index; i++)
		{
			if (element == NULL)
			{
				break;
			}
			else {
				element = element->pSuccessor;
			}
		}
		return element;
}

//Aufgabe 3
/* a)
 * Die Funktion vertauscht die Werte der Elemente an Index aIndex und Index
 * bIndex miteinander. Schlägt die Vertauschung fehl, weil eines der beiden
 * Elemente nicht existiert (Liste ist kürzer) wird FALSE zurückgegeben.
 * Ansonsten wird TRUE zurückgegeben. Zu Übungszwecken bietet es sich an die
 * Vertauschung über eine zeigerbasierte Lösung durchzuführen.
 */

boolean listSwapElements(List* list, unsigned int aIndex, unsigned int bIndex)
{

}

/* b)
 * Die Funktion durchsucht die Liste beginnend vom Kopf zum Ende nach einem
 * Element mit entsprechendem Value. Ist das Element nicht in der Liste enthalten
 * wird FALSE zurückgegeben. Ist das Element in der Liste enthalten, so wird dieses
 * gelöscht und sein Speicher freigegeben. Vorher ist allerdings der Nachfolgerzeiger
 * des Vorgängerelements auf den Nachfolger des Elements zu setzen (siehe GDI Skript).
 */

boolean listDeleteElement(List* list, unsigned int value)
{
	Element* element = list->head;

	if(element == NULL)
	{
		return FALSE;
	}

	while(element != NULL)
	{
		if(element->value == value)
		{
			free(element);
			return TRUE;
			break;
		}
		else{
			element = element->pSuccessor;
		}

	}
}
