//
// Created by 金文泽 on 2023/6/5.
//

#ifndef VSCPROJECT_STOREDIALOG_H
#define VSCPROJECT_STOREDIALOG_H

#include <QDialog>
#include <stack>


QT_BEGIN_NAMESPACE
namespace Ui { class StoreDialog; }
QT_END_NAMESPACE

class StoreDialog : public QDialog {
Q_OBJECT

public:
    explicit StoreDialog(QWidget *parent = nullptr);

    ~StoreDialog() override;



private:
    Ui::StoreDialog *ui;
    int next_level;
    static int calculate_soul(int lv);
    bool next_available;
    bool hasNext() const;
    int temp_intelligence;
    int temp_power;
    int temp_speed;
    int temp_live;
    int temp_level;
    int temp_soul;

    void refresh_table();
    void refresh_next_level();
    void apply();
};


#endif //VSCPROJECT_STOREDIALOG_H
