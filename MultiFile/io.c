#include "common.h"
#include "io.h"
#include "public.h"
#include "datastr.h"

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