#include "common.h"
#include "datastr.h"
#include "public.h"

int reqNum = 0;
int queue[MAX_REQUEST]; //SCAN专用请求队列，仅存放请求目标站编号
sta INFO[MAX_STATION + 1];
STATION1 req[MAX_REQUEST];
track *position = NULL;


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
