#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	FILE* pFile = fopen("Data.txt", "r");
	
	PriorityQueue pQueue = { .items = NULL, .position = -1, .size = 0 };

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
			enqueue(&pQueue, stud);

			printf("\n-------------------NEXT ITERATION---------------\n");
			for (int i = 0; i < pQueue.position; i++)
			{
				printStudent(pQueue.items[i]);
			}
		}

		changePrio(&pQueue, 4, 1090);

		printf("\n-----------------DEQUEING DATA STRUCTURES---------------\n");
		Student* value = NULL;
		while ((value = dequeue(&pQueue)) != NULL)
		{
			printStudent(value);
		}
	}
}