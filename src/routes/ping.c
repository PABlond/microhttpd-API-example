#include "ping.h"

#include <string.h>

int ROUTE_ping(struct MHD_Connection *connection) {
	cJSON *json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "status", "OK");
	const char *json_response = cJSON_Print(json);
	struct MHD_Response *response;
	int ret;
	response = MHD_create_response_from_buffer(strlen(json_response),
						   (void *)json_response,
						   MHD_RESPMEM_PERSISTENT);
	if (!response) return MHD_NO;
	MHD_add_response_header(response, "Content-Type", "application/json");
	ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
	MHD_destroy_response(response);
	cJSON_Delete(json);

	return ret;
}

