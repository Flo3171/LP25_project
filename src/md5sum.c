/**
 * @file md5sum.c
 * @author Florian Cloarec
 * @brief source file that contain the implementation of the function in the md5sum part of the project
 * @version 0.1
 * @date 15 June 2021
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "include.h"

int compute_md5(char *path, unsigned char buffer[])
{

    //créer un md5
    /*
    MD5_CTX *c = NULL;
    FILE *f = fopen(path, "r");
    char *str = (char*)malloc(512 * sizeof(char));

    MD5_Init(c);
    fseek(f, 0L, SEEK_END);
    long size = ftell(f);
    rewind(f);

    while (size > 0)
    {
        if (size > 512)
        {
            str = fgets(str, 512, f);
            MD5_Update(c, str, 512);
        }
        else
        {
            str = fgets(str, size, f);
            MD5_Update(c, str, size);
        }
        size -= 512;
    }

    MD5_Final(buffer, c);
    fclose(f);
    free(str);
    
    return 1;
    */
}
