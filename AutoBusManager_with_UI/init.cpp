#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "datastr.h"
#include "define.h"
#include "public.h"
#include "mainwindow.h"

void initSystem() {
    memset(queue, -1, sizeof(queue));
    memset(req, 0, sizeof(req));

    TIME = 0;
    goal = 0;
    TOTAL_LENGTH = 10;
    stop = 0;
    direction = 0;
    status = 0;
    size = 0;
    TOTAL_LENGTH = TOTAL_STATION * DISTANCE;
    position = createList();
    for (int i = 1; i <= TOTAL_STATION; i++){
        INFO[i].clockwise = '0';
        INFO[i].counterclockwise = '0';
        INFO[i].target = '0';
    }
    printStatus();
    setStation();
}
