#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct Banca {
	int cod;
	char* denumire;
	float profit;
	int nrClienti;
	char* strada;
}Banca;

typedef struct Nod {
	Banca info;
	struct Nod* next;
}Nod, *PNod;

Banca* creareBanca(int cod, const char* denumire, float profit, int nrClienti, const char* strada) {
	Banca* b = (Banca*)malloc(sizeof(Banca));
	b->cod = cod;
	b->denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(b->denumire, denumire);
	b->profit = profit;
	b->nrClienti = nrClienti;
	b->strada = (char*)malloc(sizeof(char) * (strlen(strada) + 1));
	strcpy(b->strada, strada);
	return b;
}

void afisareBanca(Banca* b) {
		printf("Cod: %d, Denumire: %s, Profit: %5.2f, NrClienti: %d, Strada: %s\n", b->cod, b->denumire, b->profit, b->nrClienti, b->strada);
}
void afisareLista(Nod* head) {
	Nod* aux = head;
	while (aux != NULL) {
		afisareBanca(&aux->info);
		aux = aux->next;
	}
	
}
Nod* adaugareSfarsit(Nod* head, Banca info){
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = info;
	nou->next = NULL;
	if (head == NULL) {
		return nou;
	}
	else {
		Nod* aux = head;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = nou;
	}
	return head;
	
}

Nod* adaugareInceput(Nod* head, Banca info) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = info;
	nou->next = head;
	return nou;
}
void freeLista(Nod* head) {
	while (head != NULL) {
		Nod* aux = head;
		head = head->next;
		free(aux->info.denumire);
		free(aux->info.strada);
		free(aux);
	}
}
void main() {
	Nod* lista = NULL;

	FILE* f = fopen("banca.txt", "r");
	if (f) {
		char delimiter[] = ",";
		char* token = NULL;
		char buffer[256], denumire[256], strada[256];
		while (fgets(buffer, sizeof(buffer), f)) {
			token = strtok(buffer, delimiter);
			int cod = atoi(token);

			token = strtok(NULL, delimiter);
			strcpy(denumire, token);

			token = strtok(NULL, delimiter);
			float profit = atof(token);

			token = strtok(NULL, delimiter);
			int nrClienti = atoi(token);

			token = strtok(NULL, delimiter);
			strcpy(strada, token);

			Banca* b = creareBanca(cod, denumire, profit, nrClienti, strada);
			if (b != NULL) {
				lista = adaugareSfarsit(lista, *b);
			}
		}
		//fclose(f);

		afisareLista(lista);
		freeLista(lista);
	}

}
