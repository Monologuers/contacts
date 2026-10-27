#include "StudentSystemManager.h"


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

void saveSStudent(Node* head) {
    FILE* file = fopen("./stu.info", "w");
    Node* move = head->next;
    while (move != NULL) {
        if (fwrite(&move->student, sizeof(Student), 1, file) != 1) {
            printf("写入失败\n");
            return;
        }
        move = move->next;
    }
    fclose(file);
}

void loadStudent(Node* head) {
    FILE* file = fopen("./stu.info", "r");
    if (!file) {
        printf("没有学生文件，跳过读取\n");
        return;

    }
    Node* fresh = (Node*)malloc(sizeof(Node));
    if (fresh != NULL) 
        fresh->next = NULL;

    
        Node* move = head;
    while (fread(&fresh->student, sizeof(Student), 1, file) == 1) {
        move->next = fresh;
        move = fresh;
        fresh = (Node*)malloc(sizeof(Node));
        if (fresh == NULL) break;
        fresh->next = NULL;
    }
    free(fresh);
    fclose(file);
    printf("读取成功：\n");
}

void modifyStudent(Node* head) {
    printf("请输入要修改学生的学号：");
    int stuNum;
    scanf("%d", &stuNum);
    Node* move = head->next;
    while (move != NULL) {
        if (move->student.stuNum == stuNum) {
            printf("请输入姓名，成绩：\n");
            (void)scanf("%s%d", move->student.name, &move->student.score);
            printf(" 修改成功\n");
            //暂停程序
            system("pause");
            // 清空控制台
            system("cls");


        }
        move = move->next;
    }
    printf("未找到学生信息\n");
    //暂停程序
    system("pause");
    // 清空控制台
    system("cls");
}


void inputStudent(Node*head) {
    Node* fresh  = (Node *)malloc(sizeof(Node));

    if (fresh == NULL) {
        printf("内存分配失败！\n"); 
        return; // 直接退出函数，避免后续解引用
    }

    fresh ->next =  NULL;
    printf("请输入学生学号，姓名，成绩:\n");
   (void)scanf("%d%19s%d", &fresh->student.stuNum, fresh->student.name, &fresh->student.score);
   
    Node* move = head;
    while (move->next != NULL) {
        move = move->next;
    }
     //将学生插入尾部
     move->next = fresh;

     saveSStudent(head);

     //暂停程序
     system("pause");
     // 清空控制台
     system("cls");

}

void printStudent(Node* head){
    Node*move = head->next;
    while(move != NULL){
        printf("学号：%d姓名:%s 成绩：%d\n", move->student.stuNum, move->student.name, move->student.score);
        move = move->next;
    }

     //暂停程序
     system("pause");
     // 清空控制台
     system("cls");
    }

void countStudent(Node*head){
    int count = 0;
    Node* move = head->next;
    while(move !=NULL){
        count++;
        move = move->next;
    
    }
    printf("学生的总人数：%d\n",count);
    
     //暂停程序
     system("pause");
     // 清空控制台
     system("cls");

}

void findStudent(Node*head){
    printf("要查找学生的学号：");
    int stuNum;
    (void)scanf("%d",&stuNum);
    Node* move = head ->next;
    while (move != NULL){
     if (stuNum == move->student.stuNum) {
            printf("学号：%d 姓名：%s 成绩：%d\n", move->student.stuNum, move->student.name,move->student.score);
               
    //暂停程序
     system("pause");
     // 清空控制台
     system("cls");

     return;
     
     }
     move = move ->next;
    }
    printf ("未找到学生信息\n");
       //暂停程序
     system("pause");
     // 清空控制台
     system("cls");
}


void deleteStudent(Node* head){
    printf("请输入要删除的学生学号 ");
    int stuNum = 0;
    scanf("%d", &stuNum);

    Node* move = head;
    while (move ->next != NULL){
        if (move->next->student.stuNum == stuNum) {
            Node* tmp = move->next;
            move ->next  = move ->next->next;
            free(tmp);
            tmp = NULL;
            saveSStudent(head);
            //暂停程序
            system("pause");
            // 清空控制台
            printf("删除成功\n");
                return;
    }
        move = move->next;
    }
    printf("未找到学生信息\n");
    //暂停程序
    system("pause");
    // 清空控制台
    system("cls");
}

void sortStudent(Node* head) {
    Node* save = NULL;
    Node* move = NULL;
    for (Node* turn = head->next;turn->next != NULL;turn = turn->next) {
        for (Node* move = head->next; move->next != NULL; move = move->next) {
            if (move->student.score > move->next->student.score) {
                Student temp = move->student;
                move->student = move ->next->student;
                move->next->student = temp;
            }
        }
        save = move;
    }
    printStudent(head);

}



