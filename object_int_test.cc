#include <exception>
#include <string>

#include <object.hh>
#include <object_int.hh>

using std :: exception;

using std :: stoll;

int main ( int argc,char** argv ){
  if(argc != 3){
    return 1;
  }

  try{
    object_int a_object_int ( stoll ( argv [ 1 ] ) );
    object_int b_object_int ( stoll ( argv [ 2 ] ) );

    if(! (a_object_int < b_object_int)){
      return 1;
    }

    object& a_object = a_object_int;
    object& b_object = b_object_int;

    if(! (a_object < b_object)){
      return 1;
    }

    const object_int a_const_object_int ( a_object_int );
    const object_int b_const_object_int ( b_object_int );

    if(! (a_const_object_int < b_const_object_int)){
      return 1;
    }

    const object& a_const_object = a_const_object_int;
    const object& b_const_object = b_const_object_int;

    if(! (a_const_object < b_const_object)){
      return 1;
    }
  }
  catch ( const exception& a ){
    throw a;
  }
}
