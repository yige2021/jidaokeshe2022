#ifndef PUBLIC_H
#define PUBLIC_H

//以下为公共变量，默认全部为0
extern int TOTAL_STATION;  //默认为5
extern int STRATEGY;       //默认为1，STRAGETY值含义：1 => FCFS，2 => SSTF，3 => SCAN
extern int DISTANCE;       //默认为2
extern int TIME;               //打印状态里的时间
extern int goal;               //在FCFS中是当前目标在队列中的编号，在SSTF中是目标站的编号
extern int TOTAL_LENGTH;  //默认为10
extern int stop;               //记录停站状态
extern int direction;          //行车方向、状态，1为顺时针，-1为逆时针，0为待命
extern int status;             //行车方向、状态，1为顺时针，2为逆时针，0为待命
extern int size;               //请求数量
void drive();                      //运行状态函数
int isArrive();                    //是否路过车站
int cacu(int now, int sta,int mn); //SSTF与SCAN通用，计算目前车站到目标车站的距离，并更新最短距离

#endif
