#include <stdio.h>
#include <stdlib.h>
#include "rand64-sw.h"

static FILE *urandstream;

/* Initialize the software rand64 implementation.  */
void
software_rand64_init (void)
{
  urandstream = fopen (srcfile, "r");
  if (! urandstream)
    abort ();
}

/* Return a random value, using software operations.  */
unsigned long long
software_rand64 (void)
{
  unsigned long long int x;
  if (fread (&x, sizeof x, 1, urandstream) != 1)
    abort ();
  return x;
}
void
software_rand64_fini (void)
{
  fclose (urandstream);
}
