#include "not_found.h"

#include <string.h>

int ROUTE_not_found(struct MHD_Connection *connection) {
	const char *response_message =
	    "<html><head><title>Not found</title></head><body>Go "
	    "away.</body></html>";
	struct MHD_Response *response = MHD_create_response_from_buffer(
	    strlen(response_message), (void *)response_message,
	    MHD_RESPMEM_PERSISTENT);
	int ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
	MHD_add_response_header(response, MHD_HTTP_HEADER_CONTENT_ENCODING,
				"application/html");
	MHD_destroy_response(response);

	return ret;
}
