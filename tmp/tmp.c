#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//#include <crtdbg.h>
//#include <locale>
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
	NodeList* link_new_element = (NodeList*)malloc(sizeof(NodeList));
	if (link_new_element)
	{
		(*link_new_element).element = x;

		if ((list)->head == NULL) {
			(list)->head = link_new_element;
			(list)->last = link_new_element;
			link_new_element->next = (list)->head;
			return 0;
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




void remove_elemets_circle(List* list, int k) {
	//Номерация элементов начинается с 0(head)
	unsigned int length = len(list);
	NodeList* actual = list->last;


	int i = 1;
	bool flag = false;

	while (length != 1)
	{
		list->head = actual;
		actual = actual->next;
		if (flag) {
			list->last = list->last->next;
		}
		flag = true;
		if (i == k) {
			NodeList* tmp = actual;
			//printf("%d\n", actual->element);

			list->head->next = actual->next;
			actual = list->head;

			free(tmp);

			i = 0;
			flag = false;
			length--;
		}
		i++;
	}

	printf("last #%d", list->head->element);

}


int main(void) {
	//setlocale(LC_ALL, "Russian");
	List* arr = init();
	int n = 0;
	int k = 0;
	while (n <= 0 || k <= 0) {
		printf("in a circle: \n");
		scanf_s("%d", &n);
		printf("Everyone is eliminated: \n");
		scanf_s("%d", &k);
		if (n <= 0 || k <= 0)
			printf("Invalid data,please enter again\n/**********************************************/\n");
	}
	for (int i = 1; i < n + 1; i++)
		add(arr, i);
	remove_elemets_circle(arr, k);






	clean(arr);


	//_CrtDumpMemoryLeaks();

	return 0;

}
