﻿#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct _Student
{
	float income;
	short group;
	char* name;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;

struct _Node
{
	struct _Node* prev;
	Student* info;
	struct _Node* next;
};

typedef struct _Node	Node;
typedef struct _Node*	PNode;

Student* createStudent(const char*, short, float);
void deleteStudent(PStudent);
void printStudent(PStudent);

//simple lists functions
void insertTailList(Node**, Student*);
void printSimpleList(Node*);
void deleteStudByName(Node**, const char*);

//STACK functions
void pushStudent(Node**, Student*);
Student* popStudent(Node**);
Student* peekStudent(Node*);

void convertArrayToCircularSortedDoublyLinkedList(Student**, Node**);

//TEST functions
void putNode(Node**, Student*);

float computeAverage(Node*, int);
void findHighestIncome(Node*, Student**);

void printQueue(Node* head);