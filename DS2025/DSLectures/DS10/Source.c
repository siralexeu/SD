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
		unsigned short reference = 0, group = 0;
		char name[LINE_SIZE], buffer[LINE_SIZE];

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			reference = atoi(token);

			Student* stud = createStudent(name, group, reference);

			upsert(&root, stud);
		}

		//printf("\n-----PRE------\n");
		//preOrder(root);
		printf("\n-----IN------\n");
		inOrder(root);

		deleteNodeByKey(&root, 33900);

		printf("\n-----IN------\n");
		inOrder(root);

		//printf("\n-----POST------\n");
		//postOrder(root);
	}
}