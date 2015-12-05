#include <object.hh>

class object_int:public object{
public:
  object_int ( const long long int_ );

  const long long int_;
private:
  bool lt ( const object& b ) const override;
};
