#include <Client.h>

Client::Client()
{

}

Client::~Client()
{

}

void Client::ConnectServer()
{

}

void Client::ReadMesg(int socketfd, char buf[256],int len)
{
    len = read(socketfd,buf,512);
    buf[len] = 0;
    printf("data=%s\n",buf);
}

void Client::SendMesg(int socketfd,char buf[256])
{
    scanf("%s",buf);
    write(socketfd,buf,strlen(buf));
}
