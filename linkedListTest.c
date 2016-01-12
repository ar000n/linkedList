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
	int* first = get_first_element(list);
	assert((*first) == 3);	
};

