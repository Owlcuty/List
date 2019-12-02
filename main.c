#include <stdio.h>
#include <stdlib.h>

#include "list.c"
#include "listerr.c"

int main()
{
  List list = {};
  int num = 10;
  if (list_init(&list, sizeof(int), 10))
  {
    return list_perror(InitErr, NAME_OF_LIST(list), 0, 0);
  }
  list_InsertAfter(&list, 0, &num);

  list_Print(list);

  list_Destruct(&list);
}
