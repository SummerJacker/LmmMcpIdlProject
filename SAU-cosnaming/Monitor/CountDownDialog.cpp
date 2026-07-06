#include "countdowndialog.h"
#include "ui_countdowndialog.h"

unsigned int CountDownDialog::WindowsCount = 0;
std::mutex CountDownDialog::CountMutex;

CountDownDialog::CountDownDialog(const std::string& title, unsigned int number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CountDownDialog),
    lcdUpdateTimer(this)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_DeleteOnClose);// delete this object when window is closed
    connect(&lcdUpdateTimer, SIGNAL(timeout()), this, SLOT(updateLCDNumber()));
    this->setFixedSize(DefaultWidth, DefaultHeight);
    this->setWindowTitle(QString::fromLocal8Bit("倒计时对话框"));
    // adjust window position
    if(parent)
    {
        int ax, ay, aw, ah;
        parent->geometry().getRect(&ax, &ay, &aw, &ah);
//        this->move(ax + aw/2 - DefaultWidth/2 + static_cast<int>(WindowsCount)*Offset
//                   , ay + ah/2 - DefaultHeight/2 + static_cast<int>(WindowsCount)*Offset);
        int merge = 3;//aw / DefaultWidth - 1;
        this->move(ax + static_cast<int>(WindowsCount)%merge*DefaultWidth
                   , ay + static_cast<int>(WindowsCount)/merge*(DefaultHeight+30));
    }
    CountDownDialog::CountMutex.lock();
    WindowsCount ++;
    CountDownDialog::CountMutex.unlock();
    ui->stateLabel->setText(QString::fromLocal8Bit(title.c_str()));
    ui->lcdNumber->display(static_cast<int>(number));
    ui->stateLabel->update();
    ui->lcdNumber->update();
    lcdUpdateTimer.start(1000);// 1s
}

CountDownDialog::~CountDownDialog()
{
    this->lcdUpdateTimer.stop();
    delete ui;
    CountDownDialog::CountMutex.lock();
    WindowsCount --;
    CountDownDialog::CountMutex.unlock();
}

void CountDownDialog::updateLCDNumber()
{
    int current = ui->lcdNumber->intValue();
    current --;
    if(current != 0)
        ui->lcdNumber->display(current);
    else
    {
        this->lcdUpdateTimer.stop();
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::red);
        ui->label1->setPalette(pe);
        ui->label1->setText(QString::fromLocal8Bit("已超时"));
        ui->label2->hide();
        ui->lcdNumber->hide();
    }
    ui->lcdNumber->update();
}
