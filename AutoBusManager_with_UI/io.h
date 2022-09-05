#ifndef IO_H
#define IO_H

void readCommand(int commandType, int value);             //读指令函数，并将读到的指令传给各个策略
void getConfig(char path[]);               //读配置文件函数

#endif
