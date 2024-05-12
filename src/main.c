#include <stdio.h>
#include "server.h"

int main() 
{
	if (initialize_server() != 0) {
        	printf("Server not initialized\n");
        	return 1;
    	}

    	if (start_server() != 0) {
        	printf("Server not started\n");
        	return 1;
    	}

    	printf("Enter to stop server...\n");
    	getchar();

    	stop_server();

    	return 0;
}
