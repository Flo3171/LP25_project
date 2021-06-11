/**
 * @file utils.c
 * @author Florian Cloarec
 * @brief  implementation file of the function who can be util for all part of the project
 * @version 0.1
 * @date 07 June 2021
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "include.h"

char* getFilePath(char* fileName, char* dirPath){
    char* filePath = (char*)malloc(sizeof(char)*(strlen(dirPath)+ strlen(fileName) + 2));
    strcpy(filePath, fileName);
    strcat(filePath, "/");
    strcat(filePath, dirPath);

    return filePath;

}