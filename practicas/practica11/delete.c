#include <stdio.h>
#include <string.h>

typedef struct
{
    char firstName[20];
    char lastName[20];
    short id;
    char semester[3];
    char free;
} Student;

int main(int argc, char **argv)
{
    if (argc < 2) return 1;
    char *search = argv[1];
    char *dbName = "student.dat";
    FILE *data = fopen(dbName, "r+b");
    Student myStudent;
    while(1)
    {
        fread(&myStudent, sizeof(Student), 1, data);
        if (feof(data))
        {
            break;
        }
        if(!strcmp(myStudent.firstName, search))
        {
            myStudent.free = 1;
            fseek(data, -1 * sizeof(Student), SEEK_CUR);
            fwrite(&myStudent, sizeof(Student), 1, data);
            break;
        }
    }
    fclose(data);
    return 0;
}
