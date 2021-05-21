#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "options.h"
void checkinput(int argc, char** argv, struct options* opts )
{
  opts->valid = false;
  int opt;
  opts->srcfile = "/dev/random";
  while ((opt = getopt(argc, argv, "i:o:")) != -1)
  {
    switch(opt)
      {
      case 'i':
	if (!strcmp(optarg, "mrand48_r"))
	  {
	    opts->input = MRAND;
	    
	  }
	else if (!strcmp(optarg, "rdrand"))
	  {
	    opts->input = RDRAND;
	  }

	else if ('/' == optarg[0])
	  {
	    opts->input = SLASHF;
	    opts->srcfile = optarg;
          }
	else
	  {
	    fprintf(stderr, "Error: Invalid Argument");
	    exit(1);
	  }
	opts->valid = true;
	break;
      case 'o':
	if (!strcmp(optarg, "stdio"))
	  {
	    opts->output = STDIO;
	  }
	else 
	  { 
	    opts->output = WRITEN;
	    opts->blockSize = atoi(optarg);
	    if (atoi(optarg) <= 0)
	    {
	      fprintf(stderr, "Byte number must be positive");
	      exit(1);
	    }
	  }
	opts->valid = true;
	break;
      case '?':
	fprintf(stderr, "Improper input of arguments and options");
	exit(1);
      }

    }
  if (optind >= argc)
        return;
  opts->nbytes = atol(argv[optind]);
   if (opts->nbytes >= 0)
       opts->valid = true;
    
}
