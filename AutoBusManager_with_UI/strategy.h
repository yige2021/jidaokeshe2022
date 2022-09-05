#ifndef STRATEGY_H
#define STRATEGY_H

void FCFS(int commandType, int value);
void SSTF(int commandType, int value);
void SCAN(int commandType, int value);

//下面是FCFS专用
void setDirection();
int isArrive();

//下面是SSTF和SCAN

void SSTF(int commandType, int value); //SSTF策略入口函数
void SCAN(int commandType, int value); //SCAN策略入口函数
void initBus();                        //初始化运行方向以及目标，用于公交车从待命状态启动
void busStop();                        //停车函数
void setStatus2();                     //SSTF用更新行车状态
void setStatus3();                     //SCAN用更新行车状态
void arrStation();                     //到达车站函数
int isStation();                       //判断是否是路过车站
int getDistance(int value);            //获取某车站与公交车当前位置在目前行驶方向上的距离

#endif // STRATEGY_H
