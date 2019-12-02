#define NAME_OF_LIST(listName) #listName
enum ListErr
{
  InitErr,
  InsertAfterErr,
  DeleteAfterErr,
  DestructErr,
  LastEmptyErr
};

extern const char* OutListErr;

int list_perror(int err, const char* listName, int elErr, int valErr);
