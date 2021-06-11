#include "include.h"

int main(int argc, char const *argv[])
{
    printf("*************program start*************\n");
    // if (argc == 1){
    //     process_dir(".");
    // }
    // else{
    //     while (--argc > 0){
    //         process_dir(*++argv);
    //     }
    // }

    printf("%s\n", getFilePath("/bin/doc", "bon.c"));




    printf("*************program stop*************\n");
    return 0;
}
