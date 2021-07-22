#include <stdio.h>


struct node {
	int value;
	struct node * next;
};
void PushNList(struct node **Phead, int val) {
	struct node * newelem = (struct node *) malloc(sizeof(struct node)); //create the new node
	newelem->value = val; //adding value
	newelem->next = NULL; //the end of the list
	if (*Phead == NULL) { // the list is empty
		*Phead = newelem; //make the head point to the new element
	}
	else {
		struct node * temp = *Phead;
		while (temp->next != NULL) //go forward untill the last element
		{
			temp = temp->next;
		}
		temp->next = newelem; //make the pointer of the last element point to the new element
	}
}
int getTheSizeOfTheList(struct node *head) {
	if (head == NULL) { //there are no elements in the list
		return 0;
	}
	else {
		struct node * temp = head;
		int count = 0;
		while (temp != NULL) { //go forward to the last element
			temp = temp->next;
			count++;
		}
		return count;
	}
}

void printList(struct node *head) {
	if (getTheSizeOfTheList(head) == 0) {
		printf("Empty List!!\n");
	}
	else {
		while (head != NULL) {
			printf("%d\n", head->value);
			head = head->next;
		}
	}



}
void insertNPos(struct node **Phead, int pos, int val) {
	struct node * newelem = (struct node *) malloc(sizeof(struct node)); //create the new node
	newelem->value = val; //adding value


	int count = 1;
	if (pos == 0) { //insert in the first postion
		newelem->next = *Phead; // make the new element point to the element the head used to point to
		*Phead = newelem; //make the head point to the new element as the first one
	}
	else {
		if (getTheSizeOfTheList(*Phead) < pos) { //ensure that the user didn't enter an invalid pos
			printf("Cannot insert the value in this postion!\n");
			return;
		}
		else {
			struct node * temp = *Phead; // create a temp pointer to manipulate the list without changing the head pointer
			for (int i = 0; i < pos-1; i++) // go forward to the element before the wanted position
			{
				temp = temp->next;
			}
			newelem->next = temp->next; //make the new element
			temp->next = newelem;
		}
	}

}
void deleteElemNPos(struct node ** Phead,int pos) {
	struct node * temp = *Phead;
	if (getTheSizeOfTheList(*Phead) <= pos) {
		printf("No elements in this position!\n");
	}
	else {
		if (pos == 0) {
			*Phead = temp->next;
			free(temp);
		}
		else {
			for (int i = 0; i < pos-1; i++) {
				temp = temp->next;
			}
			struct node * temp2next = temp->next;
			temp->next = temp2next->next;
			free(temp2next);
		}
		printf("\nelement in postion %d is deleted!\n\n", pos);
	}
}
void UpdateElemNPos(struct node ** Phead ,  int pos , int newValue) {
	struct node * temp = *Phead;
	if (getTheSizeOfTheList(*Phead) <= pos) {
		printf("No elements in this position!\n");
	}
	else {
		if (pos == 0) {
			temp->value = newValue;
		}
		else {
			for (int i = 0; i < pos ; i++) {
				temp = temp->next;
			}
			temp->value = newValue;
		}
		printf("\nThe element in postion %d is updated!\n\n", pos);
	}
}
int getElement(struct node * head, int pos) {
	if (getTheSizeOfTheList(head) <= pos) {
		printf("No elements in this position!\n");
		return -1; //used to detect an error
	}
	else {
		int res;
		if (pos == 0) {
			res = head->value;
		}
		else {
			struct node * temp = head;
			for (int i = 0; i < pos ; i++) {
				temp = temp->next;
			}
			res = temp->value;
		}
		return res;
	}
}
void destroyList(struct node ** Phead) {

	int count = getTheSizeOfTheList(*Phead);
	for (int i = 0; i < count; i++) {
		deleteElemNPos(Phead, 0);
	}
}
int main(void) {
    struct node * head = NULL;
	insertNPos(&head, 0, 5);
	insertNPos(&head, 0, 8);
	insertNPos(&head, 1, 52);
	insertNPos(&head, 55, 7);
	insertNPos(&head, 2, 0);
	insertNPos(&head, 4, 11);

	printList(head);
	return 0;
}

