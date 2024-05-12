#ifndef PING_H
#define PING_H

#include <cjson/cJSON.h>
#include <microhttpd.h>

int ROUTE_ping(struct MHD_Connection *connection);

#endif
