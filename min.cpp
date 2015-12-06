#include <iostream>
#include <limits>

#include <object_int.hh>

using std :: cout;

using std :: numeric_limits;

int main ( ){
  cout << numeric_limits<decltype ( object_int :: int_ )>:: min ( ) << '\n';
}
