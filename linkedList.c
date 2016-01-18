#include "linkedList.h"
#include <stdio.h>
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
	element *ele = list->first;
	for(int i=0;i<list->length;i++){
		if(index == i){
			list->length--;
			return ele->value;
			ele=ele->next;
		}
		ele = ele->next;
	}
	return NULL;
}

int asArray(linkedList list, void **destination, int maxElements) {
	int count = 0;
	element *ele = list.first;
	while(count<maxElements && ele != NULL){
		*destination = ele->value;
		ele = ele->next;
		count++;
		destination++;
	}
	return count;
};

linkedList  filter(linkedList list, MatchFunc isEven, void * hint){
	linkedList dest = createList();
	element *ele = list.first;
	for(int i=0;i<list.length;i++){
		if(isEven(hint, ele->value) == 1){
			add_to_list(&dest, ele->value);
		}
		ele = ele->next;
	}
	return dest;
};

int isEven(void * hint, void * item){
	int * num = (int*)item;
	return (*num%2==0); 
};

linkedList reverse(linkedList list){
	linkedList result = createList();
	element * ele = list.first;
	for(int i=list.length-1;i>0;i--){
		add_to_list(&result,(getElementAt(list,i)));
	}
	return result;
};

 void incrementer2(void* hint, void* sourceItem, void* destinationItem){
	int *dest = (int *)malloc(sizeof(int));
	*dest = (*(int *)sourceItem)+2;
	*(void **)destinationItem = dest;
};


linkedList map(linkedList list, ConvertFunc incrementer2, void * hint){
	element *ele = list.first;
	linkedList destination = createList();
	void * destinationItem ;
	for(int i=0;i<list.length;i++){
		incrementer2(hint,ele->value, &destinationItem);
		add_to_list(&destination, destinationItem);
		ele = ele->next;
	}
	return destination;
};

void* sumUp(void* hint, void* previousItem, void* item){
	int *dest = malloc(sizeof(int));
	*dest = (*(int *)previousItem) + (*(int *)item);
	return dest;
}

void * reduce(linkedList list, Reducer sum, void *hint, void *initialValue){
	element * ele = list.first;
	void *previousItem;
	if(initialValue == NULL){
		 previousItem = ele->value;
		 ele = ele->next;
	}
	else{
		previousItem = initialValue;
	}
	
	while(ele!=NULL){
		previousItem = sumUp(hint, previousItem, ele->value);
		ele = ele->next;
	}
	return previousItem;
};








