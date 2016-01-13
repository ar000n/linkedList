#include <stdio.h>
#include <assert.h>
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





































