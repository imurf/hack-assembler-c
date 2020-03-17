
#include <stdio.h>
#include "symbollib.h"

int main(int argc, char* argv[]){
  struct SymLib* p_lib = NULL;
  int err;
  err = new_symbol_library(&p_lib);

  // add symbols to the library...
  printf("adding symbol: THAT:0x0b01\n");
  printf("adding symbol: that:0x0c71\n");
  printf("adding symbol: moonCat:0xdb25\n");

  add_symbol(p_lib, "THAT", 0x0b01);
  add_symbol(p_lib, "that", 0x0c71);
  add_symbol(p_lib, "moonCat", 0xdb25);

  // search the symbols in the library...
  printf("retrieving symbols from library...");
  uint16_t address = 0;

  search_symbol_library(p_lib, "THAT", &address);
  printf("symbol THAT address = %#04x\n", address);

  search_symbol_library(p_lib, "that", &address);
  printf("symbol that address = %#04x\n", address);

  search_symbol_library(p_lib, "moonCat", &address);
  printf("symbol moonCat address = %#04x\n", address);

  free_symbol_library(&p_lib);

  return 0;
}
