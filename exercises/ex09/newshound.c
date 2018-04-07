/* Example from Head First C.

Downloaded from https://github.com/twcamper/head-first-c

Modified by Allen Downey.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <wait.h>


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search phrase>\n", argv[0]);
        return 1;
    }
    const char *PYTHON = "/usr/bin/python2";
    const char *SCRIPT = "rssgossip.py";
    char *feeds[] = {
        "http://www.nytimes.com/services/xml/rss/nyt/Africa.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Americas.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/MiddleEast.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Europe.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/AsiaPacific.xml"
    };
    int num_feeds = 5;
    char *search_phrase = argv[1];
    char var[255];
    int child_status;

    int i;
    for (i=0; i<num_feeds; i++) {
        printf("hello from loop %d\n", i);
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};

        pid_t pid = fork();
        if(pid==-1){
          fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
          return 1;
        }

        if(!pid){
          int res = execle(PYTHON, PYTHON, SCRIPT, search_phrase, NULL, vars);
          if (res == -1) {
              fprintf(stderr, "Can't run script: %s\n", strerror(errno));
              return 1;
          }
        }
        else{
          pid_t ppid = wait(&child_status);
          while (pid != ppid){
            ppid = wait(&child_status);
          }
        }
    }
    return 0;
}
