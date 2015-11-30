#include <string>

#include <object_type.hh>
#include <object_str.hh>
#include <type.hh>

using std :: string;

bool operator== ( const object_str& a,const object_str& b ){
  return a . str_ == b . str_;
}

object_str :: object_str ( const string str ):str_(str){
}

object_type object_str :: type ( ) const{
  return TYPE :: str;
}

object_str object_str :: str ( ) const{
  return * this;
}
