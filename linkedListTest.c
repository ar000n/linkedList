#include <stdio.h>
#include <assert.h>
#include "linkedList.h"

void test_for_createList(){
	linkedList list = createList();
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);


}
