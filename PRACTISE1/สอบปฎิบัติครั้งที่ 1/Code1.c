//นายชยธร เอียดราช รหัส 65543206049-0 Sec2
//https://youtu.be/uaieQEjl-xE

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node * link;
};

//struct node * head = NULL;
  //AddNode( & head, 10);
  //AddNode( & head, 20);
  //AddNode( & head, 30);
  //AddNode( & head, 40);

void AddNode(struct node ** head, int NewValue) {
  struct node * MyNode = (struct node * ) malloc(sizeof(struct node));
  MyNode -> value = NewValue;
  MyNode -> link = NULL;

  if ( * head == NULL) {
    * head = MyNode;
    return;
  }

  struct node * c = * head;
  struct node * p = NULL;
  while (c != NULL) {
    p = c;
    c = c -> link;
  }
  p -> link = MyNode;
} 

void ShowAll(struct node * head) {
  struct node * t = head;
  while (t != NULL) {
    printf("%d ", t -> value);
    t = t -> link;
  }
  printf(" ");
} 
//ShowAll(head); //10, 20, 30, 40
void UpdateNode(struct node * head, int r, int w) {
  struct node * c = head;
  while (c && c -> value != r) {
    c = c -> link;
  }
  if (c) {
    c -> value = w;
  }
} 
//UpdateNode(head, 10, 99);
void SwapNode(struct node ** head, int first, int second) {
  if (head == NULL || first == second) return;

  struct node * firstNode = * head, * secondNode = * head;
  struct node * prevFirst = NULL, * prevSecond = NULL;

  while (firstNode && firstNode -> value != first) {
    prevFirst = firstNode;
    firstNode = firstNode -> link;
  }
  while (secondNode && secondNode -> value != second) {
    prevSecond = secondNode;
    secondNode = secondNode -> link;
  }

  if (firstNode == NULL || secondNode == NULL) return;

  if (prevFirst) {
    prevFirst -> link = secondNode;
  } else * head = secondNode;

  if (prevSecond) {
    prevSecond -> link = firstNode;
  } else * head = firstNode;

  struct node * t = secondNode -> link;
  secondNode -> link = firstNode -> link;
  firstNode -> link = t;
} 
//SwapNode( & head, 99, 30);
void Showback(struct node * head) {
  if (head == NULL) return;
  Showback(head -> link);
  printf("%d ", head -> value);
} 
//Showback(head) 98 30 20 99;
int main() {

  struct node * head = NULL;

  AddNode( & head, 10);
  AddNode( & head, 20);
  AddNode( & head, 30);
  AddNode( & head, 40);
  printf("ShowAll: ");
  ShowAll(head); //10, 20, 30, 40
  printf("\n");
  printf("Update_Node 10 to 99 \n");
  UpdateNode(head, 10, 99);
  ShowAll(head);
  printf("\nUpdate_Node 10 to 98 \n");
  UpdateNode(head, 40, 98);
  ShowAll(head); //99, 20, 30, 40
  printf("\n");
  printf("Showback: ");
  Showback(head);
  //ShowAll(head); //98, 30, 20, 99
  printf("\n");
  printf("SwapNode: ");
  SwapNode( & head, 99, 30);
  ShowAll(head); //30, 20, 99, 98
}
