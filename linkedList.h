typedef struct{
	int value;
	struct element *next;
} element;

typedef struct {
	element *first;
	element *last;
	int length;
}linkedList;

linkedList createList(void);
int add_to_list(linkedList *,void *);