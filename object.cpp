#include <ostream>

#include <object.hh>

using std :: ostream;

ostream& operator<< ( ostream& a,const object& b ){
  return b . print ( a );
}

bool operator< ( const object& a,const object& b ){
  return a . lt ( b );
}
