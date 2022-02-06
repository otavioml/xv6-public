#include "types.h"
#include "user.h"
#include "date.h"

int stdout = 1;
int stderr = 2;
float x;

int
main(int argc, char *argv[])
{

  x = 0.0;
  float pi = 3.141573;

  for (int i = 0; i < 99999; i++){
    for (int j = 0; j < 10000; j++){
      x += pi*pi;
    }
  }

  exit();
}