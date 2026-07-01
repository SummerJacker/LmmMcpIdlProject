#include "picturewindow.h"
#include "ui_picturewindow.h"
#include <QDebug>

static const char* FIRE_PIC_DIR = "E:\\Programming\\SRIOProject\\FirePics\\";

PictureWindow::PictureWindow(const std::string& picName, QWidget *parent):
    QDialog(parent),
    ui(new Ui::PictureWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_DeleteOnClose);// delete this object when window is closed
    this->setWindowTitle(QString::fromStdString(picName));
    ui->pictureLabel->setPixmap(QPixmap
                (QString(FIRE_PIC_DIR) + picName.c_str()));
    ui->pictureLabel->adjustSize();
    this->adjustSize();
}

PictureWindow::~PictureWindow()
{
    delete ui;
}
