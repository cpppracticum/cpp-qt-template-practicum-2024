#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class Calendar {
    kEast,
    kTibet,
    kZoroastr
};

enum class Horoscope {
    kZodiak,
    kDruid
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    Calendar calendar_ = Calendar::kEast;
    Horoscope horoscope_ = Horoscope::kZodiak;
};
#endif // MAINWINDOW_H
