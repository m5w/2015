#ifndef OBJECT_TYPE_HH_
  #define OBJECT_TYPE_HH_

#include <object.hh>
#include <object_str.hh>
#include <type.hh>

class object_type:public object{
public:
  friend bool operator== ( const object_type& a,const object_type& b );

  object_type ( const enum TYPE type );

  object_type type ( ) const;

  object_str str ( ) const;
private:
  const enum TYPE type_;
};

#endif
