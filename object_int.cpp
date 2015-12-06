#include <ostream>

#include <object_int.hh>

using std :: ostream;

object_int :: object_int ( const long long int_ ):int_(int_){
}

ostream& object_int :: print ( ostream& a ) const{
  a << int_;
  return a;
}

bool object_int :: lt ( const object& b ) const{
  return int_ < dynamic_cast<const object_int&>( b ) . int_;
}
