#include <stdlib.h>
#include <stdio.h>

struct node {
  struct node *next;
  int data;
};

struct node *build_node()
{
  return (struct node*)malloc(sizeof(struct node));
}

struct node *insert_at_head(struct node *head, struct node *new_node)
{
  if(head == NULL) {
    head = new_node;
  } else {
    new_node->next = head;
    return new_node;
  }
}

void print_list(struct node *head)
{
  if(head == NULL) return;

  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void remove_duplicates(struct node *head)
{
  if(head == NULL) return;
  if(head->next == NULL) return;

  struct node *it1 = head;
  struct node *it2 = head->next;

  while(it1 != NULL) {
    it2 = it1->next;
    struct node *prev = it1;

    while(it2 != NULL) {

      if(it1->data == it2->data) {
        prev->next = it2->next;
        free(it2);
        break;
      }

      it2 = it2->next;
      prev = prev->next;
    }

    it1 = it1->next;
  }
}

int main(int argc, char const *argv[])
{
  struct node *head = NULL;
  int option = 1, aux_i;

  while(option != 0) {
    printf("1. Insert at head. \n2. Remove duplicates.\n3. Print List\n0. Exit\n");
    scanf("%d", &option);

    if(option == 1) {
      struct node *new_node = build_node();
      printf("Value:");
      scanf("%d", &aux_i);
      new_node->data = aux_i;
      new_node->next = NULL;
      head = insert_at_head(head, new_node);
    } else if (option == 2) {
      remove_duplicates(head);
    } else if (option == 3) {
      print_list(head);
    }
  }
  return 0;
}
