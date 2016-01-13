typedef struct ele{
	void *value;
	struct ele *next;
} element;

typedef struct {
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

