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
    if (argc < 3) return 1;
    char *search = argv[1];
    char *update = argv[2];
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
            strcpy(myStudent.firstName, update);
            fseek(data, -1 * sizeof(Student), SEEK_CUR);
            fwrite(&myStudent, sizeof(Student), 1, data);
            break;
        }
    }
    fclose(data);
    return 0;
}
