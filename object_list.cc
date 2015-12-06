#include <algorithm>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

#include <object_list.hh>

using std :: for_each;
using std :: lexicographical_compare;
using std :: reverse;

using std :: unique_ptr;

using std :: ostream;

using std :: move;

using std :: vector;

template<typename object_type>void object_list :: append ( object_type x ){
  list_ . emplace_back ( new object_type ( x ) );
}

void object_list :: extend ( object_list L ){
  list_ . reserve ( list_ . size ( ) + L . list_ . size ( ) );

  for(auto& item:L . list_){
    list_ . push_back ( move ( item ) );
  }
}

template<typename object_type>void object_list :: insert ( vector<unique_ptr<object> >:: const_iterator :: difference_type i,object_type x ){
  list_ . emplace ( list_ . cbegin ( ) + i,new object_type ( x ) );
}

unique_ptr<object>object_list :: pop ( ){
  unique_ptr<object>item = move ( list_ . back ( ) );
  list_ . pop_back ( );
  return item;
}

unique_ptr<object>object_list :: pop ( vector<unique_ptr<object> >:: iterator :: difference_type i ){
  auto index = list_ . begin ( ) + i;
  unique_ptr<object>item = move ( * index );
  list_ . erase ( index );
  return item;
}

void object_list :: reverse ( ){
  :: reverse ( list_ . begin ( ),list_ . end ( ) );
}

ostream& object_list :: print ( ostream& a ) const{
  a << '[' << * ( list_ . front ( ) );
  for_each ( ++ list_ . cbegin ( ),list_ . cend ( ),[&]( const object& b ){a << ", " << b;});
  a << ']';
  return a;
}

bool object_list :: lt ( const object& b ) const{
  auto b_list = dynamic_cast<const object_list&>( b );
  return lexicographical_compare ( list_ . cbegin ( ),list_ . cend ( ),b_list . list_ . cbegin ( ),b_list . list_ . cend ( ) );
}
