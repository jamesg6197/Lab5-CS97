enum Input { RDRAND, SLASHF, MRAND};
enum Output { STDIO, WRITEN};

struct options
{
  long long nbytes;
  enum Input input;
  enum Output output;
  char* srcfile;
  bool valid;
  unsigned int blockSize;
};
void checkinput(int argc, char** argv, struct options* opts);
