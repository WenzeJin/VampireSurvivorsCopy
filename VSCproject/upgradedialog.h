//
// Created by 金文泽 on 2023/6/5.
//

#ifndef VSCPROJECT_UPGRADEDIALOG_H
#define VSCPROJECT_UPGRADEDIALOG_H

#include <QDialog>

class GameMain;

QT_BEGIN_NAMESPACE
namespace Ui { class UpgradeDialog; }
QT_END_NAMESPACE

class UpgradeDialog : public QDialog {
Q_OBJECT

public:
    explicit UpgradeDialog(GameMain * game_widget ,QWidget *parent = nullptr);

    ~UpgradeDialog() override;

private:
    Ui::UpgradeDialog *ui;
    GameMain * parent;

    void choose1();
    void choose2();
    void choose3();
};


#endif //VSCPROJECT_UPGRADEDIALOG_H
