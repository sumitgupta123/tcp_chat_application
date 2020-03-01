#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>
#include<errno.h>

int main()
{
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	int k;
	ser.sin_family=AF_INET;
	ser.sin_port=htons(10000);
	ser.sin_addr.s_addr=INADDR_ANY;

	int sock_id=socket(AF_INET,SOCK_STREAM,0);

	if((connect(sock_id,(struct sockaddr*)&ser,sizeof(ser)))==-1)
	{
		perror("connect:");
		return 0;
	}

	char a[100];
	char b[100];
	while(1)
	{       memset(a,0,100);
		printf("client:");
		fgets(a,100,stdin);
	send(sock_id,a,strlen(a),0);
	//memset(a,0,100);
//	printf("message sent successfully\n");
	recv(sock_id,b,99,0);
	printf("server:%s",b);
	memset(b,0,100);
	if(a[0]=='b'&&a[1]=='y'&&a[2]=='e')
	{
	close(sock_id);
	return 0;
	}
	
}
	return 0;
}

