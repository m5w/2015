#ifndef OBJECT_private_type_HH_
  #define OBJECT_private_type_HH_

#include <object.hh>
#include <object_str.hh>
#include <type.hh>

class object_type:public object{
public:
  friend bool operator== ( const object_type& a,const object_type& b );

  object_type ( const enum private_type type );

  object_type type ( ) const;

  object_str str ( ) const;
private:
  const enum private_type type_;
};

#endif
