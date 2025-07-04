#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	BinarySearchTree* root = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char* token = NULL;
		float income = 0; int group = 0, id =0;
		char name[LINE_SIZE];
		char buffer[LINE_SIZE];

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			id = atoi(token);

			token = strtok(NULL, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* stud = createStudent(name, group, income, id);

			upsert(&root, stud);
		}

		printf("\n---------Preorder---------\n");
		preOrder(root);
		printf("\n---------Inorder---------\n");
		inOrder(root);

		//move students from the tree in a simple linked list, storing them in descending order by their id
		SNode* list = NULL;
		convertTreeToCircularLinkedList(root, &list);

		if (list != NULL) {
			printf("\n---------Circular List ---------\n");
			SNode* current = list;
			do {
				printStudent(current->info);
				current = current->next;
			} while (current != list);
		}
	}
}