#include <ostream>

#include <object.hh>

using std :: ostream;

class object_int:public object{
public:
  object_int ( const long long int_ );

  const long long int_;
private:
  ostream& print ( ostream& a ) const override;

  bool lt ( const object& b ) const override;
};
