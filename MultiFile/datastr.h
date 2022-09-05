#ifndef DATASTR_H
#define DATASTR_H

#include "default.h"

typedef struct node { //采用双向循环链表模拟轨道；下面是定义以及相关变量与函数
    int pos;
    int sta;
    struct node *next;
    struct node *prev;
} track;

typedef struct { //FCFS和SSTF通用的请求队列，可存储一个请求的站点和类型
    int type;
    int sta;
} STATION1;

typedef struct { //存储站点信息的INFO数组
    int target;           //公交车上对车站请求
    int clockwise;        //顺时针车站请求  0表示无，1表示有
    int counterclockwise; //逆时针车站请求
} sta;

extern int reqNum;
extern int queue[MAX_REQUEST]; //SCAN专用请求队列，仅存放请求目标站编号
extern sta INFO[MAX_STATION + 1];
extern STATION1 req[MAX_REQUEST];
extern track *position;
extern track *createList();

void deleteList();                                   //程序运行结束时删链表
void addINFO(int commandType, int value);            //为INFO数组添加信息
void delINFO(int type, int sta);                     //为INFO数组删除信息
void push_back(int commandType, int value);          //FCFS和SSTF通用，请求入队
int isExist(int type, int value);                    //FCFS和SSTF通用，判断某一请求是否在队列，不忽略类型
int isExist_SSTF(int value);                         //SSTF专用，判断某一指定站点编号的请求是否在队列，忽略类型
void push_SCAN(int queue[], int *size, int value);   //SCAN专用，请求入队
void pop_FCFS();                                     //某一请求出队
void pop_SCAN(int queue[], int *size, int value);
int isExist_SCAN(int queue[], int *size, int value); //SCAN专用，判断某一请求是否存在于队列中

#endif
