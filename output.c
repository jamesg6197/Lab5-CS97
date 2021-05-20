#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <cpuid.h>
#include "output.h"
bool
writebytes (unsigned long long x, int nbytes)
{
  do
    {
      if (putchar (x) < 0)
        return false;
      x >>= CHAR_BIT;
      nbytes--;
    }
  while (0 < nbytes);

  return true;
}
void writeblocks (unsigned int blocksize, long long nbytes, unsigned long long (*rand64)(void))
{
  unsigned int currentArrayIndex = 0;
  unsigned int totalWritten = 0;
  unsigned int outbytes = nbytes < blocksize ? nbytes : blocksize;
  char* buffer = malloc(outbytes);
  while (totalWritten < nbytes)
    {
      unsigned long long x = rand64();
      if (totalWritten + blocksize > nbytes)
	{
	  blocksize = nbytes - totalWritten;
	}
      while (x > 0 && currentArrayIndex < blocksize)
	{
	  memcpy(buffer + currentArrayIndex, &x, 1);
	      currentArrayIndex++;
	    x >>= CHAR_BIT;
	}
      if (currentArrayIndex == blocksize)
	{
	  int bytesWritten = write(1, buffer, nbytes);
	    totalWritten += bytesWritten;
	    currentArrayIndex = 0;
	}
    }

}
