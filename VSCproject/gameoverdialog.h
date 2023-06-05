//
// Created by 金文泽 on 2023/6/5.
//

#ifndef VSCPROJECT_GAMEOVERDIALOG_H
#define VSCPROJECT_GAMEOVERDIALOG_H

#include <QDialog>
#include "GameLogic/config.h"

class Menu;
QT_BEGIN_NAMESPACE
namespace Ui { class GameOverDialog; }
QT_END_NAMESPACE

class GameOverDialog : public QDialog {
Q_OBJECT

public:
    explicit GameOverDialog(Menu * parent = nullptr, int e_cnt = 0, double h_percent = 0, int s_cnt = 0);

    ~GameOverDialog() override;

private:
    Ui::GameOverDialog *ui;
    Menu * m;
};


#endif //VSCPROJECT_GAMEOVERDIALOG_H
