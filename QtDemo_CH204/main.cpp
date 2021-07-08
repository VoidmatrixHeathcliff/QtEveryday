#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, QString> map;

    map.insert("Beijing", "111");
    map.insert("Shanghai", "021");
    map.insert("Nanjing", "025");

    QMapIterator<QString, QString> i(map);

    for(; i.hasNext();)
        qDebug() << "\t" << i.key() << "\t" << i.next().value();

    QMutableMapIterator<QString, QString> mi(map);

    if(mi.findNext("111"))
        mi.setValue("010");

    QMapIterator<QString, QString> modi(map);

    for(; modi.hasNext();)
        qDebug() << "\t" << modi.key() << "\t" << modi.next().value();

    return a.exec();
}
