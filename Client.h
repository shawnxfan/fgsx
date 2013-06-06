#ifndef HEADER_H
#define HEADER_H
#include <QTcpSocket>
#include <QObject>

class Client : public QObject {
    Q_OBJECT
public:
    Client();
    ~Client();
public slots:
    void connectServer();
    void sendMesg();
    void readMesg();
public:
    QTcpSocket *m_tcpSocket;
};

#endif // HEADER_H
