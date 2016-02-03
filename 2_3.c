#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *next;
};

struct node *build_node()
{
  return (struct node*)malloc(sizeof(struct node));
}

struct node *insert_at_head(struct node *head, struct node *new_head)
{
  if(head == NULL) {
    return new_head;
  } else {
    new_head->next = head;
    return new_head;
  }
}

void print_list(struct node *head)
{
  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void delete_node(struct node *head, int value)
{
  if(head == NULL) return;

  struct node *prev = head;
  head = head->next;

  while(head != NULL) {
    if(head->data == value) {
      prev->next = head->next;
      free(head);
      return;
    }

    prev = prev->next;
    head = head->next;
  }
}

int main(int argc, char const *argv[])
{
  struct node *head = NULL;
  int option = 1, aux_i;

  while(option != 0) {
    printf("1. Add at head.\n2. List items.\n3. Delete Node.\n0. Exit.\n");
    scanf("%d", &option);

    if(option == 1) {
      struct node *new_head = build_node();
      printf("value: ");
      scanf("%d", &aux_i);
      new_head->next = NULL;
      new_head->data = aux_i;
      head = insert_at_head(head, new_head);
    } else if(option == 2) {
      print_list(head);
    } else if(option == 3) {
      int number;
      printf("Key:");
      scanf("%d", &number);
      delete_node(head, number);
    }
  }


  return 0;
}
