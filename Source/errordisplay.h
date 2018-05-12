#ifndef ERRORDISPLAY_H
#define ERRORDISPLAY_H
#include<gtk/gtk.h>
#include"unicode2preeti.h"
#include "preeti2unicode.h"
GdkRGBA color;//This has to made global for the customizability to occur

void display_Message(std::string title,std::string message,int res1,int res2)
{
	GtkWidget *window,*label;
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window,res1,res2);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_window_set_title(GTK_WINDOW(window),title.c_str());
	label=gtk_label_new(message.c_str());
	gtk_container_add(GTK_CONTAINER(window),label);
	gtk_widget_show_all(window);

}
std::string format_Name(std::string raw_name)
{
	raw_name.erase(0,7);
	//string_slicer=(raw_filename+7);
	//std::string temp=string_slicer;
	std::string filename="";
	std::string check_string;
	for(int i=0;i<(raw_name.length());i++)
	{
		if(i<(raw_name.length()-2))
		{
			check_string+=raw_name[i];
			check_string+=raw_name[i+1];
			check_string+=raw_name[i+2];
		}
		if(check_string=="%20")
		{
			filename+=" ";
			i+=2;
		}
		else
		{
			filename+=raw_name[i];
		}
			check_string="";
	}
	return filename;
}
void image_Layout(std::string name,std::string file,int res1,int res2)
{
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window,res1,res2);
	gtk_window_set_title(GTK_WINDOW(window),name.c_str());
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);


	layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);

    //gtk_widget_show(layout);

    image = gtk_image_new_from_file(file.c_str());
    gtk_layout_put(GTK_LAYOUT(layout), image,0,0);


    gtk_widget_show_all(window);
}
void change_BackgroundColor(float red,float green,float blue,float alpha)
{
	extern GtkWidget* main_window;//taking the global variable..not overriding

	color.red = red;
	color.green = green;
	color.blue = blue;
	color.alpha = alpha;
	gtk_widget_override_background_color(main_window,GTK_STATE_FLAG_NORMAL,&color);
}
void clear_TextBuffer(std::string box)
{
	GtkTextIter iter,start,end;
	extern GtkTextBuffer *buffer2;
	extern GtkTextBuffer *buffer1;
	GtkTextBuffer* buffer;
	if(box=="Unicode")
	{
		buffer=buffer1;
	}
	else if(box=="Preeti")
	{
		buffer=buffer2;
	}
	gtk_text_buffer_get_start_iter (buffer,&start);
	gtk_text_buffer_get_end_iter (buffer,&end);
	gtk_text_buffer_delete (buffer,&start,&end);

}
void extract_and_load_Buffer(std::string conversion_type)
{
	GtkTextIter iter,start,end;
    extern GtkTextBuffer *buffer1,*buffer2;
    GtkTextBuffer *extract_buffer,*load_buffer;
	if(conversion_type=="Unicode2Preeti")
	{
		clear_TextBuffer("Preeti");//Preparing the next buffer for display
		extract_buffer=buffer1;
		load_buffer=buffer2;

	}
	else if(conversion_type=="Preeti2Unicode")
	{
		clear_TextBuffer("Unicode");
		extract_buffer=buffer2;
		load_buffer=buffer1;
	}
	gtk_text_buffer_get_start_iter(extract_buffer,&start);
	gtk_text_buffer_get_end_iter(extract_buffer,&end);
	char *text;
	text=gtk_text_buffer_get_text(extract_buffer,&start,&end,FALSE);
	char *result;
	std::string converted;
	if(conversion_type=="Unicode2Preeti")
	{
		converted=unicode_Converter_Direct(text);
	}
	else if(conversion_type=="Preeti2Unicode")
	{
		converted=preeti_Converter(text);
	}
	result=new char[converted.length()+1];
	int i;
	for(i=0;i<converted.length();i++)
	{
		result[i]=converted[i];
	}
	result[i]='\0';
	/**
	*The above lines are to convert the string(object) into null terminating string(array of char)
	*Every time I use std::string::c_str(), it crashes the program...Hence I did the conversion manually
	*/
	text=result;
	//upto here...Now its Graphic' fault
	gtk_text_buffer_get_iter_at_offset(load_buffer, &iter,10);
	gtk_text_buffer_insert(load_buffer,&iter,text,-1);
	delete[] result;
	//And here is where it ends.
}


#endif//ERRORDISPLAY_H
