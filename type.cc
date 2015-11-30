#include <string>

#include <type.hh>

using std :: string;

string str ( const enum TYPE type ){
  switch(type){
  case TYPE :: str:{
    return "str";
    break;
  }
  case TYPE :: type:{
    return "type";
    break;
  }
  }
}
