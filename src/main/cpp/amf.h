#ifndef amf_h
#define amf_h

/*
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  | 16 bits | 16 bits       | header count*56 | 16 bits       | message count*64 |
  |         |               | + bits          |               | +bits            |
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  |         |               |                 |               |                  |
  | Version | Header Count  | Header Type     | Message Count | Message Type     |
  |         |               |                 |               |                  |
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/
typedef enum {
    AMF0_NUMBER=0,
    AMF0_BOOL,
    AMF0_STRING,
    AMF0_OBJECT,
    AMF0_MOVIE,
    AMF0_NULL,
    AMF0_UNDEFINED,
    AMF0_REFERENCE,
    AMF0_ARRAY,
    AMF0_END,
};

/*
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  | 16 bits | 16 bits       | header count*56 | 16 bits       | message count*64 |
  |         |               | + bits          |               | +bits            |
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  |         |               |                 |               |                  |
  | Version | Header Count  | Header Type     | Message Count | Message Type     |
  |         |               |                 |               |                  |
  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
typedef enum {
   AMF3_UNDEFINED=0,
   AMF3_MULL,
   AMF3_FALSE,
   AMF3_TRUE,
   AMF3_INTEGER,
   AMF3_DOUBLE,
   AMF3_STRING,
   AMF3_XML,
   AMF3_DATE,
   AMF3_ARRAY,
   AMF3_OBJECT,
   AMF3_XML_END,
   AMF3_BYTE_ARRAY,
   AMF3_VECTOR_INT,
   AMF3_VECTOR_UINT,
   AMF3_VECTOR_DOUBLE,
   AMF3_VECTOR_OBJECT,
   AMF3_DICTIONARY
};

int stream_amf0(char* msg);

#endif /* amf_h */
