#include "StudentSystemManager.h"
void inputStudent(Node*head) {
    Node* fresh  = malloc(sizeof(Node));
    fresh ->next =  NULL;
    printf("请输入学生学号，姓名，成绩");
    scanf("%d%s%d",&fresh->student.stuNum, fresh->student.name,fresh->student.score);

    Node* move = head;
    while (move->next != NULL) {
        move = move->next;
    }
}

void welcome(){
    printf ("******************\n");
    printf ("*\t学生管理系统\t\n");
    printf("********************\n");
    printf ("*\t请选择列表功能\t*\n");
    printf ("******************\n");
    printf ("*\t1.录入学生信息\t*\n");
    printf ("*\t2.打印学生信息\t*\n");
    printf ("*\t3.统计学生人数\t*\n");
    printf ("*\t4.查找学生信息\t*\n");
    printf ("*\t5.修改学生信息\t*\n");
    printf ("*\t6.删除学生信息\t*\n");
    printf ("*\t7.按成绩排序\t*\n");
    printf ("*\t8.退出系统\t*\n");
    printf ("********************\n");
}