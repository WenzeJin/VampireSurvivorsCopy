//
// Created by 金文泽 on 2023/6/5.
//

#ifndef VSCPROJECT_SELECTDIALOG_H
#define VSCPROJECT_SELECTDIALOG_H

#include <QWidget>

class Menu;
QT_BEGIN_NAMESPACE
namespace Ui { class SelectDialog; }
QT_END_NAMESPACE

class SelectDialog : public QWidget {
Q_OBJECT

public:
    explicit SelectDialog(Menu * menu_parent,QWidget *parent = nullptr);

    ~SelectDialog() override;

private:
    Ui::SelectDialog *ui;
    Menu * m_p;



};


#endif //VSCPROJECT_SELECTDIALOG_H
