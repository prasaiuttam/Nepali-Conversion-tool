#ifndef GRAPHIC1_H
#define GRAPHIC_H
#include<gtk/gtk.h>
#include<iostream>
#include"FiletoFile.h"
#include "filetofile2.h"
#include "errordisplay.h"
#include<string.h>
using namespace std;
GtkWidget *main_window;
GtkTextBuffer *buffer1,*buffer2;
GtkWidget *picker1,*picker2,*picker3;
struct Sliders
{
	GtkWidget *box,*label,*h_slider;
};
Sliders slider[4];//Four Sliders are Required for Costumization
static gboolean activate(GtkWidget*refresh,GdkEvent*event,gpointer data) // for clearing the text buffer
{
	clear_TextBuffer("Preeti");
	clear_TextBuffer("Unicode");
	/*
	 *No Need For the Conditions
	*/
}

static gboolean activate8(GtkWidget*homepage,GdkEvent*event,gpointer data)  //another one unicode layout
{
	image_Layout("Unicode Layout","unicode.png",999,580);
}
static gboolean activate9(GtkWidget*homepage,GdkEvent*event,gpointer data)  //another one for preeti layout
{
    image_Layout("Preeti Layout","preeti.png",1230,500);
}
static gboolean activate1(GtkWidget*help,GdkEvent*event,gpointer data) //another callback for help
{
	display_Message("Help","If any feedbacks regarding this software,\nplease email us at\n\t WWW.subash.com\nOR goto our facebook page\n\thttps://www.facebook.com/NepaliConversionTool\n\t\t\t\tThank YOU!",300,200);
}

static gboolean activate2(GtkWidget*about,GdkEvent*event,gpointer data)  //another one for about
{

	GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window,410,400);
	gtk_window_set_title(GTK_WINDOW(window),"About");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);

	layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);


    image = gtk_image_new_from_file("gtk.png");
    gtk_layout_put(GTK_LAYOUT(layout), image,100,0);
    GtkWidget*about_label=gtk_label_new("\tNepali Conversion Tool\n\tVersion:1.1\n\n\tNCT is utility software designed to convert Nepali Unicode to\n\tPreeti and vice-versa.\n\t\t\t\t\tDevelopers:\n\t\t\t\t\tPrashant Subedi\n\t\t\t\t\tPratibha Shrestha\n\t\t\t\t\tUttam Prasai\n\t\t\t\t\tAnkita Sharma\n\t\t\t\t\tPratibha Shrestha\n\t\t\t\t\tSubash Sapkota\n\tUnder the supervision of Mr.Santosh Khanal For partial\n\tfulfillment of First year project");
    gtk_layout_put(GTK_LAYOUT(layout), about_label,0,150);

    gtk_widget_show_all(window);


}

