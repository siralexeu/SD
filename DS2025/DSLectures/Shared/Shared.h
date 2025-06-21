#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef union Reference
{
	unsigned char intRef;
	unsigned short extRef;
} Reference;
struct _Student
{
	Reference reference;
	char* name;
	unsigned int group;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;
typedef struct _BitReference
{
	short ref : 8;
	short uniId : 7;
	short type : 1;
} BitReference;

Student* createStudent(const char*, int, unsigned short);
void printStudent(Student* stud);
void deleteStudent(Student* stud);
unsigned char getIntRef(unsigned short);

struct _Node {
	Student* info;
	struct _Node* next;
};
typedef struct _Node Node;

typedef struct HTable
{
	Student** items;
	int size;
}HashTable;

void resizeHT(HashTable*);
void putHashTable(HashTable*, Student*);
void displayStudents(HashTable);


//Priority Queue definitions
#define PQUEUE_SIZE 3
typedef struct PQueue
{
	Student** items;
	int size;
	int position;
}PriorityQueue;

void enqueue(struct PQueue*, Student*);
Student* dequeue(struct PQueue*);
void changePrio(struct PQueue*, int, int);


//Generic Trees
typedef struct TreeNode {
	Student* data;                   // Data stored in the node
	struct TreeNode* parent;    // Pointer to the parent node
	struct TreeNode** children; // Array of pointers to child nodes
	int noDescendants;          // Number of children of this node
} TreeNode;
TreeNode* createNode(Student*);
void insertChild(TreeNode*, int, Student*);
void printTree(TreeNode*, int);

//BinarySearchTree definitions
typedef struct BST
{
	Student* data;
	struct BST* left;
	struct BST* right;
}BinarySearchTree;

void upsert(BinarySearchTree**, Student*);
void preOrder(BinarySearchTree*);
void inOrder(BinarySearchTree*);
void postOrder(BinarySearchTree*);
void deleteNodeByKey(BinarySearchTree**, unsigned short);
