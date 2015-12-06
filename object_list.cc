#include <algorithm>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

#include <object_list.hh>

using std :: for_each;
using std :: lexicographical_compare;
using std :: reverse;

using std :: make_shared;
using std :: shared_ptr;

using std :: ostream;

using std :: move;

using std :: vector;

void object_list :: extend ( object_list L ){
  list_ . reserve ( list_ . size ( ) + L . list_ . size ( ) );

  for(auto& item:L . list_){
    list_ . push_back ( move ( item ) );
  }
}

shared_ptr<object>object_list :: pop ( ){
  shared_ptr<object>item = move ( list_ . back ( ) );
  list_ . pop_back ( );
  return item;
}

shared_ptr<object>object_list :: pop ( vector<shared_ptr<object> >:: iterator :: difference_type i ){
  auto index = list_ . begin ( ) + i;
  shared_ptr<object>item = move ( * index );
  list_ . erase ( index );
  return item;
}

void object_list :: reverse ( ){
  :: reverse ( list_ . begin ( ),list_ . end ( ) );
}

ostream& object_list :: print ( ostream& a ) const{
  a << '[' << * ( list_ . front ( ) );
  for_each ( ++ list_ . cbegin ( ),list_ . cend ( ),[&]( const shared_ptr<object>& b ){a << ", " << * b;});
  a << ']';
  return a;
}

bool object_list :: lt ( const object& b ) const{
  auto b_list = dynamic_cast<const object_list&>( b );
  return lexicographical_compare ( list_ . cbegin ( ),list_ . cend ( ),b_list . list_ . cbegin ( ),b_list . list_ . cend ( ) );
}
