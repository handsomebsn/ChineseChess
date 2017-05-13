#ifndef CHOOSEDLG_H
#define CHOOSEDLG_H

#include <QDialog>
#include <QPushButton>

class ChooseDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseDlg(QWidget *parent = 0);

    //定义4个按钮
    QPushButton* _buttons[4];
    //用于判断哪个按钮被点击，并传递给主窗口
    int _selected;

public slots:
    //按钮被点击时，给_selected赋值
    void slotClicked();
};

#endif // CHOOSEDLG_H
