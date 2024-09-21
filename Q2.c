/**
Name:Q2.c
Author:Pavan
Description:Program to print the system resource limits using getrlimit system call.
Date:12th September 2024
**/
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

void print_resource(int resource,const char* msg){
struct rlimit limit;
if(getrlimit(resource,&limit)==0){
printf("%s limits \n",msg);
printf("soft limit %ld\n",(long)limit.rlim_cur);
printf("hard limit %ld\n",(long)limit.rlim_max);
}
else{
perror("error");
exit(1);
}
}
void main(){
print_resource(RLIMIT_AS,"Max size of process virtual mem");
print_resource(RLIMIT_CORE,"Core file size");
print_resource(RLIMIT_CPU,"Amount of cpu time process may consume");
print_resource(RLIMIT_DATA,"size of process data seg");
print_resource(RLIMIT_FSIZE,"file size");
print_resource(RLIMIT_LOCKS,"limit of locks");
print_resource(RLIMIT_MEMLOCK,"Number of bytes of mem that may be locked into Ram");
print_resource(RLIMIT_MSGQUEUE,"POSIX message  Queue size");
print_resource(RLIMIT_STACK,"Stack size");
}
/*Output:
Max size of process virtual mem limits 
soft limit -1
hard limit -1
Core file size limits 
soft limit 0
hard limit -1
Amount of cpu time process may consume limits 
soft limit -1
hard limit -1
size of process data seg limits 
soft limit -1
hard limit -1
file size limits 
soft limit -1
hard limit -1
limit of locks limits 
soft limit -1
hard limit -1
Number of bytes of mem that may be locked into Ram limits 
soft limit 2064408576
hard limit 2064408576
POSIX message  Queue size limits 
soft limit 819200
hard limit 819200
Stack size limits 
soft limit 8388608
hard limit -1
*/



