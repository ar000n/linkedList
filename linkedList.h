typedef struct ele{
	void *value;
	struct ele *next;
} element;

typedef struct linkedList{
	element *first;
	element *last;
	int length;
}linkedList;
typedef void(ElementProcessor) (void *);

linkedList createList(void);
int add_to_list(linkedList *,void *);
void *get_first_element(linkedList list);
void *get_last_element(linkedList list);
void forEach(linkedList, ElementProcessor e);
void * getElementAt(linkedList, int );
int indexOf(linkedList, void *);
void * deleteElementAt(linkedList *, int);
int asArray(linkedList, void **, int maxElements);
typedef int (MatchFunc)(void*, void*);
linkedList filter(linkedList,MatchFunc,void*);
int isEven(void*, void*);
linkedList reverse(linkedList);
typedef void (ConvertFunc)(void *, void *, void *);
void incrementer2(void *, void *, void*);
linkedList map(linkedList, ConvertFunc, void *);
typedef void* Reducer(void*, void*, void*);
void * sumUp(void*, void*, void*);
void * reduce(linkedList, Reducer, void *hint, void *initialValue);



