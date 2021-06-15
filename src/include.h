#ifndef _INCLUDE_H_
#define _INCLUDE_H_

/**
 * @file include.h
 * @author Florian Cloarec
 * @brief header file that contain all the header file to include in the other  part 
 * @version 0.1
 * @date 07 June 2021
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include <linux/limits.h>
#include <time.h>
#include <openssl/md5.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

#include "types.h"

#include "scan.h"
#include "md5sum.h"
#include "utils.h"
#include "tree.h"


#endif //_INCLUDE_H_
