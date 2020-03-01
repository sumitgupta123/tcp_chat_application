#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

int main()
{
	struct sockaddr_in ser;

	memset(&ser,0,sizeof(ser));

	ser.sin_family=AF_INET;
	ser.sin_port=htons(10000);
	ser.sin_addr.s_addr=INADDR_ANY;

	int sock_id=socket(AF_INET,SOCK_STREAM,0);

	bind(sock_id,(struct sockaddr*)&ser,sizeof(ser));

	listen(sock_id,1);
	int len=sizeof(ser);
	int cli=accept(sock_id,(struct sockaddr*)&ser,&len);

	char a[100];
	char b[100];
	while(1)
	{
	memset(a,0,100);
	recv(cli,a,99,0);
	printf("client:%s",a);
	printf("server:");
		fgets(b,100,stdin);
		send(cli,b,strlen(b),0);
	if(a[0]=='b'&&a[1]=='y'&&a[2]=='e')
		return 0;

	memset(b,0,100);
	}

	close(sock_id);
	return 0;
}
