#include "linkedList.h"
#include <stdlib.h>
linkedList createList(void){
	linkedList list;
	list.first = NULL;
	list.last = NULL;
	list.length = 0;
	return list;
};
int add_to_list(linkedList * list,void * value){
	list->last = value;
	list->first = value;
	list->length++;
	return list->length;
};