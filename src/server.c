#include <stdio.h>
#include "server.h"
#include "handler.h"

#define PORT 8888

static struct MHD_Daemon *server_daemon = NULL;

int initialize_server() 
{
	server_daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                              &handle_request, NULL, MHD_OPTION_END);
    	if (!server_daemon)
        	return 1;

    	printf("Server initialised on port %d.\n", PORT);
    	return 0;
}

int start_server() 
{
	if (!server_daemon)
        	return 1;
	// TODO 
    	return 0;
}

void stop_server() 
{
	if (server_daemon) {
        	MHD_stop_daemon(server_daemon);
        	server_daemon = NULL;
    	} else 
        	printf("Le serveur n'est pas démarré.\n");
    	
}
