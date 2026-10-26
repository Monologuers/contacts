#include <stdio.h>
#include <stdlib.h>  
#include<conio.h>
//学生信息
typedef struct _Student
{
    int stuNum;
    char name[20]; 
    int score;
}Student;

//节点信息
typedef struct _Node
{
    Student student;
    struct _Node* next;

}Node;

void welcome();

void inputStudent(Node*head);

void printStudent(Node* head);

void countStudent(Node*head);

void findStudent(Node*head);

