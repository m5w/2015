#include <object_int.hh>

object_int :: object_int ( const long long int_ ):int_(int_){
}

bool object_int :: lt ( const object& b ) const{
  return int_ < dynamic_cast<const object_int&>( b ) . int_;
}
