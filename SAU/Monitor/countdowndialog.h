#ifndef COUNTDOWNDIALOG_H
#define COUNTDOWNDIALOG_H

#include <QDialog>
#include <QTimer>
#include <mutex>

namespace Ui {
class CountDownDialog;
}

class CountDownDialog : public QDialog
{
    Q_OBJECT

public:
    CountDownDialog(const std::string& title, unsigned int number, QWidget *parent);

    ~CountDownDialog();

private slots:
    void updateLCDNumber();

private:
    const int DefaultWidth = 320;

    const int DefaultHeight = 200;

    const int Offset = 40;

    static unsigned int WindowsCount;

    static std::mutex CountMutex;

    Ui::CountDownDialog *ui;

    QTimer lcdUpdateTimer;
};

#endif // COUNTDOWNDIALOG_H
