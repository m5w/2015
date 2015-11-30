#ifndef TYPE_HH_
  #define TYPE_HH_

#include <string>

using std :: string;

enum class TYPE{
  type,
  str,
};

string str ( const enum TYPE type );

#endif
