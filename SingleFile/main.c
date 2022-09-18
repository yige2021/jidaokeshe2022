/*
★★★★★课程设计单文件核心版★★★★★
        作者           学号
    梁晨锐（组长）  2021211321
        闫晨浩      2021211314
         孙懿       2021211315
    版本：完美版 1.0
    班级：2021211313
    日期：2022年6月5日
★★★★★★★★★★★★★★★★★★★★
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STATION 10    //最多有10个车站
#define MAX_REQUEST 10000 //最多有10000个请求（假设）

//以下为公共变量，默认全部为0
int time;
int goal;               //在FCFS中是当前目标在队列中的编号，在SSTF中是目标站的编号
int TOTAL_STATION = 5;  //默认为5
int STRATEGY = 1;       //默认为1，STRAGETY值含义：1 => FCFS，2 => SSTF，3 => SCAN
int DISTANCE = 2;       //默认为2
int TOTAL_LENGTH = 10;  //默认为10
int stop;               //记录停站状态

// datstr.h
typedef struct node { //采用了双向循环链表模拟轨道；定义以及相关变量与函数
    int pos;
    int sta;
    struct node *next;
    struct node *prev;
} track;
track *position = NULL;
track *createList();

typedef struct { //FCFS和SSTF通用的请求队列，可存储一个请求的站点和类型
    int type;
    int sta;
} STATION1;
STATION1 req[MAX_REQUEST];
int reqNum;

typedef struct { //存储站点信息的INFO数组
    int target;           //公交车上对车站请求
    int clockwise;        //顺时针车站请求  0表示无，1表示有
    int counterclockwise; //逆时针车站请求
} sta;
sta INFO[MAX_STATION + 1];

int queue[MAX_REQUEST]; //SCAN专用请求队列，仅存放请求目标站编号

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

// FCFS.h
int direction; //行车方向、状态，1为顺时针，-1为逆时针，0为待命

// SSTF_SCAN.h
int status;             //行车方向、状态，1为顺时针，2为逆时针，0为待命
int size;               //请求数量

// main.c
void initSystem(); //初始化程序

// io.c
void readCommand();             //读指令函数，并将读到的指令传给各个策略
int isEnd(char command[]);      //判断是否读到end指令
int getRequest(char command[]); //判断读入指令的类型
void getConfig();               //读配置文件函数
void printStatus();             //打印状态函数

// pubfunc.c
void drive();                      //运行状态函数
int isArrive();                    //是否路过车站
int cacu(int now, int sta,int mn); //SSTF与SCAN通用，计算目前车站到目标车站的距离，并更新最短距离

// FCFS.c
void FCFS(int commandType, int value); //FCFS策略入口函数
void setDirection();                   //无请求时初始化公交车

// SSTF_SCAN.c
void SSTF(int commandType, int value); //SSTF策略入口函数
void SCAN(int commandType, int value); //SCAN策略入口函数
void initBus();                        //初始化运行方向以及目标，用于公交车从待命状态启动
void busStop();                        //停车函数
void setStatus2();                     //SSTF用更新行车状态
void setStatus3();                     //SCAN用更新行车状态
void arrStation();                     //到达车站函数
int isStation();                       //判断是否是路过车站
int getDistance(int value);            //获取某车站与公交车当前位置在目前行驶方向上的距离

int main() {
    initSystem();
    readCommand(); //读指令入口
    deleteList();
    printf("end\n");
    return 0;
}

// ★★★★★以下是公共函数★★★★★

void initSystem() {
    memset(queue, -1, sizeof(queue));
    getConfig();                               //读取配置文件
    TOTAL_LENGTH = TOTAL_STATION * DISTANCE;
    position = createList();
    printStatus();                             //开局先输出一下
}

void getConfig() {
    char FilePath[128] = "dict.dic";
    char Line[128] = {0};
    char Param[128] = {0};
    char Value[128] = {0};
    char Temp[128] = {0};
    int iLength = 0;
    int iIndex = 0;
    FILE *fp = NULL;
    int iTOTAL = 0;
    int iDISTANCE = 0;
    int iSTRATEGY = 0;
    int i;

    fp = fopen(FilePath, "r");
    if (fp != NULL) {
        while (1) {
            fgets(Line, 128, fp);

            iLength = strlen(Line);
            if (iLength > 0) {
                for (i = 0; i < iLength; i++) {
                    if (Line[i] == '\n') {
                        Line[i] = 0;
                    }
                }
                for (i = 0, iIndex = 0; i < iLength; i++, iIndex++) {
                    if (Line[i] == '=') {
                        break;
                    }
                }

                if (iIndex >= 0 && iIndex < iLength) {
                    Line[iIndex] = 0;
                    strcpy(Param, Line);
                    strcpy(Value, Line + iIndex + 1);

                    //判断TOTAL_STATION
                    memset(Temp, 0, 128);
                    for (i = 0; i < strlen("TOTAL_STATION"); i++) {
                        Temp[i] = Param[i];
                    }
                    for (i = 0; i < strlen("TOTAL_STATION"); i++) {
                        if (Temp[i] >= 97 && Temp[i] <= 122) {
                            Temp[i] -= 32;
                        }
                    }
                    if (strcmp(Temp, "TOTAL_STATION") == 0) {
                        for (i = strlen("TOTAL_STATION"); i < strlen(Param); i++) {
                            if (Param[i] != ' ') {
                                break;
                            }
                        }
                        if (i >= strlen(Param)) {
                            iTOTAL = 1;
                            TOTAL_STATION = atoi(Value);
                            continue;
                        }
                    }

                    //判断DISTANCE
                    memset(Temp, 0, 128);
                    for (i = 0; i < strlen("DISTANCE"); i++) {
                        Temp[i] = Param[i];
                    }
                    for (i = 0; i < strlen("DISTANCE"); i++) {
                        if (Temp[i] >= 97 && Temp[i] <= 122) {
                            Temp[i] -= 32;
                        }
                    }
                    if (strcmp(Temp, "DISTANCE") == 0) {
                        for (i = strlen("DISTANCE"); i < strlen(Param); i++) {
                            if (Param[i] != ' ') {
                                break;
                            }
                        }
                        if (i >= strlen(Param)) {
                            iDISTANCE = 1;
                            DISTANCE = atoi(Value);
                            continue;
                        }
                    }

                    //判断STRATEGY
                    memset(Temp, 0, 128);
                    for (i = 0; i < strlen("STRATEGY"); i++) {
                        Temp[i] = Param[i];
                    }
                    for (i = 0; i < strlen("STRATEGY"); i++) {
                        if (Temp[i] >= 97 && Temp[i] <= 122) {
                            Temp[i] -= 32;
                        }
                    }
                    if (strcmp(Temp, "STRATEGY") == 0) {
                        for (i = strlen("STRATEGY"); i < strlen(Param); i++) {
                            if (Param[i] != ' ') {
                                break;
                            }
                        }
                        if (i >= strlen(Param)) {
                            iSTRATEGY = 1;
                            if (strcmp(Value, " FCFS") == 0) {
                                STRATEGY = 1;
                            }
                            if (strcmp(Value, " SSTF") == 0) {
                                STRATEGY = 2;
                            }
                            if (strcmp(Value, " SCAN") == 0) {
                                STRATEGY = 3;
                            }
                            continue;
                        }
                    }
                }
            }
            if (feof(fp)) {
                break;
            }
        }
    }
}

void readCommand() {
    /*该函数是读取配置文件结束后用来读指令的，同时也是调度运行的入口*/
    char command[20];                        //存储指令名称的字符串
    int value;                               //该变量存储某三种指令后跟着一个的整数类型的值
    int commandType;                         //存储指令类型

    scanf("%s", command);
    while (!isEnd(command)) {                //遇到end之前一直读取
        value = -1;                          // value缺省值设为-1
        commandType = getRequest(command);   //获取指令类型
        if (commandType != 0)
            scanf("%d", &value);             //需要时读取value值
        if (STRATEGY == 1){
            FCFS(commandType, value);
        }
        if (STRATEGY == 2){
            SSTF(commandType, value);
        }
        if (STRATEGY == 3){
            SCAN(commandType, value);
        }
        scanf("%s", command);
    }
}

