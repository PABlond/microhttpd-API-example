#ifndef PING_H
#define PING_H

#include <microhttpd.h>
#include <cjson/cJSON.h>

int ROUTE_ping(struct MHD_Connection *connection);

#endif
