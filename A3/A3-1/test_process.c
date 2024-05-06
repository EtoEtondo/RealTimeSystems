#include <stdio.h>
#include "process.h"
#include <stdint.h>
#include <stdlib.h>

int main(){

process testing={234,RUNNING};
printf("A1\n");
p_switch_state(&testing);
p_print(&testing);
p_switch_state(&testing);
p_print(&testing);
return 0;
}
