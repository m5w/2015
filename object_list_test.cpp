#include <iostream>

#include <object_int.hh>
#include <object_list.hh>

using std :: cout;

int main ( ){
  object_list L;
  L . append ( object_int ( 2 ) );
  L . append ( object_int ( 3 ) );
  object_list M;
  M . append ( object_int ( 5 ) );
  M . append ( L );
  cout << M << '\n';
}
