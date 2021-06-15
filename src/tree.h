#ifndef _TREE_H
#define _TREE_H



int append_subdir(s_directory *child, s_directory *parent);
int append_file(s_file *child, s_directory *parent);
void clear_files(s_directory *parent);
void clear_subdirs(s_directory *parent);

/**
 * @brief free a s_file variable
 * 
 * @param file 
 * @author Florian CLOAREC
 */
void free_s_file(s_file* file);


/**
 * @brief  free a s_directory variable
 * 
 * @param dir 
 * @author Florian CLOAREC
 */
void free_s_directory(s_directory* dir);

#endif
