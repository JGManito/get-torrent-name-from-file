//Program to extract and output the filename of a torrent file
//V0.1 05/09/2019

#include <stdio.h>
#include <string.h>

#define BUFFSIZE 1000

const char* main(int argc, char *argv[])
{
	//Variable definition
	FILE *fp;
	char filename_buff[1000];
	static char filename[BUFFSIZE];
	char *varname;
	char *varname2;
	char *torrentname=NULL;
	char buff[BUFFSIZE];
	char buff2[BUFFSIZE];
	char *saveptr;
	const char token[4] = ":";
	char name_str[4];
	int c;
	int size;
	int found = 0;
	
	torrentname = argv[1];
	
	//Read file
	
	//First iteration: Check for "name" tag
	
	//printf("Reading torrent file %s\n", torrentname);
	fp = fopen(torrentname,"r");
	fgets(buff,BUFFSIZE,fp);
		
	//printf("The read string is :%s\n",buff);
		
	varname = strdup(buff);
		
	while((varname2 = strsep(&varname,":")) != NULL){
		//printf("The read varname2 is :%s\n",varname2);
		
		sprintf(name_str,"%.4s",varname2);
		
		if (strcmp("name",name_str)==0){
			//printf("found!\n");
			//printf("%s\n",name_str);
			varname2 = strsep(&varname,":");
			//printf("The read varname2 is :%s\n",varname2);
			sprintf(filename_buff,"%s",varname2);		
			//printf("The read filename buffer is: %s\n",filename_buff);
			//printf("here!\n");
			size=strlen(filename_buff);
			//printf("here!\n");
			//printf("size: %d\n",size);
			memmove(filename,filename_buff,size-2);
			
			//printf("The read filename is :%s\n",filename);
			break;
		}
	}
	
	fclose(fp);
	
	//Second iteration: Check for "path" tag
	
	if (filename[0]=='\0'){
	
		fp = fopen(torrentname,"r");
		fgets(buff,BUFFSIZE,fp);
			
		//printf("The read string is :%s\n",buff);
			
		varname = strdup(buff);
			
		while((varname2 = strsep(&varname,":")) != NULL){
			//printf("The read varname2 is :%s\n",varname2);
			
			sprintf(name_str,"%.4s",varname2);
			
			if (strcmp("path",name_str)==0){
				//printf("found!\n");
				//printf("%s\n",name_str);
				varname2 = strsep(&varname,":");
				//printf("The read varname2 is :%s\n",varname2);
				sprintf(filename_buff,"%s",varname2);		
				//printf("The read filename buffer is: %s\n",filename_buff);
				//printf("here!\n");
				size=strlen(filename_buff);
				//printf("here!\n");
				//printf("size: %d\n",size);
				memmove(filename,filename_buff,size-2);
				
				//printf("The read filename is :%s\n",filename);
				break;
			}
		}
		fclose(fp);	
	}
	
	printf("%s\n",filename);

	return 0;
}
