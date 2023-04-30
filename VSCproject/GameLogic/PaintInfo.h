//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_PAINTINFO_H
#define VSCPROJECT_PAINTINFO_H
#include <QPixmap>


class PaintInfo {
    QPixmap & target;
    int m_X;
    int m_Y;

public:
    PaintInfo(QPixmap &target, int mX, int mY);

    QPixmap &getTarget() const;

    int getMX() const;

    int getMY() const;
};



#endif //VSCPROJECT_PAINTINFO_H
