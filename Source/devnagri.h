/*Written by Prashant Subedi...for the Nepali Conversion Tool*/
#ifndef DEVANAGRI_H//header gaurd
#define DEVANAGRI_H
#include<string>
#include<iostream>
#include"tools.h"
//using namespace std; NOT in header file...against c++ standard
struct Devanagari
{
        /*I could have  used a class here, but I am creating this data type primarily to store
        data..and for that 'i feel' structure is much more logical...(may be its the part of me that still likes C more than c++)*/
        private:
			std::string character;//maximum size that needs to be returned
			int length;//no of charcater unicode characters it reperesents..NOT the size in bytes
			int change_position;//it needs to be done in case of some characters
        public:
			void to_Change(int a)
			{
				change_position=a;
			}
			int change_By()
			{
				return change_position;
			}
			Devanagari()
			{
				length=0;
				change_position=0;
			}
			void  copy_to_dev(std::string p)
			{
				character=p;
				length++;//one character is asumed to be passed ..for greater....use ++
			}
			std::string return_Dev()
			{
				return character;
			}
			int size_of_dev()
			{
				return length;
			}
			void operator+=(Devanagari d)
			{
				character+=d.character;
				length+=d.length;
			}
			void operator+=(std::string s)
			{
				character+=s;
				length++;
			}
			void operator++(int)
			{
				length++;
			}
			Devanagari operator+(Devanagari d)
			{
			/*Becareful while using this method!!! The order in which the characters are listed plays a vital role..*/
				Devanagari dev;
				dev.character=character+d.character;
				dev.length= length+d.length;
				return dev;
			}

};

