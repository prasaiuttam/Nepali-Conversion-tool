/**
  *Author:Prashant Subedi
  *Description:
    *File To File Conversion Function for Nepali Conversion Tool..Works for Unicode to Preeti,Not vice versa
  */
#ifndef FILETOFILE_H
#define FILETOFILE_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "unicode2preeti.h"
/*Prashant's Note:I only know file handling in C...I want to learn native C++ file handling but C is working for me*/
void convert_File_Unicode(std::string file_name,std::string folder_name)
{
	FILE *raw_file,*converted_file;
    int i;
	raw_file=fopen("raw_file.nct","w");
	fprintf(raw_file,"%s %s","Name:",file_name.c_str());
	fclose(raw_file);
	system("python3 unicode_preeti.py");
	/*
	 *The file has been edited by the above written/compiled script
	 */
	raw_file=fopen("raw_file.nct","r");
	char c=fgetc(raw_file);
	std::string whole_string;
	while(c!=EOF)
	{
		whole_string+=c;
		c=fgetc(raw_file);
	}
	std::vector<Pchar> converted=unicode_Converter(whole_string);
	fclose(raw_file);
    converted_file=fopen("converted.nct","w");
	fprintf(converted_file,"%s %s","Name:",file_name.c_str());
	fprintf(converted_file,"%s","<#!new_run#!>");
	fprintf(converted_file,"%s %s","Folder_Name:",folder_name.c_str());
	fprintf(converted_file,"%s","<#!new_run#!>");
	bool nepali=false;
	for(int i=0;i<converted.size();i++)
	{
		Pchar temp=converted[i];
		if(temp.type==NEPALI)
			nepali=true;
		for(int j=0;j<temp.preeti_char.length();j++)
		{
			if(temp.preeti_char[0]=='\0')
			{

				if(nepali==true)
					fputc('1',converted_file);
				else
					fputc('0',converted_file);
				nepali=false;
				fprintf(converted_file,"%s","<#!new_run#!>");
				break;
			}
            fputc(temp.preeti_char[j],converted_file);
		}
	}
	fprintf(converted_file,"%s","<#!new_run#!>");
	fclose(converted_file);
	system("python3 make_preeti_docx.py");

}
#endif //FILETOFILE_H
