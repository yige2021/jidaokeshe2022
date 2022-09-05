#ifndef IO_H
#define IO_H

void readCommand();             //读指令函数，并将读到的指令传给各个策略
int isEnd(char command[]);      //判断是否读到end指令
int getRequest(char command[]); //判断读入指令的类型
void getConfig();               //读配置文件函数
void printStatus();             //打印状态函数

#endif