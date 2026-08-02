#include <unistd.h>
int  main(void)
{
  char *string = "I hate my life";
  int  i;

  i = 0;
  while(string[i] != '\0')
  {
      write(1, &string[i], 1);
      i++;
  }
}
