//
// Created by 金文泽 on 2023/4/11.
//

#ifndef VSCPROJECT_MENU_H
#define VSCPROJECT_MENU_H

#include <QWidget>
#include "gamemain.h"

class GameMain;

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QWidget {
Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);

    ~Menu() override;

    void reportGameOver();
    void reportGamePaused();
    void reportGameStart(GameMain * game) { _game = game; }

private:
    Ui::Menu *ui;
    GameMain * _game;

private slots:
    void launch_game();
};


#endif //VSCPROJECT_MENU_H
