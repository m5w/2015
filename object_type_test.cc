#include <string>

#include <object_type.hh>
#include <object_str.hh>
#include <type.hh>

using std :: string;

bool object_type_type ( );

bool object_type_str ( );

int main ( ){
  if(! object_type_type ( )){
    return 1;
  }

  if(! object_type_str ( )){
    return 1;
  }
}

bool object_type_type ( ){
  object_type unit(private_type :: private_type_type);
  return unit . type ( ) == private_type :: private_type_type;
}

bool object_type_str ( ){
  object_type unit(private_type :: private_type_type);
  return unit . str ( ) == string("<type 'type'>");
}
