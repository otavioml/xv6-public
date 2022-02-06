#include "types.h"
#include "user.h"
#include "date.h"

int stdout = 1;
int stderr = 2;

int
main(int argc, char *argv[])
{

  float x = 0.0;
  float pi = 3.141573;

  for (int i = 0; i < 10; i++){
    sleep(1);
  }

  for (int i = 0; i < 99999; i++){
    for (int j = 0; j < 9999; j++){
      x += pi*pi;
    }
  }

  printf(stdout, "%f\n", x);

  exit();
}