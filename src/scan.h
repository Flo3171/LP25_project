#ifndef _SCAN_H_
#define _SCAN_H_

/**
 * @file scan.h
 * @author Florian Cloarec
 * @brief header file of the function and struct in the scan part of the project
 * @version 0.1
 * @date 07 June 2021
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */


/**
 * @brief recursive fuction that scan a directory and create the struct in memory whith all the sub directory and file
 * 
 * @param path : the path of the directory to scan
 * @return s_directory* : the struct with all the data about the directory
 * @author Florian CLOAREC
 */
s_directory *process_dir(char *path);


/**
 * @brief create and combute the struc s_file whit the data of a file
 * 
 * @param path : the path of the file to comute
 * @return s_file* : the struct with all the data avout the file
 * @author Florian CLOAREC
 */
s_file *process_file(char *path);



#endif  //_SCAN_H_