int isEnd(char command[]) {
    /*该函数用来判断是否读到end指令*/
    if (strcmp(command, "end") != 0){
        return 0;
    }
    else{
        return 1;
    }
}

int getRequest(char command[]) {
    /*该函数用来判断读入指令的类型*/
    if (strcmp(command, "clockwise") == 0){
        return 1; //站台顺时针请求，返回1
    }
    else if (strcmp(command, "counterclockwise") == 0){
        return 2; //站台逆时针请求，返回2
    }
    else if (strcmp(command, "target") == 0){
        return 3; //车上目的地请求，返回3
    }
    else{
        return 0; //否则是clock指令，返回0
    }
}

track *createList() {
    track *start = (track *)malloc(sizeof(track));
    track *ptr = start;

    start->pos = 0;
    start->sta = 1;
    int index;

    for (index = 1; index < TOTAL_LENGTH; index++) {
        track *newPtr = (track *)malloc(sizeof(track));

        newPtr->pos = index;
        if (index % DISTANCE == 0) {
            newPtr->sta = index / DISTANCE + 1;
        } else {
            newPtr->sta = 0;
        }
        ptr->next = newPtr;
        newPtr->prev = ptr;
        ptr = newPtr;
    }
    ptr->next = start;
    start->prev = ptr;
    return start;
}

