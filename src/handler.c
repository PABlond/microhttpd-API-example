#include <string.h>
#include "handler.h"

int handle_request(void *cls, struct MHD_Connection *connection,
                   const char *url, const char *method,
                   const char *version, const char *upload_data,
                   size_t *upload_data_size, void **con_cls) 
{
	if (strcmp(method, "GET") == 0 && strcmp(url, "/ping") == 0) {
        	const char *json_response = "{\"status\": \"OK\"}";
        	struct MHD_Response *response;
        	int ret;

        	response = MHD_create_response_from_buffer(strlen(json_response),
                                                   	   (void *)json_response,
                                                           MHD_RESPMEM_PERSISTENT);
        	if (!response)
            		return MHD_NO;

        	MHD_add_response_header(response, "Content-Type", "application/json");

        	ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        	MHD_destroy_response(response);

        	return ret;
    	}

    	const char *page = "<html><body>Hello, World!</body></html>";
    	struct MHD_Response *response;
    	int ret;

    	response = MHD_create_response_from_buffer(strlen(page),
                                               (void *)page,
                                               MHD_RESPMEM_PERSISTENT);
    	if (!response)
        return MHD_NO;

    	ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    	MHD_destroy_response(response);

    	return ret;
}
