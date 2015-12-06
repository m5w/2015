#ifndef OBJECT_HH_
  #define OBJECT_HH_

#include <ostream>

using std :: ostream;

class object{
public:
  friend ostream& operator<< ( ostream& a,const object& b );

  friend bool operator< ( const object& a,const object& b );

  virtual ~object ( ) = default;
protected:
  virtual ostream& print ( ostream& a ) const = 0;

  virtual bool lt ( const object& b ) const = 0;
};

#endif
