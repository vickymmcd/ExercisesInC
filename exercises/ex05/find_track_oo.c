/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


typedef struct {
    regex_t inner_struct[1];
} Regex;


/* Returns a new Regex that matches the given pattern.
*
* pattern: string regex
* flags: flags passed to regcomp
* returns: new Regex
*/
Regex *make_regex(char *pattern, int flags) {
    Regex *new = malloc(sizeof(Regex));
    int ret;
    ret = regcomp(new->inner_struct, pattern, flags);
    if (ret){
      fprintf(stderr, "Could not compile regex\n");
      exit(1);
    }
    return new;
}

/* Checks whether a regex matches a string.
*
* regex: Regex
* s: string
* returns: 1 if there's a match, 0 otherwise
*/
int regex_match(Regex *regex, char *s) {
    int ret;
    char msgbuf[100];
    ret = regexec(regex->inner_struct, s, 0, NULL, 0);
    if(!ret){
      return 1;
    }
    else if(ret==REG_NOMATCH){
    }
    else{
      regerror(ret, regex->inner_struct, msgbuf, sizeof(msgbuf));
    }
    return 0;
}

/* Frees a Regex.
*
* regex: Regex
*/
void regex_free(Regex *regex) {
    free(regex);
}


/* Finds all tracks that match the given pattern.
*
* Prints track number and title.
*/
void find_track_regex(char pattern[])
{
    int i;

    Regex *regex = make_regex(pattern, REG_EXTENDED | REG_NOSUB);

    for (i=0; i<NUM_TRACKS; i++) {
        if (regex_match(regex, tracks[i])) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }

    regex_free(regex);
}


int main (int argc, char *argv[])
{
    char *pattern = "F.*F.*";
    find_track_regex(pattern);

    return 0;
}
