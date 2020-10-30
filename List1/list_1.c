#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
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
	List* link_new_element = (List*)malloc(sizeof(List));
	if (link_new_element) {
		link_new_element->head = NULL;
		link_new_element->last = link_new_element->head;

		return link_new_element;
	}

	return NULL;


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
bool  add(List* list, ListElement x) {
	if (list == NULL)
		return false;
	NodeList* link_new_element = (NodeList*)malloc(sizeof(NodeList));
	if (link_new_element)
	{
		(*link_new_element).element = x;

		if ((list)->head == NULL) {
			(list)->head = link_new_element;
			(list)->last = link_new_element;
			link_new_element->next = (list)->head;
			return true;
		}
		link_new_element->next = (list)->head;

		(list)->last->next = link_new_element;
		(list)->last = link_new_element;

		return true;

	}
	else
		return false;


}


void print_list(List* list) {

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
	print_list(arr);
	clean(arr);


	//_CrtDumpMemoryLeaks();

	return 0;

}
