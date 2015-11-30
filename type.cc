#include <string>

#include <type.hh>

using std :: string;

string private_type_string ( const enum private_type type ){
  switch(type){
  case private_type :: private_type_str:{
    return "str";
    break;
  }
  case private_type :: private_type_type:{
    return "type";
    break;
  }
  }
}
