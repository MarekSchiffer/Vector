#ifndef VECTOR_H_
#define VECTOR_H_
#include "bool.h"

typedef struct {
	 long alloclength;
	 long logicallength;
	 long elmSize;
	 void* array;
	 void (*freeFn)(void* );
} vector;

typedef int (*VectorCompareFunction)(const void *elemAddr1, const void *elemAddr2);
typedef void (*VectorMapFunction)(void *elemAddr, void *auxData);
typedef void (*VectorFreeFunction)(void *elemAddr);

void VectorNew(vector *v, long elemSize, VectorFreeFunction freefn, long initialAllocation);
void VectorDispose(vector *v);

long VectorLength(const vector* v);
long VectorCapacity(const vector* v);

void* VectorNth(const vector* v, long position);
void VectorInsert(vector* v, const void* elemAddr, long position);
void VectorReplace(vector* v, const void* elemAddr, long position);
void VectorAppend(vector* v, const void* elemAddr);

void VectorDelete(vector* v, long position);

long VectorSearch(const vector* v, const void *key, VectorCompareFunction searchfn, long startIndex, bool isSorted);
void VectorSort(vector* v, VectorCompareFunction comparefn);
void VectorMap(vector* v, VectorMapFunction mapfn, void *auxData);

#endif
