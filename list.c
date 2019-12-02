#include "list.h"

const int HowRise = 2; // Resize: size *= 2

int list_init(List* list, size_t sizeofType, size_t num_el)
{
  assert(list);

  printf("%i:: Still working" "\n", __LINE__);
  list->sizeof_data = sizeofType;
  printf("%i:: sizeof_data {%d}" "\n", __LINE__, list->sizeof_data);
  list->data = (char*)calloc(num_el + 1, list->sizeof_data);
  if (!list->data)
  {
    errno = ENOMEM;
    perror("list->data");
    return -1;
  }
  list->next = (int* )calloc(num_el + 1, sizeof(*(list->next)));

  list->size = num_el + 1;
  list->head = 1;
  list->free = 1;
  printf("%i:: Still working" "\n", __LINE__);

  for (int el = 1; el < num_el - 1; el ++)
  {
    list->next[el] = el + 1;
  }
  printf("%i:: Still working" "\n", __LINE__);

  return EXIT_SUCCESS;
}

int list_InsertAfter(List* list, int pos, const void* value_p)
{
  assert(list_Ok(list));

  int free = list->free;
  if (!(list->next[free]))
  {
    list_Resize(list);
  }
  if (!list->next[pos])
  {
    if (pos)
      list->next[pos] = free;
    list->next[free] = 0;
  }
  list->free = list->next[free];
  list_Print(*list);
  memcpy(list->data + free, value_p, list->sizeof_data);

  assert(list_Ok(list));

  return EXIT_SUCCESS;
}

int list_DeleteAfter(List* list, int pos)
{
  assert(list_Ok(list));

  if (pos == list->head)
  {
    list->head = list->next[list->head];
  }
  int next_ptr = list->next[pos];
  list->next[pos] = list->free;
  list->free = pos;
  list->next[pos] = next_ptr;

  assert(list_Ok(list));

  return EXIT_SUCCESS;
}

int list_Ok(List* list)
{
  if (!(list->data))
  {
    errno = ENODATA;
    perror("Ok: list->data");
    return 0;
  }
  if (!(list->next))
  {
    errno = ENODATA;
    perror("Ok: list->data");
    return 1;
  }

  return 1;
}

int list_Destruct(List* list)
{
  assert(list_Ok(list));

  free(list->data);
  free(list->next);
  return EXIT_SUCCESS;
}

int list_Resize(List* list)
{
  assert(list_Ok(list));

  int pr_size = list->size;
  list->size *= HowRise;
  list->data = (char*)(realloc(list->data, list->size * list->sizeof_data));
  list->next = (int*) (realloc(list->next, list->size * sizeof(*list->next)));

  assert(list_Ok(list));

  list->next[list->free] = pr_size;

  for (int cur = pr_size; cur < list->size - 1; cur ++)
  {
    list->data[cur] = 0;
    list->next[cur] = cur + 1;
  }
  list->data[list->size - 1] = 0;
  list->next[list->size - 1] = 0;

  assert(list_Ok(list));
}

int list_Print(List list)
{
  for (int cur = list.head, cnt = 0; list.next[cur] || cnt < 2; cur = list.next[cur], cnt ++)
  {
    printf("%i::next[%d]{%d} Cur element[%d] = %d\n", __LINE__, cur, list.next[cur], cnt, (int)(list.data[cur]));
  }
  printf("%i:: 1" "\n", __LINE__);
  for (int el = 0; el < 10; el ++)
  {
    printf("%i:: next[%d] = %d" ";\t", __LINE__, el, list.next[el]);
    printf("%i:: data[%d] = %d" "\n", __LINE__, el, list.data[el]);
  }
}
