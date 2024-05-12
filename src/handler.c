#include "handler.h"

#include <string.h>

int handle_request(void *cls, struct MHD_Connection *connection,
		   const char *url, const char *method, const char *version,
		   const char *upload_data, size_t *upload_data_size,
		   void **con_cls) {
	if (strcmp(method, "GET") == 0 && strcmp(url, "/ping") == 0)
		return ROUTE_ping(connection);

	return ROUTE_not_found(connection);
}
