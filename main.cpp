#include <QCoreApplication>
#include "MyIO.h"

QTextStream cin(stdin, QIODevice::ReadOnly);
QTextStream cout(stdout, QIODevice::WriteOnly);
QTextStream cerr(stderr, QIODevice::WriteOnly);

QString getInput()
{
    QString input;
    cin>>input;
    return input;
}

int main(int argc, char *argv[])
{
    QString a = "xxx";

    cin >> a;
    cout<<a<<endl;//fgsb
}
