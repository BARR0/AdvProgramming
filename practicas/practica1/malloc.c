#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doFullName(char *firstName,
               char *lastName,
               char **fullName)
{
    int sizefn = strlen(firstName);
    int sizeln = strlen(lastName);
    *fullName = (char *)malloc((sizefn + sizeln + 1) * sizeof(char));
    strcpy(*fullName, firstName);
    strcpy(*fullName + sizefn, " ");
    strcpy(*fullName + sizefn + 1, lastName);

    return 0;
}

int main()
{
    char fn[] = "Andrés";// Se puede modificar.
    char *ln = "Barro";// Si se almacena en char *, es una constante.
    char *fullName;
    doFullName(fn, ln, &fullName);
    printf("fullName = %s\n", fullName);
    free(fullName);
    return 0;
}
