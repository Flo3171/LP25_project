#include "include.h"

int main(int argc, char const *argv[])
{
    printf("*************program start*************\n");

    s_directory* dir;
    if (argc == 1){
        dir = process_dir("./test", true);
    }
    else{
       dir = process_dir(argv[1], true);
    }

    // printf("%s\n", getFilePath("coucou", "/bin/src"));


    


    printf("*************program stop*************\n");
    return 0;
}
