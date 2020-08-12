#include "connection.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


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

int resolve_ip(char* host) {
  struct addrinfo hints, *res, *p;
  int status;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET; // AF_INET, AF_INET6 or AF_UNSPEC

  if ((status = getaddrinfo(host, NULL, &hints, &res)) != 0) {
    fprintf(stderr, "Error getting address info: %s\n", gai_strerror(status));
    return 2;
  }

  for (p = res; p != NULL; p = p->ai_next) {
    void *addr;
    char *ipver;

    if (p->ai_family == AF_INET) {
      struct sockaddr_in *ipv4 = (struct sockaddr_in*)p->ai_addr;
      addr=  &(ipv4->sin_addr);
      ipver = "IPv4";
    } else {
      // IPV6
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6*)p->ai_addr;
      addr = &(ipv6->sin6_addr);
      ipver = "IPv6";
    }

    // Convert the IP to string
    inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
    printf("IP for host %s is %s\n", host, ip);
  }

  freeaddrinfo(res);

  return 0;
}
