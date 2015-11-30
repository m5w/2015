#ifndef private_type_HH_
  #define private_type_HH_

#include <string>

using std :: string;

enum class private_type{
  private_type_type,
  private_type_str,
};

string private_type_string ( const enum private_type type );

#endif
