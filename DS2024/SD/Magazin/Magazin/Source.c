#define _CRT_SECURE_NO_WARNINGS
#include "ListUtil.h"
#include "HashUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 256

void main()
{
	ListNode* list = NULL;
	HashNode** hash = NULL;

	FILE* pFile = fopen("data.txt", "r");
	if (pFile)
	{
		char delimiter[] = ",";
		char* token = NULL;
		char buffer[LINE_SIZE], denumire[LINE_SIZE], localitate[LINE_SIZE];
		while (fgets(buffer, sizeof(buffer), pFile))
		{
			token = strtok(buffer, delimiter);
			int id = atoi(token);
			token = strtok(NULL, delimiter);
			strcpy(denumire, token);
			token = strtok(NULL, delimiter);
			strcpy(localitate, token);
			token = strtok(NULL, delimiter);
			float suprafata = atof(token);
			token = strtok(NULL, delimiter);
			int nr_angajati = atoi(token);
			Magazin* mag = createMagazin(id, denumire, localitate, suprafata, nr_angajati);
			//list = insertSorted(list, mag);
			//printMagazin(mag);
			insertHash(&hash, mag);
		}

		//displayList(list);
		//updateMagazin(&list, "La Nicusor", "Nehoiu", "La Nicu 2");
		//printf("\nLista dupa actualizare:\n");

		/*const char* loc = "Iasi";
		float angajati = angajatiAvg(list, loc);
		if (angajati > 0) {
			printf("\nNumarul mediu de angajati per magazin in localitatea %s: %.2f\n", loc, angajati);
		}*/
		/*deleteMagazine(&list, "La Nicusor");
		printf("\nLista dupa actualizare:\n");
		displayList(list);*/
		//freeList(list);
		displayHashTable(&hash);
		/*updateLocalitate(hash, "La Nicusor", "Nehoiu", "Lehliu");
		printf("\nAfter updating the locality:\n");
		displayHashTable(hash);	*/
		for (int i = 0; i < HASHT_SIZE; i++) {
			HashNode* current = hash[i];
			while (current) {
				HashNode* temp = current;
				current = current->next;
				deleteMagazin(temp->info);
				free(temp);
			}
		}	
		free(hash);
	} 
	
}