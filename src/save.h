//
// Created by theod on 08/06/2021.
//

#ifndef LP25_PROJECT_SAVE_H
#define LP25_PROJECT_SAVE_H

#include "include.h"
#include <stdbool.h>

/**
    Writes the contents of `root` into the file with as path `path_to_target`.
**/
int save_to_file(s_directory * root, const char* path_to_target, const char* current_path);

/**
    Internal; recursive function to save the contents of `current_dir` into the output file `output`.
    `depth` controls the tabulation amount and `current_path` will be prepended to the file paths.
**/
int save_to_file_recursive(FILE* output, s_directory* current_dir, int depth, const char* current_path);

/**
    Internal; writes a single regular file line to `output`.
    `path_to_parent_dir` will be pretended to the file's basename.
**/
int construct_file_line(FILE* output, s_file file, const char* path_to_parent_dir);

/**
    Internal; writes a single directory line to `output`.
    `path_to_parent_dir` will be pretended to the directory's basename.
**/
int construct_dir_line(FILE* output, s_directory dir, const char* path_to_parent_dir);

/**
    Internal; writes a single other file line to `output`.
    `path_to_parent_dir` will be pretended to the file's basename.
**/
int construct_other_line(FILE* output, s_file file, const char* path_to_parent_dir);

#endif //LP25_PROJECT_SAVE_H
