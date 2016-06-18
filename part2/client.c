#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <mysql.h>
#include <my_global.h>
#include <time.h>
	
#define BUFSIZE 2000
#define SIZE 20
	
void getserverip_port(char **args, char *ip, char *s_port);

	
void commandline_parse(int argc , char *args[], char *ip, char *s_port, char *c_port, char *c_name)
{
	if (argc != 7){
		printf("usage: ./client1 -s serveraddress:port -p clientport -n clientname\n");
	}else if (argc == 7){
		if (strcmp(args[1], "-s" ) == 0){
			getserverip_port(args, ip, s_port);
		}
		if(strcmp(args[3], "-p") == 0)
			strcpy(c_port, args[4]);
		if(strcmp(args[5] , "-n") == 0)
			strcpy(c_name, args[6]);
	}
}
void connectto_server(int *sockfd, struct sockaddr_in *server_addr, struct sockaddr_in *my_addr, char *s_port, char *c_port, char *ip)
{
	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}
	server_addr->sin_family = AF_INET;
	server_addr->sin_port = htons(atoi(s_port));
	server_addr->sin_addr.s_addr = inet_addr(ip);
	memset(server_addr->sin_zero, '\0', sizeof server_addr->sin_zero);
		
	my_addr->sin_family = AF_INET;
	my_addr->sin_port = htons(atoi(c_port));
	my_addr->sin_addr.s_addr = inet_addr(ip);
	memset(my_addr->sin_zero, '\0', sizeof my_addr->sin_zero);
	
	if(connect(*sockfd, (struct sockaddr *)server_addr, sizeof(struct sockaddr)) == -1) {
		perror("connect");
		exit(1);
	}
}

void set_clear(int sockfd, fd_set *read_fds, fd_set *master)
{
        FD_ZERO(master);
        FD_ZERO(read_fds);
        FD_SET(0, master);
        FD_SET(sockfd, master);
}

void getserverip_port(char **args, char *ip, char *s_port)
{

        char **arg1;
        int i, j;
        char c;

        arg1 = args;
        i = j = 0;
        c = *arg1[2];
        while(c != ':'){
                ip[i] = c;
                c = *++arg1[2];
                i++;
        }
        ip[i] = '\0';
        c = *++arg1[2];
        while (c != '\0'){
                s_port[j] = c;
                c = *++arg1[2];
                j++;
        }
        s_port[j] = '\0';
}

void connectto_database(char* c_name, char* messages,time_t now){
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   char *server = "localhost";
   char *user = "root";
   char *password = "datvip12"; /* set me first */
   char *database = "UNIX";
   char q[BUFSIZE];
   sprintf(q,"INSERT INTO CHAT_HISTORY (Name,Message,Time) VALUES('%s','%s','%s')",c_name,messages,ctime(&now));
   // char *tempquery = " INSERT INTO CHAT_HISTORY (Name,Message) VALUES ('DOGD',"messages","now"); " ;
   conn = mysql_init(NULL);
   /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   /* send SQL query */
   if (mysql_query(conn, q)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);
   /* output table name */
   // printf("MySQL Tables in UNIX database:\n");
   // while ((row = mysql_fetch_row(res)) != NULL)
   //    printf("%s \n", row[0]);
   /* close connection */
   mysql_free_result(res);
   mysql_close(conn);
}
	
void send_recv(int i, int sockfd, char *c_name)
{	
	char send_buf[BUFSIZE];
	char recv_buf[BUFSIZE];
	int nbyte_recvd;
	//0 is the standard input
	if (i == 0){
		fgets(send_buf, BUFSIZE, stdin);
		time_t t;
    	time(&t);
		connectto_database(c_name,send_buf,t);
		fflush(stdin);
		if (strcmp(send_buf , "quit\n") == 0 || strcmp(send_buf , "QUIT\n") == 0) {
			exit(0);
		}else
			strcat(send_buf,c_name);
			send(sockfd, send_buf, strlen(send_buf), 0);
	}else {
		nbyte_recvd = recv(sockfd, recv_buf, BUFSIZE, 0);
		recv_buf[nbyte_recvd] = '\0';
		printf("%s\n" , recv_buf);
	}
}

int main(int argc, char *argv[])
{
	int sockfd, fdmax, i;
	fd_set master;
	fd_set read_fds;
	struct sockaddr_in server_addr, my_addr;
	char ip[SIZE], s_port[SIZE], c_name[SIZE], c_port[SIZE];
	
	commandline_parse(argc, argv, ip, s_port, c_port, c_name);
	// printf("what is your password\n" );
	// scanf("%s",password);
	printf("%s started\n", c_name);
	connectto_server(&sockfd, &server_addr, &my_addr, s_port, c_port, ip);
	set_clear(sockfd, &read_fds, &master);
	// send(sockfd, c_name, strlen(c_name), 0);
	fdmax = sockfd;
	while(1){
		fflush(stdin);
		printf("+");
		fflush(stdout);
		read_fds = master;
		if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
			perror("select");
			exit(4);
		}
		for(i=0; i <= fdmax; i++ ){
			if(FD_ISSET(i, &read_fds))
				send_recv(i, sockfd,c_name);
			
		}
	}

	close(sockfd);
	return 0;
}