void deleteList(){
    int num = 0;

    while (num++ < TOTAL_LENGTH) {
        track* tmp = position;
        position = position->next;
        free(tmp);
    }
}

void addINFO(int commandType, int value) {
    if (commandType == 3) {
        INFO[value].target = 1;
    }
    if (commandType == 1) {
        INFO[value].clockwise = 1;
    }
    if (commandType == 2) {
        INFO[value].counterclockwise = 1;
    }
}

void delINFO(int type, int sta) {
    if (type == 1) {
        INFO[sta].clockwise = 0;
    }
    if (type == 2) {
        INFO[sta].counterclockwise = 0;
    }
    if (type == 3) {
        INFO[sta].target = 0;
    }
}

void push_SCAN(int queue[], int *size, int value) {
    if (isExist_SCAN(queue, size, value) == 1) {
        return;
    }
    (*size)++;
    queue[*size] = value;
}

void push_back(int commandType, int value) {
    if (isExist(commandType, value) == 1) {
        return;
    }
    addINFO(commandType, value);
    req[reqNum].type = commandType;
    req[reqNum++].sta = value;
}

int isExist(int type, int value) {
    int index;

    if(STRATEGY == 1) {
        index = goal;
    }
    if(STRATEGY == 2) {
        index = 0;
    }
    for(index; index < reqNum; index++) {
        if(req[index].sta == value && req[index].type == type) {
            return 1;
        }
    }
    return 0;
}

void printStatus() {                                                //打印状态函数
    int index;

    printf("TIME:%d\n", time++);
    printf("BUS:\n");
    printf("position:%d\n", position->pos);
    printf("target:");
    for (index = 1; index <= TOTAL_STATION; index++) {
        printf("%d", INFO[index].target);
    }
    printf("\n");
    printf("STATION:\n");
    printf("clockwise:");
    for (index = 1; index <= TOTAL_STATION; index++) {
        printf("%d", INFO[index].clockwise);
    }
    printf("\n");
    printf("counterclockwise:");
    for (index = 1; index <= TOTAL_STATION; index++) {
        printf("%d", INFO[index].counterclockwise);
    }
    printf("\n");
}

