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
enum AMF0_TYPE {
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

int amf0_c0();
int amf0_c1();
int amf0_c2();


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
enum AMF3_TYPE {
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

int decode_amf(const char* msg, char* buf);

int decode_amf0(const char* msg, char* buf);

int decode_amf3(const char* msg, char* buf);

#endif /* amf_h */
