#include "dialog.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style.qss");
    if (file.open(QIODevice::ReadOnly)) {
        qDebug() << "11";
        a.setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }
    Dialog w;
    w.show();

    return a.exec();
}
