#ifndef OBJECT_LIST_HH_
  #define OBJECT_LIST_HH_

#include <memory>
#include <ostream>
#include <vector>

#include <object.hh>

using std :: shared_ptr;

using std :: ostream;

using std :: vector;

class object_list:public object{
public:
  template<typename object_type>void append ( object_type x );

  void extend ( object_list L );

  template<typename object_type>void insert ( vector<shared_ptr<object> >:: const_iterator :: difference_type i,object_type x );

  shared_ptr<object>pop ( );

  shared_ptr<object>pop ( vector<shared_ptr<object> >:: const_iterator :: difference_type i );

  void reverse ( );
private:
  ostream& print ( ostream& a ) const override;

  bool lt ( const object& b ) const override;

  vector<shared_ptr<object> >list_;
};

template<typename object_type>void object_list :: append ( object_type x ){
  list_ . emplace_back ( new object_type ( x ) );
}

template<typename object_type>void object_list :: insert ( vector<shared_ptr<object> >:: const_iterator :: difference_type i,object_type x ){
  list_ . emplace ( list_ . cbegin ( ) + i,make_shared ( new object_type ( x ) ) );
}

#endif
