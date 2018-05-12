#ifndef FILETOFILE2_H
#define FILETOFILE2_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include<string>
#include "preeti2unicode.h"
void convert_file_Preeti(std::string file_name,std::string folder_name)
{
	FILE *fileto_convert,*converted;
	fileto_convert=fopen("raw_file.nct","w");
	fprintf(fileto_convert,"%s",file_name.c_str());
	fclose(fileto_convert);
	system("python3 preeti2unicode.py");
	fileto_convert=fopen("raw_file.nct","r");
    char c=fgetc(fileto_convert);
    std::string whole_string;
	while(c!=EOF)
	{
        whole_string+=c;
        c=fgetc(fileto_convert);
	}
    fclose(fileto_convert);
    converted=fopen("converted.nct","w");
    fprintf(converted,"%s",file_name.c_str());
    fprintf(converted,"%s","<#!new_run#!>");
    fprintf(converted,"%s",folder_name.c_str());
    fprintf(converted,"%s","<#!new_run#!>");
    whole_string=preeti_Converter(whole_string);
    std::string run_string;
    for(int i=0;i<whole_string.length();i++)
    {
        if(whole_string[i]=='\0')
        {
            fprintf(converted,"%s",run_string.c_str());
           	fprintf(converted,"%s","<#!new_run#!>");
           	run_string="";
           	i++;
        }
        run_string+=whole_string[i];
    }
    fprintf(converted,"%s","<#!new_run#!>");
    fclose(converted);
    system("python3 make_unicode_docx.py");
}
#endif //FILETOFILE2_H
