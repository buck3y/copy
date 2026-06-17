#include <stddef.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[]){
   
    if (argc < 2)
    {
        printf("cp: missing file operand\n");
        return 1;
    }
    else if (argc < 3) {
        printf("cp: missing destination file operand after %s", argv[1]);
        return 2;
    }


    FILE* fptr1;
    fptr1 = fopen(argv[1], "r");
    size_t pos = ftell(fptr1);
    fseek(fptr1, 0, SEEK_END);
    size_t length = ftell(fptr1);
    fseek(fptr1, pos, SEEK_SET);

    char buffer[length];
    if(fptr1 == NULL)
    {
        printf("cp: cannot stat %s : No such file or directory", argv[1]);
        return 3;
    }

    FILE* fptr2;
    fptr2 = fopen(argv[2], "w");
    if(fptr2 == NULL)
    {
        printf("cp: cannot stat %s : No such file or directory", argv[1]);
        return 4;
    }

    while(!feof(fptr1))
    {
        fgets(buffer, 256, fptr1);
        fprintf(fptr2, buffer);
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;

}
