#ifndef PICTUREWINDOW_H
#define PICTUREWINDOW_H

#include <QDialog>
#include <string>

namespace Ui {
class PictureWindow;
}

class PictureWindow : public QDialog
{
    Q_OBJECT

public:
    PictureWindow(const std::string& picName, QWidget *parent = nullptr);

    ~PictureWindow();

private:
    Ui::PictureWindow *ui;
};

#endif // PICTUREWINDOW_H
