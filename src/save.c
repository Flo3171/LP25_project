//
// Created by theod on 08/06/2021.
//

#include "save.h"

int save_to_file(s_directory *root, const char* path_to_target, const char* current_path) {
    FILE *output = fopen(path_to_target, "w");
    if (!output) {
        perror("ERROR: Couldn't open target file");
        fprintf(stderr, "Couldn't open %s!\n", path_to_target);
        return NULL;
    }

    int res = save_to_file_recursive(output, root, 0, current_path);

    fclose(output);

    return res;
}

int save_to_file_recursive(FILE* output, s_directory* current_dir, int depth, const char* current_path) {
    //Put the right number of tabulations in a string (VLA!)
    char tabulations[depth + 2];
    int i = 0;
    for (; i < depth; i++) {
        tabulations[i] = '\t';
    }
    tabulations[i] = '\0';

    //write the current directory informations
    fputs(tabulations, output);
    construct_dir_line(output, *current_dir, current_path);
    fputs("\n", output);

    tabulations[i] = '\t';
    tabulations[i+1] = '\0';

    //writes files
    s_file *current_file = current_dir->files;
    while (current_file != NULL) {
        fputs(tabulations, output);
        construct_file_line(output, *current_file, current_path);
        fputs("\n", output);

        current_file = current_file->next_file;
    }

    s_directory *subdir = current_dir->subdirs;
    while (subdir != NULL) {
        char* new_path = (char*)malloc(strlen(current_path) + strlen(subdir->name) + 2);
        strcpy(new_path, current_path);
        strcat(new_path, "/");
        strcat(new_path, subdir->name);
        if (!save_to_file_recursive(output, subdir, depth+1, new_path)) {
            return 1;
        }
        subdir = subdir->next_dir;
    }

    return 0;
}

int construct_file_line(FILE* output, s_file file, const char* path_to_parent_dir){
    char buffer[200] = {0};

    fputs("1\t", output); //e_type

    strftime(buffer, 200, "%Y-%m-%d %H:%M:%S\t", localtime(&file.mod_time));
    fputs(buffer, output); //time_t

    sprintf(buffer, "%lu\t", file.file_size);
    fputs(buffer, output); //size

    for (size_t n = 0; n < MD5_DIGEST_LENGTH; n++) {
        fprintf(output, "%02hhx", file.md5sum[n]);
    }

    fputs("\t", output); //md5sum

    fprintf(output, "%s/%s", path_to_parent_dir, file.name); // path

    return 0;
}

int construct_dir_line(FILE* output, s_directory dir, const char* path_to_parent_dir){
    char lil_buf[200] = {0};

    fputs("0\t", output); //e_type

    strftime(lil_buf, 200, "%Y-%m-%d %H:%M:%S\t", localtime(&dir.mod_time));
    fputs(lil_buf, output); //time_t

    fprintf(output, "%s/", path_to_parent_dir); // path

    return 0;
}

int construct_other_line(FILE* output, s_file file, const char* path_to_parent_dir){
    char buffer[200] = {0};

    fputs("2\t", output); //e_type

    strftime(buffer, 200, "%Y-%m-%d %H:%M:%S\t", localtime(&file.mod_time));
    fputs(buffer, output); //time_t

    fprintf(output, "%s/%s", path_to_parent_dir, file.name); // path

    return 0;
}
