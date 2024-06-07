#pragma once
#include "main.h"
#include "DataUtil.h"
typedef struct NodeL
{
	struct NodeL* prev;
	Student* info;
	struct NodeL* next;
}ListNode, * PListNode;

ListNode* createListNode(Student* stud)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = node->prev = NULL;
	return node;
}
void deleteNode(ListNode* node)
{
	if (node != NULL)
	{
		deleteStudent(node->info);
		free(node);
	}
}
//void insertHead_SLNode(ListNode** headList, Student* stud)
//{
//	ListNode* node = createListNode(stud);
//	node->next = *headList;
//	*headList = node;
//}
ListNode* insertHead_SLNode(ListNode* headList, Student* stud)
{
	ListNode* node = createListNode(stud);
	node->next = headList;
	return node;
}
void displayList(ListNode* headList)
{
	while (headList)
	{
		printStudent(headList->info);
		headList = headList->next;
	}
}
void deleteNodeByKey(PListNode* pHeadList, const char* key)
{
	if (*pHeadList != NULL)
	{
		if (strcmp((*pHeadList)->info->name, key) == 0)
		{
			ListNode* tmp = *pHeadList;
			*pHeadList = tmp->next;
			deleteNode(tmp);
		}
		else
		{
			ListNode* iterator = *pHeadList;
			while (iterator->next != NULL &&
				strcmp(iterator->next->info->name, key) != 0)
			{
				iterator = iterator->next;
			}
			if (iterator->next != NULL)
			{
				ListNode* tmp = iterator->next;
				iterator->next = tmp->next;
				deleteNode(tmp);
			}
		}
	}
}
void deleteNodeByKeyDL(PListNode* pHeadList, const char* key)
{
	if (*pHeadList != NULL)
	{
		// Cautam nodul care contine cheia
		ListNode* current = *pHeadList;
		while (current != NULL && strcmp(current->info->name, key) != 0)
		{
			current = current->next;
		}

		// Dacă nodul a fost găsit
		if (current != NULL)
		{
			// Dacă nodul este primul din lista
			if (current->prev == NULL)
			{
				*pHeadList = current->next;
				if (*pHeadList != NULL) {
					(*pHeadList)->prev = NULL;
				}
			}
			else
			{
				current->prev->next = current->next;
				if (current->next != NULL) {
					current->next->prev = current->prev;
				}
			}
			deleteNode(current);
		}
	}
}

void deleteList(ListNode** pHeadList)
{
	while (*pHeadList)
	{
		ListNode* tmp = *pHeadList;
		*pHeadList = (*pHeadList)->next;
		printStudent(tmp->info);
		deleteNode(tmp);
	}
}
//DoubleLinkedList functions
ListNode* insertTail_DLNode(ListNode* headList, Student* stud)
{
	ListNode* node = createListNode(stud);
	ListNode* result = headList;
	if (headList == NULL)
	{
		result = node;
	}
	else
	{
		while (headList->next)
			headList = headList->next;
		node->prev = headList;
		headList->next = node;
	}
	return result;
}

ListNode* convertToMirroredList(ListNode* list)
{
	//parcuregere lista initiala (simpla inlantuita)
	ListNode* headDL = NULL;
	ListNode* middle = NULL;
	while (list != NULL)
	{
		Student* info = list->info;
		ListNode* node1 = createListNode(info);
		ListNode* node2 = createListNode(info);
		node1->next = node2;
		node2->prev = node1;
		if (headDL == NULL)
		{
			node1->prev = node2;
			node2->next = node1;
			headDL = middle = node1;
		}
		else
		{
			node1->prev = middle;
			node2->next = middle->next;
			middle->next = node1;
			node2->next->prev = node2;
			middle = node1;
		}
		list = list->next;
	}
	//procesare nod curent (acces info util)
	//creare a doua noduri pe baza info util
	//inserare in lista dubla inlantuita la mijloc
	return headDL;
}
void displayDList(ListNode* headDL)
{
	ListNode* first = headDL;
	if (first)
	{
		do
		{
			printStudent(headDL->info);
			headDL = headDL->next;
		} while (first != headDL);
	}
}