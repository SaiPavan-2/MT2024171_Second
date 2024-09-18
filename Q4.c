/**
Name:Q4.c
Author:Pavan
Description:Program to calculate the time taken to execute 100 getpid() calls using time stamp counter
Date:12th September 2024
**/
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

uint64_t get_tsc() {
    uint32_t low, high;
    asm volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((uint64_t)high << 32) | low;
}

int main() {
    uint64_t start_time, end_time;
    
    start_time = get_tsc();
    for(int i=0;i<100;i++){
   pid_t  id= getppid();
}
    end_time = get_tsc();
    
    printf("Time taken to execute getppid() for 100 times is: %lu clock cycles\n", end_time - start_time);
    
    return 0;
}
/**Output:Time taken to execute getppid() for 100 times is: 70186 clock cycles
**/
