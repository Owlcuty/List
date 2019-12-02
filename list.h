#include <stdio.h>
#include <string.h>

#include <assert.h>
#include <errno.h>

#define EXIT_SUCCESS 0

extern const int HowRise;

typedef struct
{
  char* data;
  int sizeof_data;

  int* next;

  size_t size;
  int head;
  int free;
} List;

int list_init(List* list, size_t sizeofType, size_t num_el);
int list_InsertAfter(List* list, int pos, const void* value_p);
int list_DeleteAfter(List* list, int pos);
int list_Ok(List* list);
int list_Resize(List* list);
int list_Destruct(List* list);
int list_Print(List list);
