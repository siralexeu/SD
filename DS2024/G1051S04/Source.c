#define _CRT_SECURE_NO_WARNINGS
//#include "ListUtil.h"
//#include "StackUtil.h"
//#include "QueueUtil.h"
//#include "PQueueUtil.h"
//#include "HashUtil.h"
#include "TreeUtil.h"
//#include "GraphUtil.h"
#define LINE_SIZE 256

void main()
{
	//ListNode* list = NULL; //lista

	//StackNode* stack = NULL; //stiva

	//QueueNode* queue = NULL; //coada

	/*PriorityQueue pQueue = { .items = NULL, .size = 0, .currentIndex = 0 };
	PPriorityQueue ppQueue = NULL;*/ //coada de prioritate

	//HashNode* hashTable = NULL; //tabela de dispersie

	BinarySearchTree* root1 = NULL;  
	PBinarySearchTree root = NULL; //arbore binar de cautare

	/*Vertex* graph = NULL;
	Student* students[10];
	memset(students, 0, sizeof(students));*/ //graf

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile)
	{
		char delimiter[] = ",";
		char* token = NULL;
		float income; int index = 0;
		unsigned short reference;
		char buffer[LINE_SIZE], name[LINE_SIZE];
		while (fgets(buffer, sizeof(buffer), pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);
			token = strtok(NULL, delimiter);
			income = atof(token);
			token = strtok(NULL, delimiter);
			reference = atoi(token);
			Student* stud = createStudent(name, income, reference);
			
			//lista simpla inlantuita
			//list = insertHead_SLNode(list, stud);

			//lista dubla inlantuita
			//list = insertTail_DLNode(list, stud);

			//stiva
			//pushNode(&stack, stud);

			//coada
			//putNode(&queue, stud);

			//coada de prioritate
			//enque(&pQueue, stud);

			//tabela de dispersie
			//putHT(&hashTable, stud);

			//arbore binar de cautare
			upsert(&root, stud);

			//graf
			//students[index++] = stud;
		}
		//data structure operation
		
		//SingleLinkedList 
		/*displayList(list);
		deleteNodeByKey(&list, "Popa Maria");
		printf("\nLista after delete Popa Maria\n");
		deleteList(&list);*/

		//DoubleLinkedList
		//displayDList(list);
		/*printf("\nLista after delete Albu Cristina\n");
		deleteNodeByKeyDL(&list, "Albu Cristina");
		deleteList(&list);*/
		/*ListNode* headDL = convertToMirroredList(list);
		displayDList(headDL);*/	

		//StackUtil
		//displayStack(&stack);
		/*Student* peekStudent = peekNode(stack);
		if (peekStudent != NULL)
		{
			printf("Top element of the stack (peeked):\n");
			printStudent(peekStudent);
		}
		Student* popStudent = popNode(&stack);
		if (popStudent != NULL)
		{
			printf("\nStack after popping the top element:\n");
			free(popStudent);
			//displayStack(&stack);
			deleteStack(&stack);
		}*/

		//QueueUtil
		/*displayQueue(&queue);
		Student* peekStudent = peekNode(queue);
		if (peekStudent != NULL)
		{
			printf("\nFirst element in the queue (peeked):\n");
			printStudent(peekStudent);
		}
		Student* getStudent = getNode(&queue);
        if (getStudent != NULL)
        {
            printf("\nRemoved element from the queue (get):\n");
            printStudent(getStudent);
            free(getStudent);
        }*/

		//PQueueUtil
		/*displayQueue(&queue);
		printf("Priority Queue contents:\n");
		for (int i = 0; i < pQueue.currentIndex; i++)
		{
			printStudent(pQueue.items[i]);
		}
		Student* testStudent = createStudent("Test Student", 5000.0, 300);
		pQueue.items[pQueue.currentIndex] = testStudent;
		ReheapUp(&pQueue, pQueue.currentIndex);
		pQueue.currentIndex++;
		printf("\nPriority Queue contents after adding Test Student:\n");
		for (int i = 0; i < pQueue.currentIndex; i++)
		{
			printStudent(pQueue.items[i]);
		} */

		//HashUtil
		/*Student* info = getHT(hashTable, "Popa Maria");
		printStudent(info); 
		printf("\nHashTable after delete Popa Maria:\n");
		deleteHT(hashTable, "Popa Maria");*/
		//printHashTable(hashTable);
		/*deleteHT(hashTable, "Popa Maria");
		printf("\nHashTable after delete Popa Maria:\n");
		printHashTable(hashTable);*/
		/*int size = 0;
		Student** masiv = convertHTToArray(hashTable, &size);
		for (int i = 0; i < size; i++)
		{
			printStudent(masiv[i]);
			//size++; //eroare 
		}
		free(masiv);*/

		//TreeUtil
		displayTreeStructure(root, 0);
		deleteNodeByKey(&root, 255);
		displayTreeStructure(root, 0);

		//GraphUtil
		/*addEdge(&graph, students[0], students[1]);
		addEdge(&graph, students[0], students[4]);
		addEdge(&graph, students[0], students[5]);
		addEdge(&graph, students[1], students[3]);
		addEdge(&graph, students[2], students[3]);
		addEdge(&graph, students[2], students[4]);
		addEdge(&graph, students[3], students[5]);
		addEdge(&graph, students[4], students[5]);
		displayGraph(graph);*/


	}	
}