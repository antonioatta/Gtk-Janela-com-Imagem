#include  <gtk/gtk.h>

/* Rotina disparada quando o evento "fechar janela principal" ocorre */
void  on_window_closed (GtkWidget  *Widget ,  gpointer  dados)
{
  gtk_main_quit  ();
}

int  main(int argc, char *argv [])
{
  GtkBuilder *builder;
	GtkWidget  *janela;
  GtkWidget  *image;
  GtkWidget  *image_box;


  /* Inicializar sistema GUI */
  gtk_init(& argc, &argv );

	builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "sisbib_entrada.ui", NULL);

	/* Acessar o widget "Janela" a partir do Builder */
  janela = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_Janela_Principal"));

	/* Associar a rotina de fechar a janela ao evento "fechar a janela" */
  g_signal_connect(janela ,  "destroy" ,  G_CALLBACK(on_window_closed),  NULL );

  /* Acessar o widget "Imagem" a partir do Builder */
  image_box = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_Ctnr_SisBib_Imagem1"));
  image = gtk_image_new_from_file ("logo_livros.png");
  gtk_container_add (GTK_CONTAINER (image_box), image);

	/* Exibir os widgets "janela" e todos os seus widgets internos  */
  gtk_widget_show_all(janela);

	/* Ciclo principal de eventos */
  gtk_main();

  return(0);
}
