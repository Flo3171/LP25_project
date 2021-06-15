//
// Created by theod on 08/06/2021.
//

#ifndef LP25_PROJECT_SAVE_H
#define LP25_PROJECT_SAVE_H

#include "include.h"

/**
 * Save the directory tree in the file
 * @param root root to save
 * @param path_to_target file target
 * @param current_path directory's path
 * @return int
 */
int save_to_file(s_directory *root, char *path_to_target, const char *current_path);

/**
 * Internal : function that is called recursively to save the tree
 * @param output output file
 * @param current_dir directory to process
 * @param indentation_level depth level (tabulations)
 * @param current_path directory's path
 * @return int
 */
int save_to_file_recursive(FILE *output, s_directory *current_dir, int indentation_level, const char *current_path);

/**
 * Write a file line
 * @param output the output file
 * @param file file to write
 * @param path_to_parent_dir the path to paste before the file name
 * @return int
 */
int write_file(FILE *output, s_file file, const char *path_to_parent_dir);

/**
 * Write a directory line
 * @param output the output file
 * @param dir directory to write
 * @param path_to_parent_dir the path to paste before the directory name
 * @return int
 */
int write_directory(FILE *output, s_directory dir, const char *path_to_parent_dir);

/**
 * Generate file name for save_to_file
 * @return The filepath
 */
char *generateFileName();

#endif //LP25_PROJECT_SAVE_H
