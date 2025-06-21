#include "Shared.h"
Node* createNode(Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = info;
		node->next = node->prev = NULL;
	}
	return node;
}
void putNode(Node** pHead, Student* pStud)
{
	Node* node = createNode(pStud);
	if (node != NULL)
	{
		if (*pHead == NULL)
			*pHead = node;
		else
		{
			Node* tmp = *pHead;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
	}
}
float computeAverage(Node* list, int groupNo) {
    Node* current = list;
    float sum = 0.0f;
    int count = 0;

    while (current != NULL) {
        if (current->info->group == groupNo) {
            sum += current->info->income;
            count++;
        }
        current = current->next;
    }

    if (count > 0) {
        return sum / count;
    }
    else {
        return 0.0f;
    }
}

void findHighestIncome(Node* list, Student** pStud) {
    if (pStud == NULL) return;

    Node* current = list;
    Student* best = NULL;
    float maxIncome = -1.0f; 

    while (current != NULL) {
        if (best == NULL || current->info->income > maxIncome) {
            best = current->info;
            maxIncome = best->income;
        }
        current = current->next;
    }

    *pStud = best;
}
void printQueue(Node* head) {
    Node* cur = head;
    while (cur) {
        printStudent(cur->info);
        cur = cur->next;
    }
}