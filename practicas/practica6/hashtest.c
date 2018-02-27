#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "hash.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

unsigned hash(void *key, unsigned size)
{
  return 0;
}

unsigned hash2(void *key, unsigned size)
{
  unsigned char *str = (char *)key;
  unsigned hash = 5381;
  int c;
  while (c = *str++)
    hash = ((hash << 5) + hash) + c;
  return hash % size;
}

void *caster(void *element)
{
  char *realValue = (char *)element;
  return (void *)strdup(realValue);
}

void *copyString(void *element)
{
  return (void *)strdup((char *)element);
}

int cmpKeys(void *this, void *that)
{
  return !strcmp((char *)this, (char *)that);
}

static char *testFull()
{
  Hash myHash;
  unsigned size = 10;
  initHash(&myHash, size, hash2, copyString, copyString, cmpKeys);

  char key[20];
  char value[20];
  for (int i = 0; i < size * 2; i++)
  {
    sprintf(key, "Hello%02d", i);
    sprintf(value, "Hola%02d", i);
    insertHash(&myHash, (void *)key, (void *)value);
  }

  char *value1 = getHash(&myHash, "Hello06");
  char *value2 = getHash(&myHash, "Nothing");
  muAssert("error, get(\"Hello06\") must be \"Hola06\"", !strcmp(value1, "Hola06"));
  muAssert("error, get(\"Nothing\") must be NULL", value2 == NULL);
  return 0;
}

static char *testGet()
{
  Hash myHash;
  unsigned size = 20;
  initHash(&myHash, size, hash, copyString, copyString, cmpKeys);

  char *key = "Hello";
  char *value = "Hola";
  insertHash(&myHash, key, value);

  char *value1 = (char *)getHash(&myHash, key);
  char *value2 = (char *)getHash(&myHash, "Goodbye");
  muAssert("error, get(\"Hello\") must be \"Hola\"", !strcmp(value1, "Hola"));
  muAssert("error, get(\"Goodbye\") must be NULL", value2 == NULL);
  return 0;
}

static char *testInsert()
{
  Hash myHash;
  unsigned size = 20;
  initHash(&myHash, size, hash, copyString, copyString, cmpKeys);

  char *key = "Hello";
  char *value = "Hola";
  insertHash(&myHash, key, value);
  muAssert("error, data[0].count must be 1", myHash.data[0].count == 1);
  muAssert("error, data[0].size must be 2", myHash.data[0].size == 2);
  muAssert("error, data[0].elements must not be null", myHash.data[0].elements != NULL);
  muAssert("error, data[0].elements[0].key must be \"Hello\"", !strcmp(myHash.data[0].elements[0].key, key));
  muAssert("error, data[0].elements[0].value must be \"Hola\"", !strcmp(myHash.data[0].elements[0].value, value));
  return 0;
}

static char *testInit()
{
  Hash myHash;
  unsigned size = 20;
  initHash(&myHash, size, hash, copyString, copyString, cmpKeys);
  muAssert("error, size must be 20", myHash.size == 20);
  muAssert("error, hash() must be 0", myHash.hash(NULL, 0) == 0);
  muAssert("error, data must not be NULL", myHash.data != NULL);
  return 0;
}

static char *allTests()
{
  muRunTest(testInit);
  muRunTest(testInsert);
  muRunTest(testGet);
  muRunTest(testFull);
  return 0;
}

int main(int argc, char **argv)
{
  char *result = allTests();
  if (result != 0)
  {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else
  {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
