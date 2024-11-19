#pragma once

template <class T>
class QuickSort
{
	int (*compare) (const void* a, const void* b);
public:
	void sort(T* A,int p, int r, int (*compare) (const void* a, const void* b))
	{
		int q1, q2;
		int stack[200]; 		// For sorting upto 10^30 numbers
		int sp = 2;				//stack pointer is initalized to 2 to remove an extra if, allowing the stack size to be effectively -2.

		this->compare = compare;
		do {
			if (r > p) {
				partition(A, p, r, q1, q2);
				int p1 = p;				int r1 = q1 - 1;
				int p2 = q2 + 1;		int r2 = r;
				if (r1 - p1 > r2 - p2) {
					p2 = p1;			r2 = r1;
					p1 = q2 + 1;		r1 = r;
				}

				stack[sp++] = p2;
				stack[sp++] = r2;

				p = p1;
				r = r1;
			}
			else {
				r = stack[--sp];
				p = stack[--sp];
			}
		} while (sp);
	}

	void partition (T* A, int p,  int r, int& q1, int& q2)
	{
		int i, j, k, cmp;
		int q = rand () % (r-p+1) + p;
		T 	pivot = A[q];
		T* ptr = &pivot;
		T temp;
		i = p;
		j = p;
		k = r;
		
		while (j<=k){
			cmp = this->compare(A + j, ptr);
			if (cmp > 0 ){
				temp = A[j];
				A[j] = A[k];
				A[k] = temp;
				k--;
			}
			else if (cmp < 0){
				temp = A[j];
				A[j] = A[i];
				A[i] = temp;
				i++;
				j++;
			}
			else
				j++;
			
		}
		q1 = i;
		q2 = k;
	}
};