static gboolean clicked8(GtkWidget*button4,GdkEvent*event,gpointer data)  //another one for Preeti to uni
{
	char *raw_filename;
	raw_filename=gtk_file_chooser_get_uri((GtkFileChooser*)picker1);
	if (raw_filename==NULL)//To avoid segmentation fault
	{
		 display_Message("ERROR!!!","Please Select A DOCX File First!",300,200);//Subash, this is how you make the code less redundant
	}
	else
	{
		char *folder_name=gtk_file_chooser_get_uri((GtkFileChooser*)picker3);
		if(folder_name==NULL)
		{
			display_Message("ERROR!!!","Please Select The Directory",300,200);
		}
		else
		{
			std::string formated_string=format_Name(raw_filename);
			std::string formated_folder=format_Name(folder_name);
			convert_File_Unicode(formated_string,formated_folder);
		}
	}
}
static gboolean clicked9(GtkWidget *button4,GdkEvent*event,gpointer data)  //another one for uni to Preeti
{
	char *raw_filename;
	raw_filename=gtk_file_chooser_get_uri((GtkFileChooser*)picker2);
	if (raw_filename==NULL)//To avoid segmentation fault
	{
		 display_Message("ERROR!!!","Please Select A DOCX File First!",300,200);//Subash, this is how you make the code less redundant
	}
	else
	{
		char *folder_name=gtk_file_chooser_get_uri((GtkFileChooser*)picker3);
		if(folder_name==NULL)
		{
			display_Message("ERROR!!!","Please Select The Directory",300,200);
		}
		else
		{
			std::string formated_string=format_Name(raw_filename);
			std::string formated_folder=format_Name(folder_name);
			convert_file_Preeti(formated_string,formated_folder);
		}
	}

}
static gboolean activate4(GtkWidget*skin,GdkEvent*event,gpointer data)  //another one skin1
{
	change_BackgroundColor(0.07,0.14,0.67,1.0);
}
static gboolean activate5(GtkWidget*skin2,GdkEvent*event,gpointer data)  //another one skin2
{
	change_BackgroundColor(0.3,0.5,0.6,0.8);
}
static gboolean activate6(GtkWidget*skin3,GdkEvent*event,gpointer data)  //another one skin3
{
	change_BackgroundColor(0.7,0.8,0.6,0.6);
}
static gboolean Apply_Background(GtkWidget *apply_costum_settings,GdkEvent*event,gpointer *data)  //For applying Costum Skin
{
	float f[4];
	for(int i=0;i<4;i++)
	{
		f[i]=gtk_range_get_value((GtkRange *)slider[i].h_slider);
	}
	change_BackgroundColor(f[0],f[1],f[2],f[3]);

}
static gboolean Custom_Skin_Activate(GtkWidget *custom_skin,GdkEvent*event,gpointer data)  //another one skin3
{
	GtkWidget *window,*custom_skin_box,*apply_costum_settings;//For the main box
	//For the Main Window of the Costum Skin Widget
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window,300,200);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window),20);
	gtk_window_set_title(GTK_WINDOW(window),"Custom Skin Widget");

	//Creating the Main box which will be added to Main Window
	custom_skin_box=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);

	char *a[]={"Red    ","Green  ","Blue    ","Alpha   "};//Four Colors
	//For four sliders
	for(int i=0;i<4;i++)
	{
        slider[i].box=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);//Creating The Box For Slider
        slider[i].label=gtk_label_new(a[i]);//Creating Label
        gtk_box_pack_start(GTK_BOX(slider[i].box),slider[i].label,FALSE,FALSE,0);
		slider[i].h_slider=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL,0,1,0.01);//Creating Slider
		gtk_container_add(GTK_CONTAINER(slider[i].box),slider[i].h_slider);//Adding Slider to the box
		gtk_container_add(GTK_CONTAINER(custom_skin_box),slider[i].box);//Adding box to Main box
	}
	//For setting the current position
	gtk_range_set_value((GtkRange *)slider[0].h_slider,color.red);
	gtk_range_set_value((GtkRange *)slider[1].h_slider,color.green);
	gtk_range_set_value((GtkRange *)slider[2].h_slider,color.blue);
	gtk_range_set_value((GtkRange *)slider[3].h_slider,color.alpha);

	//For Apply bottom
	apply_costum_settings=gtk_button_new_with_label("Apply");
	gtk_box_pack_start(GTK_BOX(custom_skin_box),apply_costum_settings,0,0,2);
	g_signal_connect(G_OBJECT(apply_costum_settings),"clicked",G_CALLBACK(Apply_Background),NULL);//Passing The Array
	//Adding the custom_skin_box to the Widget
	gtk_container_add(GTK_CONTAINER(window),custom_skin_box);
	gtk_widget_show_all(window);

}
static gboolean activate7(GtkWidget*normal_skin,GdkEvent*event,gpointer data)  //another one normal_skin
{
	gtk_widget_override_background_color(main_window,GTK_STATE_FLAG_NORMAL,NULL);
}

static gboolean clicked(GtkWidget*button7,GdkEvent*event,gpointer data)  //  converting unicode to Preeti direct
{
	extract_and_load_Buffer("Unicode2Preeti");
}

static gboolean clicked1(GtkWidget*button8,GdkEvent*event,gpointer data) // for PREETI to unicode direct
{
	extract_and_load_Buffer("Preeti2Unicode");

}
#endif //GRAPHIC_H
