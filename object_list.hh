#ifndef OBJECT_LIST_HH_
  #define OBJECT_LIST_HH_

#include <memory>
#include <ostream>
#include <vector>

#include <object.hh>

using std :: unique_ptr;

using std :: ostream;

using std :: vector;

class object_list:public object{
public:
  template<typename object_type>void append ( object_type x );

  void extend ( object_list L );

  template<typename object_type>void insert ( vector<unique_ptr<object> >:: const_iterator :: difference_type i,object_type x );

  unique_ptr<object>pop ( );

  unique_ptr<object>pop ( vector<unique_ptr<object> >:: const_iterator :: difference_type i );

  void reverse ( );
private:
  ostream& print ( ostream& a ) const override;

  bool lt ( const object& b ) const override;

  vector<unique_ptr<object> >list_;
};

#endif
