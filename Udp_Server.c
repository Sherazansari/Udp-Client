#include<stdio.h>  
#include<string.h>                                                                                             
#include<stdlib.h     
#include<arpa/inet.h> 
#include<sys/socket.h> 
#define BUFLEN 512 
#define PORT 8888   
void error (char *msg) 
{
    perror(msg); 
    exit (1);   
}




int main(void) 
{
    struct sockaddr_in serv_addr, cli_addr;
    int sockfd;
    int slen=sizeof(cli_addr); 
     (cli_addr: saving the addresses of client)
    int recv_len; 
    char buf[BUFLEN]; 
    char message[BUFLEN]; 

    if ((sockfd =socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        error ("socket isn't created ");
    }

	memset ((char *) &serv_addr, 0, sizeof(serv_addr ));
	
	serv_addr.sin_family = AF_INET;
	
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	serv_addr.sin_port = htons(portno);
	
	if (bind (sockfd, (struct sockaddr*) &serv_addr , sizeof(serv_addr )) < 0)
	{
	        error("bind");
	}
	
	
	
	while (1)
	{
	        printf ("Waiting for data...");
	        fflush(stdout);
	
			if ((recv_len = recvfrom (sockfd, buf, BUFLEN, 0, (struct sockaddr *) &cli_addr, &slen)) == -1)
			{
			            error ("recvfrom failed");
			}
			
			printf ("Received packet from %s: %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port)); 
			
			
			 if (sendto (sockfd, buf, recv_len, 0, (struct sockaddr*) &cli_addr, slen) < 0)
			{
			            error ("send to failed");
			}
	}
	
	 
	    close(sockfd); 
	
	    
	return 0;

}

