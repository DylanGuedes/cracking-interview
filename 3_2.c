#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *below;
  int min;
};

struct stack
{
  struct node *top;
};

struct stack *build_stack()
{
  return (struct stack*)malloc(sizeof(struct stack));
}

struct node *build_node()
{
  return (struct node*)malloc(sizeof(struct node));
}

struct stack *push(struct stack *mystack, struct node *newnode)
{
  if(mystack == NULL) {
    newnode->min = newnode->value;
    mystack = build_stack();
    mystack->top = newnode;
    newnode->below = NULL;
    return mystack;
  }

  if(mystack->top == NULL) {
    newnode->min = newnode->value;
    mystack->top = newnode;
    newnode->below = NULL;
    return mystack;
  }

  newnode->below = mystack->top;
  if(newnode->value < mystack->top->min) {
    newnode->min = newnode->value;
  } else {
    newnode->min = mystack->top->min;
  }
  mystack->top = newnode;
  return mystack;
}

int pop(struct stack *mystack)
{
  if(mystack == NULL) return -1;
  if(mystack->top == NULL) return -1;

  struct node *aux = mystack->top;
  int tmp = aux->value;
  mystack->top = mystack->top->below;
  free(aux);

  return tmp;
}

int soft_pop(struct stack *mystack)
{
  if(mystack == NULL) return -1;
  if(mystack->top == NULL) return -1;

  int tmp = mystack->top->value;
  mystack->top = mystack->top->below;

  return tmp;
}

void print_values(struct stack *mystack)
{
  if(mystack == NULL || mystack->top == NULL) {
    printf("Invalid stack.\n");
    return;
  }

  while(mystack->top != NULL) {
    printf("%d ", soft_pop(mystack));
  }
}

void func_teste(struct node *nd)
{
  nd->value = 40;
}

int main(int argc, char const *argv[])
{
  int option = 1;
  int i_aux;
  struct stack *mystack = NULL;
  struct node *teste = build_node();
  teste->value = 15;

  while(option != 0) {
    printf("1. push\n2. pop\n3. list\n4. min\n0. exit\n");
    scanf("%d", &option);

    if(option == 1) {
      struct node *newnode = build_node();
      printf("value: ");
      scanf("%d", &i_aux);
      newnode->value = i_aux;
      newnode->below = NULL;
      printf("antes do push\n");
      mystack = push(mystack, newnode);
    } else if (option == 2) {
      pop(mystack);
    } else if (option == 3) {
      print_values(mystack);
    } else if (option == 4) {
      if(mystack == NULL || mystack->top == NULL) {
        printf("invalid stack.\n");
      } else {
        printf("%d\n", mystack->top->min);
      }
    } else if(option == 5) {
      push(mystack, teste);
      if(mystack == NULL ) {
        printf("ta null ainda aff\n");
      } else {
        printf("not null\n");
      }
    }
  }
  return 0;
}
