#ifndef OBJECT_HH_
  #define OBJECT_HH_

#include <type.hh>

class object_type;
class object_str;

class object{
public:
  virtual ~object ( );

  virtual object_type type ( ) const = 0;

  virtual object_str str ( ) const = 0;
};

#endif
