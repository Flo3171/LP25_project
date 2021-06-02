//
// Created by theod on 02/06/2021.
//

#ifndef LP25_PROJECT_TYPES_H
#define LP25_PROJECT_TYPES_H

#include <linux/limits.h>
#include <time.h>
#include <openssl/md5.h>

typedef enum {DIRECTORY, REGULAR_FILE, OTHER_TYPE} e_type;

typedef struct _file {
    e_type file_type;
    char name[NAME_MAX+1];
    time_t mod_time;
    uint64_t file_size;
    u_char md5sum[MD5_DIGEST_LENGTH];
    struct _file *next_file;
} s_file;

typedef struct _directory {
    char name[NAME_MAX+1];
    time_t mod_time;
    struct _directory *subdirs;
    s_file *files;
    struct _directory *next_dir;
} s_directory;

#endif //LP25_PROJECT_TYPES_H
