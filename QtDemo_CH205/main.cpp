#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, QString> map;

    map.insert("Beijing", "111");
    map.insert("Shanghai", "021");
    map.insert("Nanjing", "025");

    QMap<QString, QString>::const_iterator i;

    for(i = map.constBegin(); i!= map.constEnd(); i++)
        qDebug() << "\t" << i.key() << i.value();

    QMap<QString, QString>::iterator mi;

    mi = map.find("Beijing");

    if(mi != map.end())
        mi.value() = "010";

    QMap<QString, QString>::const_iterator modi;

    for(modi = map.constBegin(); modi!= map.constEnd(); modi++)
        qDebug() << "\t" << modi.key() << modi.value();

    return a.exec();
}
