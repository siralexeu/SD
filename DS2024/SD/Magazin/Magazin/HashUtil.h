#pragma once
#include "main.h"
#include "ListUtil.h"
typedef struct HashN {
	Magazin* info;
	struct HashN* next;
}HashNode,*PHashNode;
#define HASHT_SIZE 26
HashNode* createHashNode(Magazin* info)
{
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	node->info = info;
	node->next = NULL;
	return node;
}
int fHash(const char* key) {
	return key[0] % HASHT_SIZE;
}
void deleteHash(HashNode** hashTable, const char* key) {
	int index = fHash(key);
	HashNode* collisionList = hashTable[index];
	if (collisionList != NULL) {
		if (strcmp(collisionList->info->denumire, key) == 0) {
			hashTable[index] = collisionList->next;
			deleteMagazin(collisionList->info);
			free(collisionList);
		}
		else {
			while (collisionList->next) {
				if (strcmp(collisionList->next->info->denumire, key) == 0) {
					HashNode* tmp = collisionList->next;
					collisionList->next = tmp->next;
					deleteMagazin(tmp->info);
					free(tmp);
					break;
				}
				collisionList = collisionList->next;
			}
		}
	}
}
void insertHash(HashNode*** hashTable, Magazin* mag) {
	if (*hashTable == NULL) {
		*hashTable = (HashNode**)malloc(sizeof(HashNode*) * HASHT_SIZE);

		memset(*hashTable, 0, sizeof(HashNode*) * HASHT_SIZE);
	}
	HashNode* node = createHashNode(mag);
	int hashValue = fHash(mag->localitate);

	node->next = (*hashTable)[hashValue];
	(*hashTable)[hashValue] = node;
}

void displayHashTable(HashNode** hashTable) {
	if (hashTable != NULL) {
		for (int i = 0; i < HASHT_SIZE; i++) {
			if (hashTable[i] != NULL) {
				HashNode* list = hashTable[i];
				while (list) {
					printMagazin(list->info);
					list = list->next;
				}
			}
		}
	}
}
void updateLocalitate(HashNode** hashTable, const char* denumire, const char* localitate, const char* newLoc) {
	int index = fHash(localitate);
	HashNode* current = hashTable[index];
	while (current) {
		if (strcmp(current->info->denumire, denumire) == 0 && strcmp(current->info->localitate, localitate) == 0) {
			free(current->info->localitate);
			current->info->localitate = (char*)malloc(strlen(newLoc) + 1);
			strcpy(current->info->localitate, newLoc);
			return;
		}
		current = current->next;
	}
	printf("Magazinul cu denumirea '%s' și localitatea '%s' nu a fost găsit.\n", denumire, localitate);
}