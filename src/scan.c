/**
 * @file scan.c
 * @author Florian Cloarec
 * @brief source file that contain the implementation of the function in the scan part of the project
 * @version 0.1
 * @date 07 June 2021
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "include.h"

s_directory *process_dir(char *path){

    DIR* dir = opendir(".");
    if (dir == NULL){
        fprintf(stderr, "unable to open the dir : %s\n", path);
        exit(0);
    }

    s_directory* directory = (s_directory*)malloc(sizeof(s_directory));
    if (directory == NULL){
        fprintf(stderr, "unable to allocate memory\n");
        exit(0);
    }

    directory->files = NULL;
    directory->next_dir = NULL;

    


    struct dirent* dirent;
    while ((dirent = readdir(dir)) != NULL)
    {
        if (dirent->d_type == DT_DIR)
        {
            //process dir
        }
        else{
            //process file
        }
    }
    return directory;

}

s_file *process_file(char *path){

    s_file* newFile = (s_file*)malloc(sizeof(s_file));
    
    struct stat *fileStat;
    stat(path, fileStat);

    switch (fileStat->st_mode){
        case S_IFREG:
        {
            /* regular file */
            newFile->file_type = REGULAR_FILE;
            newFile->name = getFileName(path);
            newFile->mod_time = fileStat->st_mtim.tv_sec;
            newFile->file_size = fileStat->st_size;
            
            char md5sum[MD5_DIGEST_LENGTH];
            compute_md5(path, md5sum);
            newFile->md5sum = md5sum;

            newFile->pointed_file = NULL;
            newFile->next_file = NULL;
            break;
        }
        case S_IFDIR:
            /*directory*/
            return NULL;
            break;

        case S_IFLNK:
        {
            /* symbolik link */
            newFile->file_type = SYMBOLIK_LINK;
            newFile->name = getFileName(path);
            newFile->mod_time = fileStat->st_mtim.tv_sec;
            newFile->file_size = 0;
            newFile->md5sum = NULL;

            char pointed_file_path[MAXNAMLEN+1];
            readlink(path, pointed_file_path, sizeof(pointed_file_path));

            newFile->pointed_file = process_file(pointed_file_path);
            newFile->next_file = NULL;
            break;
        }
            
        
        default :
            /*other*/
            newFile->file_type = OTHER_TYPE;
            newFile->name = getFileName(path);
            newFile->mod_time = fileStat->st_mtim.tv_sec;
            newFile->file_size = 0;
            newFile->md5sum = NULL;
            newFile->pointed_file = NULL;
            newFile->next_file = NULL;
            break;
    }
    return newFile;
}

void free_s_file(s_file* file){
    free(file->name);
    free(file->md5sum);
    free(file);
}

void free_s_directory(s_directory* dir){
    free(dir->name);
    free(dir);
}

