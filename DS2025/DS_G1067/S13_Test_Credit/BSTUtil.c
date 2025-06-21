#include "Shared.h"
BinarySearchTree* createBSTNode(Student* stud)
{
	BinarySearchTree* newNode = malloc(sizeof(BinarySearchTree));
	if (newNode != NULL)
	{
		newNode->data = stud;
		newNode->left = newNode->right = NULL;
	}
	return newNode;
}

void preOrder(BinarySearchTree* root)
{
	if (root)
	{
		printStudent(root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(BinarySearchTree* root)
{
	if (root)
	{
		inOrder(root->left);
		printStudent(root->data);
		inOrder(root->right);
	}
}
void postOrder(BinarySearchTree* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		printStudent(root->data);
	}
}
int getHeight(BinarySearchTree* expectedNode) {
	if (expectedNode == NULL) return 0;
	return 1 + max(getHeight(expectedNode->left), getHeight(expectedNode->right));
}
void leftRotation(BinarySearchTree** pivot)
{
	BinarySearchTree* desc = (*pivot)->right;
	(*pivot)->right = desc->left;
	desc->left = (*pivot);
	(*pivot) = desc;
}

void rightRotation(BinarySearchTree** pivot)
{
	BinarySearchTree* desc = (*pivot)->left;
	(*pivot)->left = desc->right;
	desc->right = (*pivot);
	(*pivot) = desc;
}

void rebalanceRoot(BinarySearchTree** pivot) {
	char calculatedBF = getHeight((*pivot)->left) - getHeight((*pivot)->right);
	(*pivot)->bFactor = calculatedBF;
	if ((*pivot)->bFactor == +2)
	{
		BinarySearchTree* desc = (*pivot)->left;
		if (desc->bFactor == +1) {
			//right rotation in pivot
			rightRotation(pivot);
		}
		else if (desc->bFactor == -1) {
			//
			leftRotation(&(*pivot)->left);
			rightRotation(pivot);

		}
	}
	else if ((*pivot)->bFactor == -2)
	{
		BinarySearchTree* desc = (*pivot)->right;
		if (desc->bFactor == +1) {

			rightRotation(&(*pivot)->right);
			leftRotation(pivot);
		}
		else if (desc->bFactor == -1) {
			//left rotation in pivot
			leftRotation(pivot);
		}

	}
}

void upsert(BinarySearchTree** root, Student* stud)
{
	if (*root == NULL)
		*root = createBSTNode(stud);
	else
	{
		if ((*root)->data->id > stud->id)
			upsert(&(*root)->left, stud);
		else if ((*root)->data->id < stud->id)
			upsert(&(*root)->right, stud);
		else
		{
			printf("Key already present, updating it!");
			(*root)->data = stud;
		}
	}
	rebalanceRoot(root);
}
void deleteFullNode(BinarySearchTree** root, BinarySearchTree** desc)
{
	if ((*desc)->right)
		deleteFullNode(root, &(*desc)->right);
	else
	{
		deleteStudent((*root)->data);
		(*root)->data = (*desc)->data;
		BinarySearchTree* tmp = *desc;
		*desc = tmp->left;
		free(tmp);
	}
}
void deleteNodeByKey(BinarySearchTree** root, unsigned short key)
{
	if (*root != NULL)
	{
		if ((*root)->data->id > key)
			deleteNodeByKey(&(*root)->left, key);
		else if ((*root)->data->id < key)
			deleteNodeByKey(&(*root)->right, key);
		else
		{
			if ((*root)->left == NULL && (*root)->right == NULL)
			{
				deleteStudent((*root)->data);
				free(*root);
				*root = NULL;
			}
			else if ((*root)->left == NULL || (*root)->right == NULL)
			{
				BinarySearchTree* tmp = (*root);
				(*root) = (*root)->left ? (*root)->left : (*root)->right;
				deleteStudent(tmp->data);
				free(tmp);
			}
			else
			{
				deleteFullNode(root, &(*root)->left);
			}
		}
	}
}
void convertTreeToCircularLinkedList(BinarySearchTree* root, SNode** list)
{
	if (root == NULL) return;

	convertTreeToCircularLinkedList(root->left, list);

	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode != NULL) {
		Student* studentCopy = createStudent(root->data->name, root->data->group,
			root->data->income, root->data->id);
		newNode->info = studentCopy;

		if (*list == NULL) {
			*list = newNode;
			newNode->next = newNode;
		}
		else {
			SNode* current = *list;
			while (current->next != *list) {
				current = current->next;
			}
			newNode->next = *list;
			current->next = newNode;
			*list = newNode;
		}
	}

	convertTreeToCircularLinkedList(root->right, list);
}

