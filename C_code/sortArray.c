#include<stdio.h>
#include<stdlib.h>

int* sortedSquares(int* A, int ASize, int* returnSize);
int* squareElems(int* A, int ASize, int* returnSize);
int squareOf(int num);
int* sortArrayInAsc(int* A, int Asize);
void swap(int* x, int* y);

int main(void){
	 int _nums[5] = {-789, 9878, -9872};
	 int* _sorted;
	 int _size;
	
	 _sorted = sortedSquares(_nums, 5, &_size);
	 
	int _i;
	for(_i = 0; _i < 5; ++_i){
		printf("%i ", _sorted[_i]);
	}
	printf("\n");
	
	return 0;
}

int* sortedSquares(int* A, int ASize, int* returnSize){
	
	int *_arrOfSquares, *_arrOfSortedElems;
	
	_arrOfSquares = squareElems(A, ASize, returnSize);
	_arrOfSortedElems = sortArrayInAsc(_arrOfSquares, ASize);
	
	return _arrOfSortedElems;

}

int* squareElems(int* A, int ASize, int* returnSize){
	
	int* _arrOfSquares;
	
	_arrOfSquares = (int*)malloc(ASize*sizeof(int));
	
	int _i = 0;
	while(_i < ASize){
		*(_arrOfSquares + _i) = squareOf(*(A + _i));
		_i++;
	}
	
	*returnSize = ASize;
	return _arrOfSquares;
}

int* sortArrayInAsc(int* A, int Asize){

	int _i, _j ;
	for(_i = 0; _i < Asize; ++_i){

		for(_j = _i + 1; _j < Asize; ++_j){

			if(A[_i] > A[_j]){
				swap(A+_i, A+_j);
			}
		}
	}
	
	return A;
}

void swap(int* swapFrom, int* swapInto){
	int _tempVar = 0;
	_tempVar = *swapFrom;
	*swapFrom = *swapInto;
	*swapInto = _tempVar;
		
}

int squareOf(int num){
	int square = 0;
	square = num*num;
	return square;
}




