#include "common.h"
#include "init.h"

int main() {
    initSystem();
    readCommand(); //读指令入口
    deleteList();
    printf("end\n");
    system("pause");
    return 0;
}