#ifndef STRATEGY_H
#define STRATEGY_H

extern int status;             //行车方向、状态，1为顺时针，2为逆时针，0为待命
extern int size;               //请求数量

void FCFS(int commandType, int value); //FCFS策略入口函数
void setDirection();                   //无请求时初始化公交车
void SSTF(int commandType, int value); //SSTF策略入口函数
void SCAN(int commandType, int value); //SCAN策略入口函数
void initBus();                        //初始化运行方向以及目标，用于公交车从待命状态启动
void busStop();                        //停车函数
void setStatus2();                     //SSTF用更新行车状态
void setStatus3();                     //SCAN用更新行车状态
void arrStation();                     //到达车站函数
int isStation();                       //判断是否是路过车站
int getDistance(int value);            //获取某车站与公交车当前位置在目前行驶方向上的距离

#endif