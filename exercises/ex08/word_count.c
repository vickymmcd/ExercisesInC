/* Program to count word frequencies using Glib.

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


gchar* get_contents (void) {
    const gchar *filename = "prideandprejudice.txt";
    gchar *contents;
    gsize len;
    GError *error = NULL;

    if (! g_file_get_contents (filename, &contents, &len, &error))
        g_error ("g_file_get_contents() failed: %s", error->message);
    return contents;

}

void print_hash(gpointer key, gpointer value, gpointer user_data){
    char *pkey = key;
    printf("%s - %i\n", pkey, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {
  /*
  gchar* book = get_contents();
  //gchar** words = g_strsplit(" ", book, -1);
  gchar** words = g_strsplit(" ", "hello I am Vicky who are you", -1);
  //GArray* a = g_array_new(FALSE, FALSE, sizeof(char*));
  int count = 0;
  int i;
  FILE *ptr_file;
  //printf("%ld", sizeof(words));
  printf("%s\n", words[0]);

  for(i=0; i<sizeof(words); i++){
    //printf("%s\n", words[i]);
  }
  */

  // open up the file and get the file descriptor
  FILE *ptr_file;
  ptr_file = fopen("prideandprejudice.txt", "r");
  gint file_descriptor = fileno(ptr_file);
  // create a gscanner to read the file
  GScanner *gs = g_scanner_new(NULL);
  // make a ghashtable for the word frequency table
  GHashTable *ght = g_hash_table_new(g_str_hash, g_str_equal);

  //open("prideandprejudice.txt", O_RDONLY);
  g_scanner_input_file(gs, file_descriptor);
  while(g_scanner_eof(gs) == FALSE){
    g_scanner_get_next_token(gs);
    if(gs->value.v_string == NULL)
      continue;
    if(g_hash_table_lookup(ght, gs->value.v_string) == NULL){
      g_hash_table_insert(ght, g_strdup(gs->value.v_string), GINT_TO_POINTER(1));
    }
    else{
      g_hash_table_insert(ght, g_strdup(gs->value.v_string), g_hash_table_lookup(ght, gs->value.v_string)+1);
    }
    printf("%s\n", gs->value.v_string);
  }

  g_hash_table_foreach(ght, print_hash, NULL);

  //printf("%s", book);
  //char buf[1000];

  //for(i=0; i<a->len; i++){
    //printf("%s", book);
    //printf("%s", g_array_index(a, char*, 0));
  //}
/*
  char **lines;
  lines = (char**)malloc(sizeof(char)*count);
  lines[0] = (char*)malloc(sizeof(char)*count*1000);
  int curcount = 0;

  printf("hello i made it here");

  while (fgets(lines[curcount],1000, ptr_file)!=NULL){
    curcount++;
  }

  printf("hiya...");

  for(i=0; i<count; i++){
    printf("%s", lines[i]);
    printf("%d", i);
  }

  printf("count %d\n", count);
*/
  //fclose(ptr_file);
  return 0;
}
