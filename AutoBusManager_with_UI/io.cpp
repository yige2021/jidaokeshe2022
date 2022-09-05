#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <QtDebug>

#include "io.h"
#include "public.h"
#include "strategy.h"

void getConfig(char FilePath[]) {
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
    qDebug()<<STRATEGY;
}

void readCommand(int commandType, int value) {
    if (STRATEGY == 1){
        FCFS(commandType, value);
    }
    if (STRATEGY == 2){
        SSTF(commandType, value);
    }
    if (STRATEGY == 3){
        SCAN(commandType, value);
    }
}
