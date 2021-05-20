#include <immintrin.h>
#include <time.h>
#include <stdio.h>

#include "mrand48_r.h"
void mrand48_rng_init()
{
  
}
unsigned long long mrand48_rng()
{
  srand48_r(time(NULL), &buf);
  long int a;
  mrand48_r(&buf, &a);
  return (unsigned long long) a;
  
    
}
void mrand48_rng_fini()
{

}