void drive() {                                                      /*车辆运行函数*/
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

void pop_FCFS() {
    int type = req[goal].type;
    int sta = req[goal].sta;

    delINFO(type, sta);
    goal++;
}

int isExist_SSTF(int value) {
    int index;

    for (index = 0; index < reqNum; index++) {
        if(req[index].sta == value) {
            return 1;
        }
    }
    return 0;
}

int isExist_SCAN(int queue[], int* size, int value) {
    int index;

    for (index = 1; index <= *size; index++)
        if (queue[index] == value) {
            return 1;
        }
    return 0;
}

void pop_SSTF(int type, int value) {
    int index;

    for (index = 0; index < reqNum; index++) {
        if (req[index].sta == value && req[index].type == type) {
            int tmp = req[reqNum - 1].sta;
            int tmp2 = req[reqNum - 1].type;

            req[index].sta = tmp;
            req[index].type = tmp2;
            req[reqNum - 1].sta = -1;
            req[reqNum - 1].type = 0;
            reqNum--;
            break;
        }
    }
    delINFO(type, value);
}

void pop_SCAN(int queue[], int *size, int value) {
    int index;

    for (index = 1; index <= *size; index++) {
        if (queue[index] == value) {
            int tmp = queue[*size];
            queue[index] = tmp;
            queue[*size] = -1;
            (*size)--;
            break;
        }
    }
    INFO[value].clockwise = 0;
    INFO[value].counterclockwise = 0;
    INFO[value].target = 0;
}

// ★★★★★以下是FCFS的具体实现★★★★★

void setDirection() {
    if (goal >= reqNum) {
        direction = 0;
        return;
    }

    int sta = position->sta;
    int tmp = req[goal].sta - sta;

    if (tmp < 0) {
        if (abs(tmp) * 2 < TOTAL_STATION) {
            direction = -1;
        } else {
            direction = 1;
        }
    }
    if (tmp > 0) {
        if(tmp * 2 <= TOTAL_STATION) {
            direction = 1;
        } else {
            direction = -1;
        }
    }
}

int isArrive() {
    if (position->sta == req[goal].sta) {
        return 1;
    }
    return 0;
}

void FCFS(int commandType, int value) {
    if (commandType == 0) {                                         //clock指令的情况
        if (direction == 0 && stop == 0) {
            while (req[goal].sta == position->sta) {
                pop_FCFS();
            }
            setDirection();

        }
        drive();
        if (isArrive()) {
            direction = 0;
            stop++;
            if (stop == 2) {
                while (req[goal].sta == position->sta) {
                    pop_FCFS();
                }
                setDirection();
                stop = 0;
            }
        }
        printStatus();
    } else {                                                      //处理三种请求的情况,直接进队列
        push_back(commandType, value);
    }
}

// ★★★★★以下是SSTF和SCAN的具体实现★★★★★

void initBus() {
    if (size == 0 && reqNum == 0) {
        return;
    }
    int sta = position->sta;
    int index;
    int mn = TOTAL_STATION;

    //计算最近请求到公交车的距离
    if (STRATEGY == 2) {
        for (index = 0; index < reqNum; index++) {
            mn = cacu(req[index].sta, sta, mn);
        }
    }
    if (STRATEGY == 3) {
        for (index = 1; index <= size; index++) {
            mn = cacu(queue[index], sta, mn);
        }
    }
    int g1 = (sta + mn > TOTAL_STATION) ? (sta + mn - TOTAL_STATION) : (sta + mn);
    int g2 = (sta - mn < 1) ? (sta - mn + TOTAL_STATION) : (sta - mn);

    if(STRATEGY == 2) {
        if (isExist_SSTF(g1)) {
            goal = g1;
            status = 1;
        } else if (isExist_SSTF(g2)) {
            goal = g2;
            status = 2;
        }
    }
    if (STRATEGY == 3) {
        if (isExist_SCAN(queue, &size, g1)) {
            status = 1;
        } else if (isExist_SCAN(queue, &size, g2)) {
            status = 2;
        }
    }
}

int isStation() {
    /*判断是否路过车站*/
    return (position->sta == 0) ? 0 : 1;
}

int isRequest() {
    int sta = position->sta;

    return (INFO[sta].clockwise == 1 || INFO[sta].counterclockwise == 1 || INFO[sta].target == 1) ? 1 : 0;
}

void arrStation() {
    /*到站函数：到站之后的接客送客操作*/
    if (isRequest()) {    //若本站有请求，则停车
        busStop();
    }
}

void setStatus3() {
    int index;
    int mn = TOTAL_STATION;

    for (index = 1; index <= size; index++) {
        if (queue[index] == position->sta) {
            continue;
        }
        mn = fmin(mn, getDistance(queue[index]));
    }
    if (mn > TOTAL_STATION / 2) {
        if (status == 1) {
            status = 2;
        } else if (status == 2) {
            status = 1;
        }
    }
}

void setStatus2() {
    int sta = position->sta;
    int tmp = goal - sta;

    if(tmp < 0) {
        if (abs(tmp) < TOTAL_STATION / 2) {
            status = 2;
        } else {
            status = 1;
        }
    }
    if (tmp > 0) {
        if(tmp <= TOTAL_STATION / 2) {
            status = 1;
        } else {
            status = 2;
        }
    }
}

void busStop() {
    int now = position->sta;
    if(STRATEGY == 2 && now != goal) {
        if(status == 1 && INFO[now].clockwise == 0 && INFO[now].target == 0) {
            return;
        }
        if(status == 2 && INFO[now].counterclockwise == 0 && INFO[now].target == 0) {
            return;
        }
    }
    stop++;
    if (stop == 2) {
        if(STRATEGY == 2) {
            pop_SSTF(3, now);
            if (now == goal) {
                pop_SSTF(1, now);
                pop_SSTF(2, now);
                initBus();
            } else {
                pop_SSTF(status, now);
                pop_SSTF(3, now);
                setStatus2();
            }
        }
        if(STRATEGY == 3) {
            pop_SCAN(queue, &size, now);
            setStatus3();
        }
        if (size == 0 && reqNum == 0) {
            status = 0;
        }
        stop = 0;
    }
}

int getDistance(int tget) {
    /*获取公交车当前位置与某一车站之间，沿当前方向的距离*/
    int sta = position->sta;

    if (status == 1) {
        if (sta < tget) {
            return tget - sta;
        } else {
            return tget + TOTAL_STATION - sta;
        }
    }
    if (status == 2) {
        if (sta > tget) {
            return sta - tget;
        } else {
            return sta + TOTAL_STATION - tget;
        }
    }
}

void SSTF(int commandType, int value) {
    if (commandType == 0) {                                         /*clock指令*/
        if (status == 0) {                                           //若公交车为待命状态，则执行初始化
            int sta = position->sta;
            if(isExist_SSTF(sta)) {
                pop_SSTF(1, sta);
                pop_SSTF(2, sta);
                pop_SSTF(3, sta);
            }
            initBus();
        }
        drive();                                                    //执行车辆运行函数
        if (isStation()) {                                            //若路过车站，则执行到站函数
            arrStation();
        }
        printStatus();
    } else {
        push_back(commandType, value);
    }
}

void SCAN(int commandType, int value) {
    if (commandType == 0) {                                         /*clock指令*/
        if (status == 0) {                                           //若公交车为待命状态，则执行初始化
            int sta = position->sta;
            if(isExist_SCAN(queue, &size, sta)) {
                pop_SCAN(queue, &size, sta);
            }
            initBus();
        }
        drive();                                                    //执行车辆运行函数
        if (isStation()) {                                          //若路过车站，则执行到站函数
            arrStation();
        }
        printStatus();
    } else {
        push_SCAN(queue, &size, value);
        addINFO(commandType, value);
    }
}