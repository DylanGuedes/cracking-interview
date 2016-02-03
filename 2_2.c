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
    head = new_head;
  } else {
    new_head->next = head;
    head = new_head;
  }

  return head;
}

void print_list(struct node *head)
{
  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

struct node *solve(struct node *head, int n)
{
  if(head == NULL || n < 1) {
    return NULL;
  }

  struct node *p1 = head;
  struct node *p2 = head;
  int i;

  for(i=0; i < n-1; ++i) {
    if(p2 == NULL) {
      return NULL;
    } else {
      p2 = p2->next;
    }
  }

  while(p2 != NULL) {
    p2 = p2->next;
    p1 = p1->next;
  }

  return p1;
}

int main(int argc, char const *argv[])
{
  struct node *head = NULL;
  int option = 1, aux_i;

  while(option != 0) {
    printf("1. Add at head.\n2. List items.\n3. Solve.\n0. Exit.\n");
    scanf("%d", &option);

    if(option == 1) {
      struct node *new_head;
      printf("value: ");
      scanf("%d", &aux_i);
      new_head->next = NULL;
      new_head->data = aux_i;
      insert_at_head(head, new_head);
    } else if(option == 2) {
      print_list(head);
    } else if(option == 3) {
      int n;
      printf("N:");
      scanf("%d", &n);
      solve(head, n);
    }
  }


  return 0;
}
