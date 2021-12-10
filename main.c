#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int contador=1;
  int rc = fork();

  if(rc < 0)
  {
    fprintf(stderr, "fork failed\n");
  }
  else
  {
    if(rc==0) //is the child
    {
      contador+=5;
      printf("Soy el hijo (pid:%d) y el valor de mi contador es: %i\n", getpid(), contador);
    }
    else //is the parent
    {
      contador+=2;
      printf("Soy el padre de %d (pid:%d) y el valor de mi contador es: %i\n", rc, getpid(), contador);
    }
  }
  printf("Al final antes del return del programa el contador imprime: %i", contador);
  return 0;
}