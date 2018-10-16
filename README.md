#include<stdio.h>   
#include<string.h> 
#include<stdlib.h     
#include<arpa/inet.h> 
#include<sys/socket.h> 
# define SERVER "127.0.0.1" 
#define BUFLEN 512 
#define PORT 8888   



void error (char *msg) 
{

    perror(msg); 
    exit (1); 
}
This is a function defined for displaying any error.



int main(void) 
{
    struct sockaddr_in serv_addr; 
    int sockfd; 
    int slen=sizeof(serv_addr); 
     (serv_addr: saving the addresses of client)

    char buf[BUFLEN]; 
    char message[BUFLEN];

    if ((sockfd=socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        Error ("socket isn't created ");
    }

	memset ((char *) &serv_addr, 0, sizeof(serv_addr ));
	
	serv_addr.sin_family = AF_INET;
	
	serv_addr.sin_port = htons(portno);
	
	if (inet_aton (SERVER, &serv_addr.sin_addr) == 0) 
	{
	        fprintf (stderr, "inet_aton failed\n");
	        exit (1);
	 }

	 While (1)
	 {
	        printf ("Enter message: ");
	        gets(message);
	
	          
			if (sendto (sockfd, message, strlen(message), 0, (struct sockaddr *) &serv_addr, slen) < 0)
			{
			            error ("sendto failed");
			 }
			 
			memset (buf,'\0', BUFLEN);
			
			
			
			if ((recvfrom (sockfd, buf, BUFLEN, 0, (struct sockaddr *) &serv_addr, &slen)) < 0)
			{
			            error ("recvfrom failder");
			}
	
	        
	        puts(buf);

    }
 
    close(sockfd); 

    return 0;

}

