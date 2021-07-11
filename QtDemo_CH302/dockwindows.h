#ifndef DOCKWINDOWS_H
#define DOCKWINDOWS_H

#include <QMainWindow>

#include <QTextEdit>
#include <QDockWidget>

class DockWindows : public QMainWindow
{
    Q_OBJECT

public:
    DockWindows(QWidget *parent = 0);
    ~DockWindows();
};

#endif // DOCKWINDOWS_H
