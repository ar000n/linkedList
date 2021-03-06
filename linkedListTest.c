#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedList.h"

void test_for_createList(){
	linkedList list = createList();
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);
};

void test_for_add_to_list(){
	int  value = 3;
	linkedList list = createList();
	int len = add_to_list(&list,&value);
	assert(len == 1);
};

void test_for_get_first_element(){
	int  value = 3;
	linkedList list = createList();
	add_to_list(&list,&value);
	int* first = (int *)get_first_element(list);
	assert(*first == 3);	
};

void test_for_get_last_element(){
	int  value[3] = {3,4,6};
	linkedList list = createList();
	for(int i=0;i<3;i++){
		add_to_list(&list,&value[i]);
	}
	int* last = (int *)get_last_element(list);
	assert(*last == 6);	
};

void incrementer (void *value){
	(*(int *)value)++;
};

void test_for_forEach(){
 	int  value[3] = {3,4,6};
	linkedList list = createList();
	for(int i=0;i<3;i++){
		add_to_list(&list,&value[i]);
	}
 	forEach(list,incrementer);
 	int * res = (int*)list.first->value;
 	assert(*res == 4);
};

void test_for_getElementAt(){
	int index = 4;
	int  value[5] = {3,4,6,0,33};
	linkedList list = createList();
	for(int i=0;i<5;i++){
		add_to_list(&list,&value[i]);
	}
	int * res = getElementAt(list, index);
	assert(*res == 33);
};

void test_for_indeOf(){
	int  value[5] = {3,4,6,0,33};
	linkedList list = createList();
	for(int i=0;i<5;i++){
		add_to_list(&list,&value[i]);
	}
	int res = indexOf(list, &value[3]);
	assert(res == 3);
};

void test_for_deleteElementAt(){
	int index = 2;
	int  value[5] = {12,13,14,15,16};
	linkedList list = createList();
	for(int i=0;i<5;i++){
		add_to_list(&list,&value[i]);
	}
	int * res = deleteElementAt(&list, index);
	assert(*res ==14);
	assert(list.length == 4);
}

void test_for_asArray() {
	linkedList list = createList();
	int array[] = {4,5,6,7,8,9};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	void *destination = (int *)calloc(6,8);
	int counter = asArray(list, destination, 6);
	assert(counter == 6);
	for (int i = 0; i<6; ++i){
		assert(**(int **)destination == array[i]);
		destination+=8;
	}
};

void test_for_filter(){
	int hint = 8;
	linkedList list = createList();
	int array[] = {4,5,6,7,8,9};
	int even [] = {4,6,8};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	linkedList result = filter(list,isEven,&hint);
	element *ele = result.first;
	for(int i=0;i<result.length;i++){
		int * res = (ele->value);
		assert(*res == even[i]);
		ele = ele->next;
	}
};
 void test_for_reverse(){
 	linkedList list = createList();
	int array[] = {4,5,6,7,8,9};
	int reverseArray[] = {9,8,7,6,5,4};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	linkedList result =  reverse(list);
	element *ele = result.first;
	for(int i=0;i<result.length;i++){
		int * res = (ele->value);
		assert(*res == reverseArray[i]);
		ele = ele->next;	
	}
 };

 void test_for_map(){
 	linkedList list = createList();
	int array[] = {4,5,6,7,8,9};
	int incArray[] = {6,7,8,9,10,11};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	linkedList result = map(list,incrementer2,NULL);
	element *ele = result.first;
	for(int i=0;i<result.length;i++){
		int * res = ele->value;
		assert(*res == incArray[i]);
		ele = ele->next;		
	}
 };


void test_for_reduce(){
	linkedList list = createList();
	int array[] = {4,5,6,7,8,9};
	for (int i = 0; i < 6; ++i){
		add_to_list(&list, &array[i]);
	}
	int *result = reduce(list, sumUp, NULL, NULL);
	assert(*result == 39);
}
























