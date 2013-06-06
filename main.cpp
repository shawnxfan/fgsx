#include <QCoreApplication>
#include "MyIO.h"
#include <QTcpSocket>

QTextStream cin(stdin, QIODevice::ReadOnly);
QTextStream cout(stdout, QIODevice::WriteOnly);
QTextStream cerr(stderr, QIODevice::WriteOnly);

QString getInput()
{
    QString input;
    cin>>input;
    return input;
}

void connectServer()
{
    QTcpSocket *m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost("192.168.1.178",19999);
    connect(m_tcpSocket,SIGNAL(readyRead),this,SLOT(readMesg()));
}

void readMesg()
{
    QByteArray qba =   m_tcpSocket->readAll();

    qDebug()<<qba;
    QString ss=QVariant(qba).toString();
}

void sendMesg()
{
    QString ss= getInput();
    m_tcpSocket->write(ss.toStdString().c_str(),strlen(ss.toStdString().c_str()));
}

int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);

    QString a = "xxx";

    cin >> a;
    cout<<a<<endl;//fgsb


    while(true) {
        cout << sock.readAll();
        QString str;
        cin >> str;
        sock.write(str);
        sock.flush();
    }


    // return a.exec();
}
