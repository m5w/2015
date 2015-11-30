#ifndef OBJECT_STR_HH_
  #define OBJECT_STR_HH_

#include <string>

#include <object.hh>
#include <object_type.hh>
#include <type.hh>

using std :: string;

class object_str:public object{
public:
  friend bool operator== ( const object_str& a,const object_str& b );

  object_str ( const string str ); 

  object_type type ( ) const;

  object_str str ( ) const;
private:
  const string str_;
};

#endif
