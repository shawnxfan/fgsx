#include <Client.h>
#include <MyIO.h>
#include <iostream>

Client::Client()
{

}

Client::~Client()
{

}

void Client::connectServer()
{
    QString qStrIP;
    quint16 netport;
    cout<<"Please enter the IP address:"<<endl;
    cin>>qStrIP;

    cout<<"Please enter the port:"<<endl;
    cin>>netport;

    m_tcpSocket = new QTcpSocket();
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost(qStrIP,netport);
    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(readMesg()));
}

void Client::readMesg()
{
    QByteArray qba = m_tcpSocket->readAll();
    qDebug()<<qba;
}

void Client::sendMesg()
{
    QString ss;
    cin<<ss;
    m_tcpSocket->write(ss.toStdString().c_str(),strlen(ss.toStdString().c_str()));
}
