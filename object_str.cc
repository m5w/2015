#include <iostream>
#include <string>

#include <object.hh>
#include <object_str.hh>
#include <object_type.hh>
#include <type.hh>

using std :: cout;

using std :: string;

bool operator== ( const object_str& a,const object_str& b ){
  return a . str_ == b . str_;
}

void print ( const object* a ){
  cout << a -> str ( ) . str_;
}

object_str :: object_str ( const string str ):str_(str){
}

object_type object_str :: type ( ) const{
  return private_type :: private_type_str;
}

object_str object_str :: str ( ) const{
  return * this;
}
