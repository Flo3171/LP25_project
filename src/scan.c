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

    DIR *dir;
    struct dirent *dirent;
    dir = opendir(path);
    if (dir == NULL){
        printf("unable to open the dir");
        exit(0);
    }
    

    // s_directory* directory = (s_directory*)malloc(sizeof(s_directory));

    // directory->name = NULL;
    // directory->mod_time = 1;
    // directory->subdirs = NULL;
    // directory->files = NULL;
    // directory->next_dir = NULL;
    dirent = readdir(dir);
    while (dirent != NULL){
        
        printf("name :%s\t\t", dirent->d_name); 
        printf("type :%d\t", dirent->d_type);
        printf("inode :%lu \t", dirent->d_ino);
        printf("off :%ld\t",dirent->d_off);
        printf("reclen :%d\n", dirent->d_reclen);
        
    
        dirent = readdir(dir);
        
    }

    closedir(dir);

    return NULL;// directory;

}

s_file *process_file(char *path){


    // s_file* file = (s_file*)malloc(sizeof(s_file));

    // file->file_type = REGULAR_FILE;
    // file->name = NULL;
    // file->mod_time = 1;
    // file->file_size = 1;
    // file->md5sum = NULL;

    // if(file->file_type == SYMBOLIK_LINK){
    //     file->pointed_file = process_file(NULL);
    // }
    // else{
    //     file->pointed_file = NULL;
    // }
    


    // file->next_file = NULL;

    return NULL; //file;
}