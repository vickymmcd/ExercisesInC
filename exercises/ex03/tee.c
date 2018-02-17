#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int i;
  char ch;
  int append = 0;
  char input[256];
  FILE *output_file;

  while((ch = getopt(argc, argv, "aip")) != EOF){
    switch(ch){
      case 'a':
        append = 1;
        break;
      case 'i':
        break;
      case 'p':
        break;
    }
  }
  argc -= optind;
  argv += optind;

  if(argc < 1){
    fprintf(stderr, "Please specify at least one ouptut file\n");
    return(1);
    exit(1);
  }

  while(fgets(input, 256, stdin)){
    for(i=0; i<argc; i++){
      if(!append){
        output_file = fopen(argv[i], "w");
        append = 1;
      }
      else{
        output_file = fopen(argv[i], "a");
      }
      fprintf(stdout, "%s", input);
      fputs(input, output_file);

      fclose(output_file);
    }
  }

  return 0;
}
