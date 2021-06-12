#include "include.h"

/**
 * @brief Calcule la marque MD5 d'un fichier
 * 
 * @param path chemin du fichier à calculer
 * @param buffer 
 * @return int 
 */
int compute_md5(char *path, unsigned char buffer[])
{

    //créer un md5
    
    MD5_CTX *c;
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
            MD5_Update(&c, str, 512);
        }
        else
        {
            str = fgets(str, size, f);
            MD5_Update(&c, str, size);
        }
        size -= 512;
    }

    MD5_Final(buffer, c);
    
}