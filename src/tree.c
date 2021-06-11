#include "tree.h"

int append_subdir(s_directory *child, s_directory *parent)
{
	if(parent->subdirs == NULL){
		parent->subdirs = child;
	}
	else{
		s_directory * temp = parent->subdirs;
		while(temp->next_dir!=NULL){
			temp = temp->next_dir;
		}
		temp->next_dir = child;
	}
	
	//Je sais pas quoi retourner
	if(parent->subdirs == NULL)return 0;
	else return 1;
}

int append_file(s_file *child, s_directory *parent)
{
	if(parent->files == NULL){
		parent->files = child;
	}
	else{
		s_file * temp = parent->files;
		while(temp->next_file!=NULL){
			temp = temp->next_file;
		}
		temp->next_file = child;
	}
	
	//Je sais pas quoi retourner
	if(parent->files == NULL)return 0;
	else return 1;
}

void clear_files(s_directory *parent)
{
	s_file *temp = parent->files;
	s_file *temp1 = NULL;
	while(temp != NULL){
		temp1 = temp->next_file;
		free(temp);
		temp = temp1;
	}
}

void clear_subdirs(s_directory *parent)
{
	s_directory *temp = parent->subdirs;
	s_directory *temp1 = NULL;
	
	while(temp != NULL){
		if(temp->subdirs != NULL)clear_subdirs(temp);
		if(temp->files != NULL)clear_files(temp);
		temp1 = temp->next_dir;
		free(temp);
		temp = temp1;
	}
}
