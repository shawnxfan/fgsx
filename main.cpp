#include <QCoreApplication>
#include "MyIO.h"
#include <Client.h>

QTextStream cin(stdin, QIODevice::ReadOnly);
QTextStream cout(stdout, QIODevice::WriteOnly);
QTextStream cerr(stderr, QIODevice::WriteOnly);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client client;

    client.connectServer();
    while(true) {
        cout << client.m_tcpSocket->readAll();
        QString str;
        cin >> str;
        client.m_tcpSocket->write(str.toStdString().c_str(),strlen(str.toStdString().c_str()));
        client.m_tcpSocket->flush();
    }

    return a.exec();
}
