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
	element *ele = malloc(sizeof(element));
	ele->value=value;
	ele->next=NULL;
	if(list->first==NULL){
		list->last = ele;
		list->first = ele;
	}
	else{
		list->last->next = ele;
		list->last = ele;
	}
	list->length++;

	return list->length;
};

void *get_first_element(linkedList list){
	element * firstElement = list.first;
	return firstElement->value;
};

void *get_last_element(linkedList list){
	element * lastElement = list.last;
	return lastElement->value;
};

void forEach(linkedList list, ElementProcessor e){
	for(int i=0;i<list.length;i++){
		e(list.first->value);
		list.first = list.first->next;
	}
};

void * getElementAt(linkedList list, int index){
	for(int i=0;i<list.length;i++){
		if(index == i){
			return list.first->value;
		}
		list.first = list.first->next;
	}
	return NULL;
};

int indexOf(linkedList list, void * ele){
	for(int i=0;i<list.length;i++){
		void * val = list.first->value;
		if(val == ele){
			return i;
		}
		list.first = list.first->next;
	}
	return -1;
};

void * deleteElementAt(linkedList * list, int index){
	for(int i=0;i<list->length;i++){
		if(index == i){
			list->length--;
			return list->first->value;
			list->first=list->first->next;
		}
		list->first = list->first->next;
	}
	return NULL;
}



































