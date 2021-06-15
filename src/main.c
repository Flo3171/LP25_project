#include "include.h"

int main(int argc, char *argv[])
{
	int opt;
	char * dir_analyze = NULL;
	char * save_file = NULL;
	bool md5 = false;
	while((opt=getopt(argc,argv,"i:so:")) != -1)
	{
		switch(opt)
		{
			case 'i':dir_analyze = malloc(sizeof(char)*strlen(optarg)+1);
				dir_analyze = optarg;
				//printf("i : %s\n",dir_analyze);
				break;
			case 'o':save_file = malloc(sizeof(char)*strlen(optarg)+1);
				save_file = optarg;
				//printf("o : %s\n",save_file);
				break;
			case 's': md5 = true;
                //printf("s\n");
				break;
		}
	}
	// No special output file path specified
	if(save_file == NULL){
	    // Check if output directory exists
        struct stat s;

        if (lstat(".filescanner/", &s) == -1) {
            if (mkdir(".filescanner/", 0777) == -1) {
                fprintf(stderr, "Couldn't create directory .filescanner!\n");
                return 1;
            }
        }
        save_file = generateFileName();
	}
    printf("*************program start*************\n");
	
    s_directory* dir;
    if (dir_analyze == NULL){
        dir = process_dir(".",md5);
    }
    else{
       dir = process_dir(dir_analyze,md5);
    }

	printf("%s\n",dir->name);
    // printf("%s\n", getFilePath("coucou", "/bin/src"));

    save_to_file(dir, save_file, dir_analyze);

    printf("*************program stop*************\n");
    // Liberating memory
    free(save_file);
    return 0;
}
