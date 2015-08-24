#include <stdlib.h>
#include "dbg.h"

int main(int argc, char* argv[]) {
   char c = 5;
   check(argc == 2, error, "argc = %d and not 2", argc);
   
   printf("never executed due to the error");

   return 0;

error:
   var_val(c, "%d");
   printbits(c, sizeof(char));
   debug("c might be equal to 5");
   check(argc == 1, whatever, "Will not be printed");
whatever:
   return -1;
}
