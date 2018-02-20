#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "qsort.h"

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

static char *testUnit()
{
  muAssert("error, testUnit 1 != 1", 1 == 1);
  return 0;
}

static char *testSortIds()
{
  Student class[] = {
      {2, "juan"},
      {0, "sandra"},
      {5, "angel"}
  };
  sortById(class, 3);
  muAssert("error, testSortIds shuold be sandra", strcmp(class[0].name, "sandra") == 0);
  return 0;
}

static char *testSortNames()
{
  Student class[] = {
      {2, "juan"},
      {0, "sandra"},
      {5, "angel"}
  };
  sortByName(class, 3);
  muAssert("error, testSortName shuold be angel", strcmp(class[0].name, "angel") == 0);
  return 0;
}

static char *allTests()
{
  muRunTest(testSortIds);
  muRunTest(testSortNames);
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
