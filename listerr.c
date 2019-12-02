#include "listerr.h"

const char* OutListErr = {
  "%i::List{%s} Wrong initialization of List",
  "%i::List{%s} Can't insert after %i elem %i",
  "%i::List{%s} Can't delete after %i",
  "%i::List{%s} Can't destruct List"
};

int list_perror(int err, const char* listName, int elErr, int valErr)
{
  assert(err < LastEmptyErr);

  printf(OutListErr[err], __LINE__, listName, elErr, valErr);

  return -1;
}