struct Compare
{
	int type;
	int value;
};
//Prashant
class Database
{
    private:
		/*Note To  Self : I am using an arry of user-defined data type devanagari...not an arry of characters...each individual
		devanagari character is stored as a string...(see copy to srting method)*/
		Devanagari data[256];
		Devanagari hdata[256];//I know that it is a waste of space, but it makes writing the code A LOT easier....:p
		Devanagari otherdata[10];//Again :p
		/*
		 *After asking my friend again and again to see file handling.....which she didn't do...i have decided to do something
		  despreate...i will be regretting it the whole time..:p Ankita...
		 *Update:!!Now that I think about it, this method was much more superior that the earlier model.
		 */
		void assign_FullPreeti();
		void assign_HalfPreeti();
		void assign_OtherPreeti();
		//void assign_ComplexPreeti();
	public:
		/*The above functions will only be called once....and are very long...hence no need to request them to be inline...but the
		later are better as inline..*/
		Database()
		{
			assign_FullPreeti();
			assign_HalfPreeti();
			assign_OtherPreeti();
		//assign_ComplexPreeti();

		}
		Compare return_Index(std::string);
		Devanagari return_FullPreeti(int i)
		{
			return  data[i];
		}
		Devanagari return_HalfPreeti(int i)
		{
			return hdata[i];
		}
		Devanagari return_OtherPreeti(int i)
		{
			return otherdata[i];
		}

};
void Database::assign_FullPreeti()
{
        /*Apparently you ca use hexadecimal numbers in the index....lucky me......it would have been a pain to convert the
        numbers to decimal*/
        /*I have only included those which I think will occur in Nepali..Hence,the missing numbers.*/
        data[0x1].copy_to_dev("F");//ँ sign
        data[0x2].copy_to_dev("+");//ं sign
        data[0x5].copy_to_dev("c");//अ
        data[0x6].copy_to_dev("cf");//आ
        data[0x7].copy_to_dev("O");//इ
        data[0x8].copy_to_dev("O{");//ई
        data[0x9].copy_to_dev("p");//उ
        data[0xa].copy_to_dev("pm");//ऊ
        data[0xb].copy_to_dev("C");//ऋ
        data[0xf].copy_to_dev("P");//ए
        data[0x10].copy_to_dev("P]");//ऐ
        data[0x13].copy_to_dev("cf]");//ओ
        data[0x14].copy_to_dev("cf}");//औ
        data[0x15].copy_to_dev("s");//क
        data[0x16].copy_to_dev("v");//ख
        data[0x17].copy_to_dev("u");//ग
        data[0x18].copy_to_dev("3");//घ
        data[0x19].copy_to_dev("ª");//ङ
        data[0x1a].copy_to_dev("r");//च
        data[0x1b].copy_to_dev("5");//छ
        data[0x1c].copy_to_dev("h");//ज
        data[0x1d].copy_to_dev("em");//झ
        data[0x1e].copy_to_dev("`");//ञ
        data[0x1f].copy_to_dev("6");//ट
        data[0x20].copy_to_dev("7");//ठ
        data[0x21].copy_to_dev("8");//ड
        data[0x22].copy_to_dev("9");//ढ
        data[0x23].copy_to_dev("0f");//ण
        data[0x24].copy_to_dev("t");//त
        data[0x25].copy_to_dev("y");//थ
        data[0x26].copy_to_dev("b");//द
        data[0x27].copy_to_dev("w");//ध
        data[0x28].copy_to_dev("g");//न
        data[0x2a].copy_to_dev("k");//प
        data[0x2b].copy_to_dev("km");//फ
        data[0x2c].copy_to_dev("a");//ब
        data[0x2d].copy_to_dev("e");//भ
        data[0x2e].copy_to_dev("d");//म
        data[0x2f].copy_to_dev("o");//य
        data[0x30].copy_to_dev("/");//र
        data[0x32].copy_to_dev("n");//ल
        data[0x35].copy_to_dev("j");//व
        data[0x36].copy_to_dev("z");//श
        data[0x37].copy_to_dev("if");//ष
        data[0x38].copy_to_dev(";");//स
        data[0x39].copy_to_dev("x");//ह
        data[0x3c].copy_to_dev("Þ");//़
        data[0x3d].copy_to_dev("˜");//ऽ
        data[0x3e].copy_to_dev("f");//ा
        data[0x3f].copy_to_dev("l");//ि
        data[0x40].copy_to_dev("L");//ी
        data[0x41].copy_to_dev("'");//ु
        data[0x42].copy_to_dev("\"");//ू// '/ ' is required
        data[0x43].copy_to_dev("[");//ृ
        data[0x47].copy_to_dev("]");//े//this and next 4 not working.....fixed it!!.apparently the problem was in my unicode generator function
        data[0x48].copy_to_dev("}");//ै
        data[0x4b].copy_to_dev("f]");//ो
        data[0x4c].copy_to_dev("f}");//ौ
        data[0x4d].copy_to_dev("\\");//्
        data[0x64].copy_to_dev(".");//।
        data[0x65].copy_to_dev("..");//।
        data[0x66].copy_to_dev(")");//०
        data[0x67].copy_to_dev("!");//१
        data[0x68].copy_to_dev("@");//२
        data[0x69].copy_to_dev("#");//३
        data[0x6a].copy_to_dev("$");//४
        data[0x6b].copy_to_dev("%");//५
        data[0x6c].copy_to_dev("^");//६
        data[0x6d].copy_to_dev("&");//७
        data[0x6e].copy_to_dev("*");//८
        data[0x6f].copy_to_dev("(");//९
        //from here on, i am including the pure complexes starting the index from 128
		data[0x80].copy_to_dev("If");//क्ष
        data[0x81].copy_to_dev("q");//त्र
		data[0x82].copy_to_dev("1");//ज्ञ
		data[0x83].copy_to_dev("§");//ट्ट
		data[0x84].copy_to_dev("¶");//ठ्ठ
		data[0x85].copy_to_dev("Q");//त्त
		data[0x86].copy_to_dev("2");//द्द
		data[0x87].copy_to_dev(">");//श्र
		data[0x88].copy_to_dev("Ë");//ङ्ग
		data[0x90].copy_to_dev("");//
		int i;
		for(int i=0;i<0x7f;i++)
		{
			if(data[i].return_Dev().length()==0)
			{
                  data[i].copy_to_dev(unicode_Generator(i));
			}
		}
		for(i=0x80;i<0x90;i++)
		{
			data[i]++;
			data[i]++;

		}
}
void Database::assign_HalfPreeti()
{

        //This list will include आधा अक्षर from क  to ह
        //For making the main programm less complex, I will send the letter with ् for those letters with no half preeti values.
        //eg ढ,ठ,ट etc
        //From this point...I can no more tollerate the broken supprot for devangari unicode that linux has....I will be doing the rest of coding
        //in windows......until i run into the problem of cmd not supporting the utf-8
        hdata[0x15].copy_to_dev("S");//क्‍
        hdata[0x16].copy_to_dev("V");//ख्‍
        hdata[0x17].copy_to_dev("U");//ग्‍
        hdata[0x18].copy_to_dev("£‍");//घ्‍
        hdata[0x19].copy_to_dev("ª\\");//ङ्‍
        hdata[0x1a].copy_to_dev("R");//च्‍
        hdata[0x1b].copy_to_dev("5\\");//छ्‍
        hdata[0x1c].copy_to_dev("H");//ज्‍
        hdata[0x1d].copy_to_dev("‰");//झ्‍
        hdata[0x1e].copy_to_dev("~");//ञ्‍
        hdata[0x1f].copy_to_dev("‍6\\");//ट्‍
        hdata[0x20].copy_to_dev("7\\");//ठ्‍
        hdata[0x21].copy_to_dev("8\\");//ड्‍
        hdata[0x22].copy_to_dev("9\\");//ढ्‍
        hdata[0x23].copy_to_dev("0");//ण्‍
        hdata[0x24].copy_to_dev("T");//त्‍
        hdata[0x25].copy_to_dev("Y");//थ्‍
        hdata[0x26].copy_to_dev("b\\");//द्‍
        hdata[0x27].copy_to_dev("W");//ध्‍
        hdata[0x28].copy_to_dev("G");//न्‍
        hdata[0x2a].copy_to_dev("K");//प्‍
        hdata[0x2b].copy_to_dev("ˆ");//फ्
        hdata[0x2c].copy_to_dev("A");//ब्‍
        hdata[0x2d].copy_to_dev("E");//भ्‍
        hdata[0x2e].copy_to_dev("D");//म्‍
        hdata[0x2f].copy_to_dev("o\\");//य्‍   ...is there half य in Nepali language?..there aien't none in Preeti
        hdata[0x30].copy_to_dev("{");//half र  needs to be handled differently in the main program.....the complexity of Nepali language
        hdata[0x32].copy_to_dev("N");//ल्‍
        hdata[0x35].copy_to_dev("J");//व्‍
        hdata[0x36].copy_to_dev("Z");//श्‍
        hdata[0x37].copy_to_dev("i");//ष्‍
        hdata[0x38].copy_to_dev(":");//स्‍
        hdata[0x39].copy_to_dev("X");//ह्‍
        /*The half preeti is equivalent to two unicode characters..(zero width joiner:handle in main program)*/
        hdata[0x80].copy_to_dev("I‌");//क्ष्‍
        hdata[0x81].copy_to_dev("q\\");//त्र्‍
		hdata[0x82].copy_to_dev("1\\");//ज्ञ्‍
		hdata[0x83].copy_to_dev("§\\‌");//ट्ट्‍‍
		hdata[0x84].copy_to_dev("¶‌\\");//ठ्ठ्‍
		hdata[0x85].copy_to_dev("Q\\‍");//त्त्‍
		hdata[0x86].copy_to_dev("2\\");//द्द्‍
		hdata[0x87].copy_to_dev(">\\");//श्र्‍
		for(int i=0;i<0x7f;i++)
		{
			if(data[i].return_Dev().length()==0)
			{
                  data[i].copy_to_dev(unicode_Generator(i)+"्");
			}
		}
        for(int i=0;i<128;i++)
        {

            hdata[i]++;
        }
        for(int i=0x80;i<0x90;i++)
		{
			hdata[i]++;
			hdata[i]++;
			hdata[i]++;
		}
}
void Database::assign_OtherPreeti()
{
		///all the exceptions which are unique
		otherdata[0].copy_to_dev("<");//?
		otherdata[1].copy_to_dev("|");//
		otherdata[1]++;
		otherdata[2].copy_to_dev("¥");
		otherdata[2]++;
		otherdata[2]++;
		otherdata[3].copy_to_dev("?");
		otherdata[3]++;
		otherdata[4].copy_to_dev("¿");
		otherdata[4]++;
		otherdata[5].copy_to_dev("-");//(
		otherdata[6].copy_to_dev("_");//)

}
Compare Database::return_Index(std::string subject)
{
	Compare c;
	for(int i=0;i<=256;i++)
	{
		if(data[i].return_Dev()==subject)
		{
			c.type=1;
			c.value=i;
			return c;
		}
		else if(hdata[i].return_Dev()==subject)
		{
			c.type=2;
			c.value=i;
			return c;
		}
	}
	for(int i=0;i<=6;i++)
	{
		if(otherdata[i].return_Dev()==subject)
		{
			c.type=3;
			c.value=i;
			return c;
		}
	}
	c.type=1;
	c.value=EXCEPTION;
	return c;

}
#endif
