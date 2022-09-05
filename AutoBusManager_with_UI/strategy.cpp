#include "QtDebug"

#include "public.h"
#include "strategy.h"
#include "datastr.h"
#include "mainwindow.h"

//下面是FCFS

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
    } else {                                                      //处理三种请求的情况,直接进队列
        push_back(commandType, value);
    }
    printStatus();
}

void setDirection() {
    if (goal >= reqNum) {
        direction = 0;
        return;
    }

    int sta = position->sta;
    int tmp = req[goal].sta - sta;

    qDebug("%d", goal);

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

//下面是SSTF和SCAN

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

    return (INFO[sta].clockwise == '1' || INFO[sta].counterclockwise == '1' || INFO[sta].target == '1') ? 1 : 0;
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
        if(status == 1 && INFO[now].clockwise == '0' && INFO[now].target == '0') {
            return;
        }
        if(status == 2 && INFO[now].counterclockwise == '0' && INFO[now].target == '0') {
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
    } else {
        push_back(commandType, value);
    }
    printStatus();
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
    } else {
        push_SCAN(queue, &size, value);
        addINFO(commandType, value);
    }
    printStatus();
}
