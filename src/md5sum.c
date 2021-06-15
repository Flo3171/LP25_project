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
    FILE* f = fopen(path,"rb");
    MD5_CTX md5Context;
    int bytes;
    unsigned char data[1024];
    
    if(f==NULL){
    	printf("%s can't be opened",path);
    	return 0;
    }
    
    MD5_Init(&md5Context);
    while((bytes=fread(data,1,1024,f)) !=0)
    	MD5_Update(&md5Context,data,bytes);
    MD5_Final(buffer,&md5Context);
    
    fclose(f);
    
    return 1;
}
