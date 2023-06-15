## Acknowledgements:
The header file as well as the function names are written by Jerry Cain @Stanford University.
I just implemented the functions. The vecotortest script is entirely written by Jerry Cain. <br>
I hope that makes sense to people ;).
# General:
The term vector is a horrible choice for what is essential a dynamically allocated array.
Alternatively the term ListArray is also often used. The difference to an ordinarray array
is that if you put something at it's place, it stays there. a[7]= 23; is not affected by a[4]=12;
unless it's actively taken care of. The same does not hold true for a vector.
The insertion of a[4]=12, here VectorInsert(&vector,&pos,4), will effect the position of
all elements behind it. The equivalent when using a Vector is the replace function, i.e.
a[4]=12 is the same as VectorReplace(&vector,&pos,4); <br>

Of course this behaviour is often desired and greatly missed when using a standard array.
The same goes for deletion. There are never holes in a vector or undesired already removed
elements which may happen with a standard array if no extra care is taken.  <br>

The blatant advantage of using a vector is the possibility to dynamically adjust it's size.
This adjustment, based on the reallocation, is organized on the initial size times two policy.
The vector has therefore pretty much the same performance as a classic array. The only
difference being it allocated on the heap, not on the stack. <br>

The provided functions include: <br>
|   Function            | Time | Description                                                 |
|-----------------------|------|-------------------------------------------------------------|
| `VectorNew`           | O(1) | Initializes a new vector.                                   |
| `VectorDispose`       | O(n) | Disposes the vector &freeing the associated memory.         |
| `VectorInsert`        | O(n) | Inserts an element. Shifts each element behind it by one.   |
| `VectorAppend`        | O(1) | Appends one time at the end (logicallength) of the vector   |
| `VectorReplace`       | O(1) | Replaces an element at a position. Comparable with a[n]=x;  |
| `VectorDelete`        | O(n) | Removes an element from a certain position and shifts.      |
| `VectorLength`        | O(1) | Returns the amount of elements in the vector.               |
| `VectorCapcity`       | O(1) | Returns the amount of how many elements currently fit.      |
| `VectorNth      `     | O(1) | Returns the element at a certain position                   |
| `VectorSearch`        | O(n) | Searches for and item in either a sorted or unsorted vector.|
| `VectorSort`          | O(n²)| Sorts the vector. (Quicksort)                               |
| `VectorMap`           | O(n) | Applies a function to each element of the vector.           |


