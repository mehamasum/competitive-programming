#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  Node *next;
  Node(int x): data(x), next(NULL) {
  }
};


void append(Node** head_ref, int new_data)
{
    Node new_node(new_data);

    if (*head_ref == NULL) {
       *head_ref = &new_node;
       return;
    }

    Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = &new_node;
    return;
}

void printList(struct Node *node) {
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}


int main() {
  Node* head = NULL;
  append(&head, 6);
  append(&head, 7);
  append(&head, 1);
  append(&head, 4);
  printList(head);

  return 0;
}
