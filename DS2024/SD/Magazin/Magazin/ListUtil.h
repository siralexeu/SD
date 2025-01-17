#pragma once
#include "main.h"
typedef struct Magazin {
	int id;
	char* denumire;
	char* localitate;
	float suprafata;
	int nr_angajati;
}Magazin;

Magazin* createMagazin(int id, const char* denumire, const char* localitate, float suprafata, int nr_angajati)
{
	Magazin* mag = NULL;
	mag = (Magazin*)malloc(sizeof(Magazin));
	mag->id = id;
	mag->denumire = (char*)malloc(strlen(denumire) + 1);
	strcpy(mag->denumire, denumire);
	mag->localitate = (char*)malloc(strlen(localitate) + 1);
	strcpy(mag->localitate, localitate);
	mag->suprafata = suprafata;
	mag->nr_angajati = nr_angajati;
	return mag;
}
void printMagazin(Magazin* mag)
{
	if (mag != NULL) {
		printf("Id: %d  Denumire: %s  Localitate: %s  Suprafata: %0.2f  Nr angajati: %d\n",
		mag->id, mag->denumire, mag->localitate, mag->suprafata, mag->nr_angajati);
	}
}
void deleteMagazin(Magazin* mag)
{
	if (mag != NULL) {
		free(mag->denumire);
		free(mag->localitate);
		free(mag);
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
typedef struct Node {
	Magazin* info;
	struct Node* next;
}ListNode, *PListNode;

ListNode* createListNode(Magazin* mag)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->info = mag;
	node->next = NULL;
	return node;
}
void deleteNode(ListNode* node)
{
	if (node != NULL) {
		deleteMagazin(node->info);
		free(node);
	}
}
ListNode* insertSorted(ListNode* headList, Magazin* mag)
{
	ListNode* node = createListNode(mag);
	if (!node) return headList;
	// Inserare la începutul listei sau în fața unui element existent
	if (!headList || headList->info->id > mag->id) {
		node->next = headList;
		return node;
	}

	ListNode* current = headList;
	while (current->next && current->next->info->id < mag->id) {
		current = current->next;
	}
	// Inserare în mijlocul sau la sfârșitul listei
	node->next = current->next;
	current->next = node;
	return headList;
}
void displayList(ListNode* headList)
{
	while (headList)
	{
		printMagazin(headList->info);
		headList = headList->next;
	}
}
void freeList(ListNode* headList) {
	while (headList) {
		ListNode* temp = headList;
		headList = headList->next;
		deleteNode(temp);
	}
}
void updateMagazin(PListNode* pHeadList, const char* oldName, const char* localitate, const char* newName) {
	ListNode* current = *pHeadList;
	while(current) {
		if (strcmp(current->info->denumire, oldName) == 0 && strcmp(current->info->localitate, localitate) == 0) {
			free(current->info->denumire);
			current->info->denumire = (char*)malloc(strlen(newName) + 1);
			strcpy(current->info->denumire, newName);
			return;
		}
		current = current->next;
	}
	printf("Magazinul cu denumirea '%s' și localitatea '%s' nu a fost găsit.\n", oldName, localitate);
}
float angajatiAvg(PListNode pHeadList, const char* localitate) {
	int angajati = 0;
	int magazine = 0;
	ListNode* current = pHeadList;
	while (current) {
		if (strcmp(current->info->localitate, localitate) == 0 ) {
			angajati += current->info->nr_angajati;
			magazine++;
		}
		current = current->next;
	}
	if (magazine == 0) {
		printf("Nu exista magazine in localitatea specificata.\n");
		return 0.0f;
	}
	return (float)angajati / magazine;
}





