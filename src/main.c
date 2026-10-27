#include <stdio.h>
#include <stdlib.h>  
#include "StudentSystemManager.h"

int main(){
    //创建头结点
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    loadStudent(head);

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
        countStudent(head);
        break;
        case '4':// 查找学生信息
        findStudent(head);
        break;
        case '5': //修改学生信息
            modifyStudent(head);
        break;
        case '6': //删除学生信息
            deleteStudent(head);
        break;
        case '7': //按成绩排序
        sortStudent(head);
        break;
        case '8'://退出系统
            system("cls");
            printf("baibai!\n");
            exit(0);

        break;
        default:
            printf("请重新输入：\n");
        break;
      }
      }
    return 0;
}

