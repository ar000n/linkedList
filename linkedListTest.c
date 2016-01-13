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
}
 void test_for_forEach(){
 	int  value[3] = {3,4,6};
	linkedList list = createList();
	for(int i=0;i<3;i++){
		add_to_list(&list,&value[i]);
	}
 	forEach(list,incrementer);
 	int * res = (int*)list.first->value;
 	assert(*res == 4);
 }

















