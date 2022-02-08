#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{

    int pid = atoi(argv[1]);
    int priority = atoi(argv[2]);

    if (priority < 0){
        priority = 0;
    }

    setprio(pid, priority);
    exit();

}