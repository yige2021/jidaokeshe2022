#include "public.h"
#include "datastr.h"
#include "strategy.h"

int time = 0;               //打印状态里的时间
int goal = 0;               //在FCFS中是当前目标在队列中的编号，在SSTF中是目标站的编号
int TOTAL_STATION = 5;  //默认为5
int STRATEGY = 1;       //默认为1，STRAGETY值含义：1 => FCFS，2 => SSTF，3 => SCAN
int DISTANCE = 2;       //默认为2
int TOTAL_LENGTH = 10;  //默认为10
int stop = 0;               //记录停站状态
int direction = 0;

void drive() {                                                      //车辆运行函数
    if (STRATEGY == 1) {
        if (direction == 1) {
            position = position->next;
        }
        if (direction == -1) {
            position = position->prev;
        }
    }
    if (STRATEGY == 2 || STRATEGY == 3) {
        if (status == 1 && stop == 0) {
            position = position->next;
        }
        if (status == 2 && stop == 0) {
            position = position->prev;
        }
    }
}

int cacu(int now, int sta,int mn) {
    int dis = fmin(abs(now - sta), fmin(abs(TOTAL_STATION - now + sta), abs(TOTAL_STATION - sta + now)));

    return fmin(mn, dis);
}