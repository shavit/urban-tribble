#ifndef amf_h
#define amf_h

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

int stream_amf0(char* msg);

#endif /* amf_h */
