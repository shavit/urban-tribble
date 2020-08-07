#ifndef connection_h
#define connection_h

typedef enum ENDIAN_TYPE {
  ENDIAN_UNKNOWN=0,
  ENDIAN_LITTLE,
  ENDIAN_BIG,
};

enum ENDIAN_TYPE connection_get_endian_type() { };


#endif /* connection_h */
