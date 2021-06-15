//
// Created by theod on 08/06/2021.
//

#ifndef LP25_PROJECT_SAVE_H
#define LP25_PROJECT_SAVE_H

#include "include.h"

int save_to_file(s_directory * root, const char* path_to_target, const char* current_path);

int save_to_file_recursive(FILE* output, s_directory* current_dir, int indentation_level, const char* current_path);

int write_file(FILE* output, s_file file, const char* path_to_parent_dir);

int write_directory(FILE* output, s_directory dir, const char* path_to_parent_dir);

int write_other(FILE* output, s_file file, const char* path_to_parent_dir);

#endif //LP25_PROJECT_SAVE_H
