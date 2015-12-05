#ifndef OBJECT_HH_
  #define OBJECT_HH_

class object{
public:
  friend bool operator< ( const object& a,const object& b );

  virtual ~object ( ) = default;
protected:
  virtual bool lt ( const object& b ) const = 0;
};

#endif
