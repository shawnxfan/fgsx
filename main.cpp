#include <QCoreApplication>
#include <Client.h>
#include <QThread>

/*
void rthread(void)
{
    client->ReadMesg(socketfd,buf,len);
}

static void* rthread_callback(void *) {
    rthread();
}

void sthread(void)
{
    client->SendMesg(socketfd,buf);
}

static void* sthread_callback(void *) {
    sthread();
}*/

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    Client* client = new Client();
    struct sockaddr_in servaddr;
    char buf[256];
    int socketfd;
    int connstate;
    int len;
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
        /*pthread_t rid;
        int rret;
        rret = pthread_create(&rid, NULL, rthread_callback, NULL);
        if(rret != 0){
            printf ("Create pthread error!n");
            exit (1);
        }
        pthread_join(rid,NULL);*/
        while(true){
            client->ReadMesg(socketfd,buf,len);
        }
    }
    else
    {
        /*pthread_t sid;
        int sret;
        sret = pthread_create(&sid, NULL, sthread_callback, NULL);
        if(sret != 0){
            printf ("Create pthread error!n");
            exit (1);
        }
        pthread_join(sid,NULL);*/
        while(true){
            client->SendMesg(socketfd,buf);
        }
        close(socketfd);
    }
    exit(1);
//    return a.exec();
    return 0;
}
