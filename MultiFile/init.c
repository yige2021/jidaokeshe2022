#include "common.h"
#include "init.h"
#include "datastr.h"
#include "public.h"

void initSystem() {
    memset(queue, -1, sizeof(queue));
    getConfig();                               //读取配置文件
    TOTAL_LENGTH = TOTAL_STATION * DISTANCE;
    position = createList();
    printStatus();                             //开局先输出一下
}