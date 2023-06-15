#include "vector.h"
#include "lsearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void VectorNew(vector* v, long elemSize, VectorFreeFunction freeFn, long initialAllocation) {

	v->alloclength = initialAllocation;
	assert( v->alloclength != 0);
	v->logicallength = 0;
	v->elmSize = elemSize;

	v->array = malloc(v->alloclength*v->elmSize);
	assert ( v->array != NULL);
	v->freeFn = freeFn;
}

void VectorDispose(vector *v) {
	if ( v->freeFn != NULL) {
		for(long i=0; i<VectorLength(v);i++) {
			v->freeFn((char*)v->array+i*v->elmSize);
		}
	}

	free(v->array);
}

long VectorLength(const vector* v) { 
	assert(v->logicallength >=0);
	return v->logicallength;
}

long VectorCapacity(const vector* v) { 
	return v->alloclength;
}

void* VectorNth(const vector* v, long position) { 
	assert(  position >= 0 && position <= v->logicallength);
	return (char*)v->array + position*v->elmSize;
}

void VectorReplace(vector* v, const void* elemAddr, long position) {
	assert(position >= 0 && position <=v->logicallength);

	if (v->freeFn != NULL ) { 
		v->freeFn((char*)v->array+position*v->elmSize);
	}

	memcpy((char*)v->array+position*v->elmSize,elemAddr,v->elmSize);

}

static void VectorGrowth(vector* v) {
		v->alloclength <<=1;
		v->array = realloc(v->array,v->alloclength*v->elmSize);
}

void VectorInsert(vector* v, const void* elemAddr, long position) {
	assert(position >= 0 && position <= v->logicallength);

	if ( v->logicallength+1 == v->alloclength)  VectorGrowth(v);

	long bytesToMove = (char*)v->array + v->logicallength*v->elmSize - (char*)v->array+(position+1)*v->elmSize;

	memmove((char*)v->array+(position+1)*v->elmSize,(char*)v->array+position*v->elmSize,bytesToMove);
	memcpy((char*)v->array+position*v->elmSize,elemAddr,v->elmSize);
	v->logicallength++;

}

void VectorAppend(vector* v, const void* elemAddr) {

	if ( v->logicallength+1 == v->alloclength)  VectorGrowth(v);
	
	memcpy((char*)v->array+v->logicallength*v->elmSize,elemAddr,v->elmSize);
	v->logicallength++;
}

void VectorDelete(vector* v, long position) {
	assert(position >= 0 && position<=v->logicallength);

	  if (v->freeFn != NULL ) { 
	  	v->freeFn((char*)v->array+position*v->elmSize);
	  }

		long bytesToMove = v->logicallength-(position+1);
	  memmove((char*)v->array+position*v->elmSize,(char*)v->array+(position+1)*v->elmSize,bytesToMove*v->elmSize);
	  v->logicallength--;
}

void VectorSort(vector* v, VectorCompareFunction compare) {
	qsort(v->array,v->logicallength,v->elmSize, compare);
}

void VectorMap(vector* v, VectorMapFunction mapFn, void *auxData) {
	for(long i=0;i<v->logicallength;i++) {
		mapFn((char*)v->array+i*v->elmSize,auxData);
	}

}

long VectorSearch(const vector* v, const void* key, VectorCompareFunction searchFn, long startIndex, bool isSorted) {
	assert (startIndex >= 0 && startIndex < v->logicallength && searchFn != NULL && key != NULL);
	void* res;

	if (isSorted == true) { 
		res = bsearch(key,v->array,v->logicallength,v->elmSize,searchFn);
	}
	else {
	  res = lsearch((char*)v->array+startIndex*v->elmSize,key,v->logicallength,v->elmSize,searchFn);
	}

	if (res == NULL) { return -1; }
	else {
	  long position = ((char*)res - (char*)v->array)/(v->elmSize);
		return position;
	}
} 
