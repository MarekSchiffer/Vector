#ifndef LSEARCH_H_
#define LSEARCH_H_
#include<stdlib.h>

void* lsearch(void* base, const void* elem, int n, int elemSize,int (*cmpfn)(const void*,const void*)); 

#endif
