#include "linkedList.h"
#include <stdlib.h>
linkedList createList(void){
	linkedList list;
	list.first = NULL;
	list.last = NULL;
	list.length = 0;
	return list;
};