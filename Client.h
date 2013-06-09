#ifndef HEADER_H
#define HEADER_H
#include <QCoreApplication>
#include <QObject>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

class Client : public QObject {
    Q_OBJECT
public:
    Client();
    ~Client();
public slots:
    void ConnectServer();
    void SendMesg(int socketfd,char buf[256]);
    void ReadMesg(int socketfd,char buf[256],int len);
public:
};

#endif // HEADER_H
