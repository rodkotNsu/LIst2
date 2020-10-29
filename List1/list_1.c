#include <stdio.h>
#include<stdlib.h>
//#include <crtdbg.h>
typedef int ListElement;
struct NodeList {
	ListElement element;
	struct NodeList* next;

};
typedef struct NodeList NodeList;
struct List {
	NodeList* head;
	NodeList* last;
};
typedef struct List List;



List* init() {
	List* newList = (List*)malloc(sizeof(List));
	newList->head = NULL;
	newList->last = newList->head;



	return newList;


}
unsigned int len(List* list)
{
	unsigned int length_list = 0;
	NodeList* tmp = list->head;

	do
	{
		if (tmp == NULL) break;
		length_list++;
		tmp = tmp->next;
	} while (tmp != list->head);



	return length_list;

}
int add(List* list, ListElement x) {
	NodeList* newElement = (NodeList*)malloc(sizeof(NodeList));
	newElement->element = x;

	if ((list)->head == NULL) {
		(list)->head = newElement;
		(list)->last = newElement;
		newElement->next = (list)->head;
		return 0;
	}
	newElement->next = (list)->head;

	(list)->last->next = newElement;
	(list)->last = newElement;

	return 1;




}


void printList(List* list) {
	NodeList* tmp = list->head;
	do
	{
		if (tmp == NULL) break;
		printf("%d\n", tmp->element);
		tmp = tmp->next;
	} while (tmp != list->head);
}

void clean(List* list) {
	NodeList* tmp = list->head;
	do {
		if (tmp == NULL) break;
		NodeList* tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;

	} while (tmp != list->head);

	free(list);
}

int main(void) {
	List* arr = init();
	int n;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		add(arr, i);
	printList(arr);
	clean(arr);


	//_CrtDumpMemoryLeaks();

	return 0;

}
