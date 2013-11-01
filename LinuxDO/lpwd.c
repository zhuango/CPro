#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

ino_t get_inode(char *);
void printpathto(ino_t);
void inum_to_name(ino_t , char *, int);

int main()
{
	printpathto(get_inode("."));//get_inode is the function can get the inode number
	putchar('\n');

	return 0;
}

/*get the current dirent*/
void printpathto(ino_t this_inode)
{
	ino_t my_inode;
	char its_name[BUFSIZ];
	if(get_inode("..") != this_inode)/*Is it the root dirent???*/
	{
		
		chdir("..");/*If it's not the root, then do to the father dirent*/
		inum_to_name(this_inode, its_name, BUFSIZ);/*get the dirent name*/
		my_inode = get_inode(".");/*get the current dirent inode*/
		printpathto(my_inode);/*again, run the ptinpathto*/
		printf("/%s",its_name);/*print the dirent name one by one*/
	}
}

/*get the dirent name*/
void inum_to_name(ino_t inode_to_find, char *namebuf, int buflen)
{
	DIR *dir_ptr;
	struct dirent *direntp;
	dir_ptr = opendir(".");/*open the current dirent (to get the child dirent name)*/
	if(dir_ptr == NULL){
		perror(".");
		exit(EXIT_FAILURE);
	}

	while((direntp = readdir(dir_ptr)) != NULL)/*read the dir to find the child inode*/
		if( direntp->d_ino == inode_to_find)/*find the inode*/
		{
			strncpy(namebuf, direntp->d_name, buflen);/*get the name of the child*/
			namebuf[buflen-1] = '\0';
			closedir(dir_ptr);/*close the dirent*/
			return ;
		}

	/*didn't find the dirent*/
	fprintf(stderr,"error looking for inum %d\n", inode_to_find);
	exit(EXIT_SUCCESS);
}

ino_t get_inode(char *fname)
{

	struct stat info;

	/*get the file info*/
	if(stat(fname, &info) == -1){
		fprintf(stderr,"Cannot stat");
		perror(fname);
		exit(EXIT_FAILURE);
	}

	/*return the inode number of the file*/
	return info.st_ino;

}

