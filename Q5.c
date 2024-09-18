/**
Name:Q4.c
Author:Pavan
Description:Program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date:12th September 2024
**/
#include<stdio.h>
#include <unistd.h>
void main(){

long  max_arg_l=sysconf(_SC_ARG_MAX);
if(max_arg_l!=-1){
printf("Maximum length of the arguments to the exec family of functions %ld\n",max_arg_l);}
else{
perror("sysconf");
}

long  simul=sysconf(_SC_CHILD_MAX);
if(simul!=-1){
printf("Maximum number of simultaneous process per user id %ld\n",simul);}
else{
perror("sysconf");
}

long  ticks=sysconf(_SC_CLK_TCK);
if(ticks!=-1){
printf("Number of clock ticks (jiffy) per second %ld\n",ticks);}
else{
perror("sysconf");
}


long  max_files=sysconf(_SC_OPEN_MAX);
if(max_files!=-1){
printf("maximum number of open files %ld\n",max_files);}
else{
perror("sysconf");
}

long  page_s=sysconf(_SC_PAGESIZE);
if(page_s!=-1){
printf("Size of page in bytes  %ld\n",page_s);}
else{
perror("sysconf");
}

long  pm_pages=sysconf(_SC_PHYS_PAGES);
if(pm_pages!=-1){
printf("Total number of pages in the physical memory %ld\n",pm_pages);}
else{
perror("sysconf");
}

long av_pm_pages=sysconf(_SC_AVPHYS_PAGES);
if(av_pm_pages!=-1){
printf("Total number of currently available  pages in the physical memory %ld\n",av_pm_pages);}
else{
perror("sysconf");
}
}
/*Output:
Maximum length of the arguments to the exec family of functions 2097152
Maximum number of simultaneous process per user id 62708
Number of clock ticks (jiffy) per second 100
maximum number of open files 1024
Size of page in bytes  4096
Total number of pages in the physical memory 4032049
Total number of currently available  pages in the physical memory 2821503
*/
