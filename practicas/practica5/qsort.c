#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"

static int compareById(const void *av, const void *bv)
{
    Student *a = (Student *)av;
    Student *b = (Student *)bv;
    return a->id - b->id;
}

static int compareByName(const void *av, const void *bv)
{
    Student *a = (Student *)av;
    Student *b = (Student *)bv;
    return strcmp(a->name, b->name);
}

void sortById(Student *classroom, int n)
{
    qsort((void *)classroom, n, sizeof(Student), compareById);
}

void sortByName(Student *classroom, int n)
{
    qsort((void *)classroom, n, sizeof(Student), compareByName);
}
