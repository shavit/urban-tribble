#import "connection.h"

enum ENDIAN_TYPE connection_get_endian_type() {
  union {
    short s_num;
    char c_num[sizeof(short)];
  } un;

  // Check the order
  un.s_num = 0x0102;
  if (sizeof(short) == 2) {
    if (un.c_num[0] == 1 && un.c_num[1] == 2) {
      return ENDIAN_BIG;
    } else if (un.c_num[0] == 2 && un.c_num[1] == 1) {
      return ENDIAN_LITTLE;
    } else {
      return ENDIAN_UNKNOWN;
    }    
  } else {
    return ENDIAN_UNKNOWN;
  }
};

