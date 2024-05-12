#ifndef HANDLER_H
#define HANDLER_H

#include <microhttpd.h>

#include "routes/not_found.h"
#include "routes/ping.h"

int handle_request(void *cls, struct MHD_Connection *connection,
		   const char *url, const char *method, const char *version,
		   const char *upload_data, size_t *upload_data_size,
		   void **con_cls);

#endif

