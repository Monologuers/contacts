#include <stdio.h>
#include <stdlib.h>  
#include "StudentSystemManager.h"

int main(){
    //创建头结点
    Node* head = malloc(sizeof(Node));
    head->next = NULL;

while (1){

    welcome();

      char c = _getch();
      switch (c)
      {
        case '1'://录入学生信息
        inputStudent(head);
        break;
        case '2'://打印学生信息
        printStudent(head);
        break;
        case '3':// 统计学生信息
        countStudent(head):
        break;
        case '4':// 查找学生信息
        break;
        case '5': //修改学生信息
        break;
        case '6': //删除学生信息
        break;
        case '7'://按成绩排序
        break;
        case '8'://退出系统
        break;
        default:
        break;
      }
      }
    return 0;
}

