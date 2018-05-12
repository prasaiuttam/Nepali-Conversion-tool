#ifndef PREETI2UNICODE_H
#define PREETI2UNICODE_H
#include"unicode2.h"
#include"devnagri.h"
#include"tools.h"
#include<string>
#include<vector>
std::string preeti_Converter(std::string abc)
{
	Unicode separator;
	separator=abc;
	Database db;
	std::vector<std::string> preeti;
	/*
	 *Preeti is of type vector<string>
	 *We will use it to store one preeti unit(not one byte or one utf-8 character)
	 */
	for(int i=0; i<separator.length_Unicode();i++)
	{
		std::string temp;
		temp=(separator+i);
		if(test_Compound(temp))
		{
			temp+=(separator+(i+1));
			if(test_DoubleCompound(temp))
			{
				temp+=(separator+(i+2));
				std::string temp2;
				temp2=temp[2];
				if(temp2=="}" || temp2=="]")
				{
					preeti.push_back(temp);
					i+=2;
				}
				else//if(temp2=="}" || temp2=="]")
				{
					preeti.push_back("cf");
					i++;
				}
			}
			else//if(test_DoubleCompound(temp))
			{
				if(confirm_Compound(temp))
					{
						preeti.push_back(temp);
						i++;
					}
				else
					preeti.push_back((separator+i));
			}

		}
		else//if(test_Compound)
		{
			preeti.push_back(separator+i);
		}

	}
	//Here comes the converting algorithm
	std::vector<std::string> converted;
	Compare penultimate_char;
	Compare antipenultimate_char;
	for(int i=0;i<preeti.size();i++)
	{
		Compare c=db.return_Index(preeti[i]);
		if (c.value==EXCEPTION)
		{
			converted.push_back(preeti[i]);
		}
		else
		{
			if(c.type==1)
			{
            	converted.push_back(unicode_Generator(c.value));
                if(penultimate_char.value==0x3f&&i!=0)
                {
                    swap(converted[i],converted[i-1]);
                }

			}
			else if(c.type==2)
			{
                std::string temp;
				temp+=unicode_Generator(c.value);
				temp+="्";
                converted.push_back(temp);
                if(c.value==0x30&&i!=0) //र्
                {
                    swap(converted[i],converted[i-1]);
                    int p=penultimate_char.value;
                    if(p==0x40||p==0x3e||p==0x4b||p==0x41||p==0x42||p==47||p==48&&i!=1)  //ी   ा   ो  ु ू े ै
					{
                        swap(converted[i-1],converted[i-2]);
                    }
                    if(antipenultimate_char.value==0x3f&&i!=1)  //ि
                    {
                        swap(converted[i-1],converted[i-2]);
                    }



                }
                else if(penultimate_char.value==0x3f&&i!=0)
                {
                    converted[i]+="‍";//Zero Width Joiner lies here
                    swap(converted[i],converted[i-1]);

                }
			}
			else if(c.type==3)
			{
                std::string temp;
                if(c.value==0)//Question Mark
                {
                    converted.push_back("?");
                }
                else if(c.value==1)
                {
					converted.push_back("्र");
					if(antipenultimate_char.value==0x3f)
                        swap(converted[i],converted[i-1]);
                }
                else if(c.value==2)
                {
					converted.push_back("र्‍");
                }
                else if(c.value==3)
                {
					converted.push_back("रु");
                }
                else if(c.value==4)
                {
					converted.push_back("रू");
                }
                else if(c.value==5)
                {
					converted.push_back("(‍");
				}
                else if(c.value==6)
                {
					converted.push_back(")");
                }
			}
			antipenultimate_char=penultimate_char;
			penultimate_char=c;
		}
	}
	std::string return_string;
	for(int i=0;i<converted.size();i++)
	{
		return_string+=converted[i];
	}
	return return_string;
}
#endif //PREETI2UNICODE_H
