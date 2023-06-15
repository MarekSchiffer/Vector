#include"lsearch.h"
#include<stdlib.h>

void* lsearch(void* base, const void* elem, int n, int elemSize, int (*cmpfn)(const void*,const void*)) {
	for (int i=0;i<n;i++) {
		void* elmAddr= (char*)base + i*elemSize;
		if (cmpfn(elmAddr,elem) == 0){ return elmAddr; };
	}
	return NULL;
}

