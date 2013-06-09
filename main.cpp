#include <QCoreApplication>
#include <Client.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    struct sockaddr_in servaddr;
    char buf[256];
    int socketfd;
    int connstate;
    int len;
    Client* client = new Client();

    //client->ConnectServer();
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5500);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connstate = connect(socketfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    if(connstate == -1)
    {
        printf("Error!Can not connect.");
        return -1;
    }

    pid_t tid;
    tid = fork();
    if(tid == 0)
    {
        while(true)
        {
            client->ReadMesg(socketfd,buf,len);
        }
    }
    else
    {
        while(true)
        {
            client->SendMesg(socketfd,buf);
        }
        close(socketfd);
    }
    return a.exec();
    return 0;
}
