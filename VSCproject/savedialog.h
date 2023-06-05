//
// Created by 金文泽 on 2023/6/5.
//

#ifndef VSCPROJECT_SAVEDIALOG_H
#define VSCPROJECT_SAVEDIALOG_H

#include <QDialog>
#include <string>
#include <vector>

class Menu;
QT_BEGIN_NAMESPACE
namespace Ui { class SaveDialog; }
QT_END_NAMESPACE

class SaveDialog : public QDialog {
Q_OBJECT

public:
    explicit SaveDialog(Menu * m, QWidget *parent = nullptr);

    ~SaveDialog() override;

private:
    Ui::SaveDialog *ui;
    Menu * m_p;

    void refresh_file_list();
    void refresh_file_display();
    void new_file(QString & file_name);
    void store(QString & file_name);
    int file_cnt = 0;
    std::vector<std::string> file_name;
};


#endif //VSCPROJECT_SAVEDIALOG_H
