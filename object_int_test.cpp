#include "object_int.hpp"

#include "object.hpp"

#include <exception>
#include <string>

int main(int argc, char **argv) {
  if (argc != 3) {
    return 1;
  }

  try {
    object_int a_object_int(std::stoll(argv[1]));
    object_int b_object_int(std::stoll(argv[2]));

    if (!(a_object_int < b_object_int)) {
      return 1;
    }

    object &a_object = a_object_int;
    object &b_object = b_object_int;

    if (!(a_object < b_object)) {
      return 1;
    }

    const object_int a_const_object_int(a_object_int);
    const object_int b_const_object_int(b_object_int);

    if (!(a_const_object_int < b_const_object_int)) {
      return 1;
    }

    const object &a_const_object = a_const_object_int;
    const object &b_const_object = b_const_object_int;

    if (!(a_const_object < b_const_object)) {
      return 1;
    }
  } catch (const std::exception &a) {
    throw a;
  }
}
