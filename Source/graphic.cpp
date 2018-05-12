#include "graphic.h"
int main(int argc,char *argv[])
{
        gtk_init(&argc,&argv); //initializing the two arguments

        GtkWidget *menubar,*homemenu,*home,*refresh,*exit;  //for home menu
        GtkWidget *skin,*skin1,*skin2,*skin3,*settingmenu,*normal_skin,*custom_skin; //for setting menu
        GtkWidget *helpmenu,*help,*help1,*about;  //for help menu
        // GtkWidget *box,*box1,*box2,*box3,*box
        GtkWidget *box,*choose_unicode_file_button;
        GtkWidget *box1,*button2,*scroll,*scroll1;
        GtkWidget *box2,*button3,*button4;
        GtkWidget *box3,*button5,*button_convert_to_preeti,*box4;
        GtkWidget *box5,*button_close,*box6,*box7,*button8;
        GtkWidget *view,*view1;
        PangoFontDescription *font_desc;
        GtkTextIter iter,start,end;
        GtkWidget *layoutmenu,*layout,*unicode_layout,*preeti_layout;

                    //widgets for labels
        GtkWidget *label_welcome,*label_file_convert,*label_file_unicode_to_preeti;
        GtkWidget *label_file_preeti_to_unicode,*label_text_convert,*label_unicode;
        GtkWidget *label_preeti,*no_name_label1,*no_name_label,*label_output_folder;





        //creating window
        main_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_default_size(GTK_WINDOW(main_window),800,550);
        gtk_window_set_position(GTK_WINDOW(main_window),GTK_WIN_POS_CENTER);
        gtk_container_set_border_width(GTK_CONTAINER(main_window),20);
        gtk_window_set_title(GTK_WINDOW(main_window),"Nepali Conversion Tool");

        g_signal_connect(main_window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);


        box=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);        //creating vertical box


    //creating menusbar for home



	menubar=gtk_menu_bar_new();
	homemenu=gtk_menu_new();
	home=gtk_menu_item_new_with_label("Home");
	refresh=gtk_menu_item_new_with_label("Refresh");
	exit=gtk_menu_item_new_with_label("Exit");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(home),homemenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(homemenu),refresh);
	gtk_menu_shell_append(GTK_MENU_SHELL(homemenu),exit);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar),home);

	//setting menu

	settingmenu=gtk_menu_new();
	skin=gtk_menu_item_new_with_label("Background");
	skin1=gtk_menu_item_new_with_label("Skin1");
	skin2=gtk_menu_item_new_with_label("Skin2");
	skin3=gtk_menu_item_new_with_label("Skin3");
	custom_skin=gtk_menu_item_new_with_label("Custom Skin");
	normal_skin=gtk_menu_item_new_with_label("Default Skin");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(skin),settingmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(settingmenu),skin1);
	gtk_menu_shell_append(GTK_MENU_SHELL(settingmenu),skin2);
	gtk_menu_shell_append(GTK_MENU_SHELL(settingmenu),skin3);
	gtk_menu_shell_append(GTK_MENU_SHELL(settingmenu),custom_skin);
	gtk_menu_shell_append(GTK_MENU_SHELL(settingmenu),normal_skin);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar),skin);




	//creating menusbar for keyboard layouts

	layoutmenu=gtk_menu_new();
	layout=gtk_menu_item_new_with_label("Layout");
	unicode_layout=gtk_menu_item_new_with_label("Unicode Layout");
	preeti_layout=gtk_menu_item_new_with_label("preeti Layout");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(layout),layoutmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(layoutmenu),unicode_layout);
	gtk_menu_shell_append(GTK_MENU_SHELL(layoutmenu),preeti_layout);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar),layout);

	//creating menusbar for help

	helpmenu=gtk_menu_new();
	help=gtk_menu_item_new_with_label("Help");
	help1=gtk_menu_item_new_with_label("Help");
	about=gtk_menu_item_new_with_label("About");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help),helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu),help1);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu),about);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar),help);


	gtk_box_pack_start(GTK_BOX(box),menubar,FALSE,FALSE,0);





	label_welcome=gtk_label_new("WELCOME!!!   Nepali Conversion Tool\n\n");
	gtk_widget_set_size_request(label_welcome,30,10);
	gtk_misc_set_alignment (GTK_MISC (label_welcome),0.5, 1);   //for making an allignment
	gtk_box_pack_start(GTK_BOX(box),label_welcome,FALSE,FALSE,0);

	label_file_convert=gtk_label_new("File Convert\n");
	gtk_widget_set_size_request(label_file_convert,30,10);
	gtk_misc_set_alignment (GTK_MISC (label_file_convert),-1, 1);   //for making an allignment
	gtk_box_pack_start(GTK_BOX(box),label_file_convert,FALSE,FALSE,0);

	//box1 and box2 for the file convert

	box1=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,30);
	gtk_container_add(GTK_CONTAINER(box),box1);

	label_file_unicode_to_preeti=gtk_label_new("1.Unicode to Preeti\t\t");
	gtk_misc_set_alignment (GTK_MISC (label_file_unicode_to_preeti),0.01, 0.001);   //for making an allignment
	gtk_box_pack_start(GTK_BOX(box1),label_file_unicode_to_preeti,FALSE,FALSE,0);


	//label9=gtk_label_new("choose unicode file:");
	//gtk_box_pack_start(GTK_BOX(box1),label9,FALSE,FALSE,0);


	choose_unicode_file_button=gtk_label_new("Choose Unicode File\t\t");
    picker1 = gtk_file_chooser_button_new ("Pick a File",GTK_FILE_CHOOSER_ACTION_OPEN);
	gtk_container_add(GTK_CONTAINER(picker1),choose_unicode_file_button);
	gtk_box_pack_start(GTK_BOX(box1),picker1,20,10,0);


	button2=gtk_button_new_with_label("  Convert\t");
	g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(clicked8),NULL);	//for the preeti to unicode
	gtk_box_pack_end(GTK_BOX(box1),button2,0,0,2);

	//box2
	box2=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,30);
	gtk_container_add(GTK_CONTAINER(box),box2);

	label_file_preeti_to_unicode=gtk_label_new("2.Preeti to Unicode\t\t");
	//gtk_misc_set_alignment (GTK_MISC (label_file_preeti_to_unicode),0.01, 0.001);   //for making an allignment
	gtk_box_pack_start(GTK_BOX(box2),label_file_preeti_to_unicode,FALSE,FALSE,0);


	button3=gtk_button_new_with_label("Choose Preeti File");
	picker2 = gtk_file_chooser_button_new ("Pick a File",GTK_FILE_CHOOSER_ACTION_OPEN);
	gtk_container_add(GTK_CONTAINER(picker2),button3);
	gtk_box_pack_start(GTK_BOX(box2),picker2,30,30,0);

	button4=gtk_button_new_with_label("  Convert\t");
	g_signal_connect(G_OBJECT(button4),"clicked",G_CALLBACK(clicked9),NULL);	//for the preeti to unicode
	gtk_box_pack_end(GTK_BOX(box2),button4,0,0,2);

	//box3
	box3=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_container_add(GTK_CONTAINER(box),box3);

	label_output_folder=gtk_label_new("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Select Destination Folder: ");
	gtk_box_pack_start(GTK_BOX(box3),label_output_folder,0,0,0);

    button5=gtk_button_new_with_label("Output Folder");
	picker3 = gtk_file_chooser_button_new ("Pick a File",GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	gtk_container_add(GTK_CONTAINER(picker3),button5);
	gtk_box_pack_end(GTK_BOX(box3),picker3,50,100,0);






	label_text_convert=gtk_label_new("\n\n\tTEXT CONVERT\n\n");
	gtk_misc_set_alignment (GTK_MISC (label_text_convert),-1,1);   //for making an allignment
	gtk_widget_set_size_request(label_text_convert,30,10);
	gtk_box_pack_start(GTK_BOX(box),label_text_convert,FALSE,FALSE,0);

	//box4
	box4=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_container_add(GTK_CONTAINER(box),box4);

	label_unicode=gtk_label_new("\tUnicode");
	gtk_box_pack_start(GTK_BOX(box4),label_unicode,FALSE,FALSE,0);

	label_preeti=gtk_label_new("Preeti\t");
	gtk_box_pack_end(GTK_BOX(box4),label_preeti,FALSE,FALSE,0);

	//box5
	box5=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,75);
	gtk_container_add(GTK_CONTAINER(box),box5);

	//for text view at the left
	scroll=gtk_scrolled_window_new(0,0);
	gtk_widget_set_size_request(scroll,100,250);
	view=gtk_text_view_new();
	gtk_container_set_border_width(GTK_CONTAINER(view),5);
	buffer1=gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	gtk_text_buffer_get_iter_at_offset(buffer1, &iter,0);
    font_desc = pango_font_description_from_string ("jpt_font 12");
	gtk_widget_override_font (view, font_desc);
	pango_font_description_free (font_desc);
	gtk_text_buffer_insert(buffer1,&iter,"युनिकोड",-1);
	gtk_container_add(GTK_CONTAINER(scroll),view);
	gtk_box_pack_start(GTK_BOX(box5),scroll,TRUE,TRUE,5);

    //for text view at the right
	scroll1=gtk_scrolled_window_new(0,0);
	gtk_widget_set_size_request(scroll1,100,250);
	view1=gtk_text_view_new();
	gtk_container_set_border_width(GTK_CONTAINER(view1),5);
	buffer2=gtk_text_view_get_buffer(GTK_TEXT_VIEW(view1));
	gtk_text_buffer_get_iter_at_offset(buffer2, &iter,0);
	gtk_text_buffer_insert(buffer2,&iter,"lk|tL",-1);
	font_desc = pango_font_description_from_string ("Preeti 15");
	gtk_widget_override_font (view1, font_desc);
	pango_font_description_free (font_desc);
	gtk_container_add(GTK_CONTAINER(scroll1),view1);
	gtk_box_pack_end(GTK_BOX(box5),scroll1,TRUE,TRUE,5);
    gtk_widget_set_vexpand(box5,TRUE);



	//box6
	box6=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	gtk_container_add(GTK_CONTAINER(box),box6);


	button_convert_to_preeti=gtk_button_new_with_label("\tConvert to Preeti \t");
	gtk_box_pack_start(GTK_BOX(box6),button_convert_to_preeti,FALSE,FALSE,0);
	g_signal_connect(G_OBJECT(button_convert_to_preeti),"clicked",G_CALLBACK(clicked),NULL);


	button8=gtk_button_new_with_label("\tConvert to Unicode \t");
	gtk_box_pack_end(GTK_BOX(box6),button8,FALSE,FALSE,0);
	g_signal_connect(G_OBJECT(button8),"clicked",G_CALLBACK(clicked1),NULL);


	//box7
	box7=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    button_close=gtk_button_new_with_label("\tClose\t");
    gtk_box_pack_end(GTK_BOX(box7),button_close,FALSE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(box),box7);




	g_signal_connect(button_close,"clicked",G_CALLBACK(gtk_main_quit),main_window);
	g_signal_connect(G_OBJECT(skin1),"activate",G_CALLBACK(activate4),NULL);
	g_signal_connect(G_OBJECT(skin2),"activate",G_CALLBACK(activate5),NULL);
	g_signal_connect(G_OBJECT(skin3),"activate",G_CALLBACK(activate6),NULL);
	g_signal_connect(G_OBJECT(custom_skin),"activate",G_CALLBACK(Custom_Skin_Activate),NULL);
	g_signal_connect(G_OBJECT(normal_skin),"activate",G_CALLBACK(activate7),NULL);
	g_signal_connect(G_OBJECT(exit),"activate",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(G_OBJECT(refresh),"activate",G_CALLBACK(activate),NULL);
	g_signal_connect(G_OBJECT(help1),"activate",G_CALLBACK(activate1),NULL);
	g_signal_connect(G_OBJECT(about),"activate",G_CALLBACK(activate2),NULL);
	g_signal_connect(G_OBJECT(unicode_layout),"activate",G_CALLBACK(activate8),NULL);
	g_signal_connect(G_OBJECT(preeti_layout),"activate",G_CALLBACK(activate9),NULL);



	gtk_container_add(GTK_CONTAINER(main_window),box);
	//making all widgets visible
	gtk_widget_show_all(main_window);
	gtk_main(); //running main loop
	return 0;
}
