#include <stdio.h>
#define max_size 5

void add_one(int* given_array){
	int carry = 1;
	
	for(int i = 0; i < max_size - 1; i++){
		int total = given_array[i] + carry;
		
		if(total == 10) carry = 1;
		else carry = 0;

		given_array[i] = total % 10;
	}

	if(carry == 1){
		given_array[max_size] = 1;
	}
}

void dec_one(int* given_array){ 
	// step 1. no allow dynamic allocation.
	// so we use array type which also pointer. in C language we can't return array object so we should use array's address
	// that is why we declare function dec_one(int *) 
	
	int carry = 1;

	for(int i = 0; i <max_size - 1; i++){
		int total = given_array[i] - carry;

	// step 2. minus. 
	// if given_array is 9990 then you should return 9989
	// given_array is array type so we should check it array[0] to array[max_size]. because carry influencing not only array[i] but also array[i+1].
	// if carry is not positive integer then that means carry was occured so we should change current array[i] to 9 by definition of minus.
		if(total == -1){
			carry = 1;
			total = 9;
		}
		else carry = 0;
	
	// step 3. assign
	// like mentioned in step 1, we use pointer. array with index operator( [] ) is same as *(array + i). so we can use assign operator.
		given_array[i] = total;
	}

	if(carry == 1) given_array[max_size] = 9;
}
		


int main(){
	int array[max_size] = {9, 9, 9, 9};

	while(1){
		dec_one(array);

		for(int i = max_size - 1; i >= 0; i--){
			if(i == max_size-1 &&  array[i] == 0) // not allow array[max_size -1] == 0 like 09987
				continue;
			printf("%d", array[i]);
		}
		printf("\n");
	
		char buf[2];
		fgets(buf, 2, stdin);
	}

	return 0;
}
