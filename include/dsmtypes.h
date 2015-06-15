#ifndef DSM_COMMON_FTYPES_H
#define DSM_COMMON_FTYPES_H

#include <limits.h>
#include <stdint.h>

// Typing that long attribute is hard
#define packed __attribute__((__packed__))

// Because unsigned char is long...
typedef unsigned char uchar;

// Because unsigned int is long...
typedef unsigned int uint;

// phandle type we use across the library
typedef uint64_t dhandle;

typedef enum packed dsm_msg_type_enum {
  NOOP,
  ALLOCCHUNK,
  FREECHUNK,
  GETPAGE,
  LOCATEPAGE,
  INVALIDATEPAGE,
  TERMINATE,
  ERROR,
  PAD_MSG_TYPE_ENUM = INT_MAX
} dsm_msg_type;

typedef enum packed dsm_error_enum {
  DSM_ENOTIMPL,
  DSM_EBADOP,
  DSM_ENOENT,
  DSM_EINTERNAL,
  DSM_EBADALLOC,
  DSM_ENOPAGE,
  PAD_ERROR_ENUM = INT_MAX
} dsm_error;

#define HOST_NAME 128
#define MAP_SIZE (1024*1024)
#define NUM_CHUNKS 32

struct dsm_map {
  uint64_t offset;
  char host[HOST_NAME];
  int port;
};

extern int PAGESIZE;

#endif
