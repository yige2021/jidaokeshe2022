#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "datastr.h"
#include "public.h"
#include "mainwindow.h"

int TOTAL_STATION = 5;
int DISTANCE = 2;
int STRATEGY = 1;

int TIME = 0;
int goal = 0;
int TOTAL_LENGTH = 10;
int stop = 0;
int direction = 0;
int status = 0;
int size = 0;

// ★★★★★以下是公共函数★★★★★

void drive() {
    if (STRATEGY == 1) {
        if (direction == 1) {
            position = position->next;
            moveBus(1);
        }
        if (direction == -1) {
            position = position->prev;
            moveBus(0);
        }
    }
    if (STRATEGY == 2 || STRATEGY == 3) {
        if (status == 1 && stop == 0) {
            position = position->next;
            moveBus(1);
        }
        if (status == 2 && stop == 0) {
            position = position->prev;
            moveBus(0);
        }
    }
}

int cacu(int now, int sta,int mn) {
    int dis = fmin(abs(now - sta), fmin(abs(TOTAL_STATION - now + sta), abs(TOTAL_STATION - sta + now)));

    return fmin(mn, dis);
}
