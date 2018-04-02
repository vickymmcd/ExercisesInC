/* Program to count word frequencies using Glib.

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

// function to print the hash table entries
void print_hash(gpointer key, gpointer value, gpointer user_data){
    char *pkey = key;
    printf("%s: %i\n", pkey, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {

  // open up the file and get the file descriptor
  FILE *ptr_file;
  ptr_file = fopen("words.txt", "r");
  gint file_descriptor = fileno(ptr_file);
  // create a gscanner to read the file
  GScanner *gs = g_scanner_new(NULL);
  // make a ghashtable for the word frequency table
  GHashTable *ght = g_hash_table_new(g_str_hash, g_str_equal);

  // set up the scanner input file
  g_scanner_input_file(gs, file_descriptor);
  // read words until the end of the file
  while(g_scanner_eof(gs) == FALSE){
    // add the key/value to the hash table each time you scan a new word
    g_scanner_get_next_token(gs);
    if(gs->value.v_string == NULL)
      continue;
    if(g_hash_table_lookup(ght, gs->value.v_string) == NULL){
      g_hash_table_insert(ght, g_strdup(gs->value.v_string), GINT_TO_POINTER(1));
    }
    else{
      g_hash_table_insert(ght, g_strdup(gs->value.v_string), g_hash_table_lookup(ght, gs->value.v_string)+1);
    }
  }

  // print out the values in the hash table
  g_hash_table_foreach(ght, print_hash, NULL);

  return 0;
}
