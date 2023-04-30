//
// Created by 金文泽 on 2023/4/18.
//

#include "PaintInfo.h"

PaintInfo::PaintInfo(QPixmap &target, int mX, int mY) : target(target), m_X(mX), m_Y(mY) {}

QPixmap &PaintInfo::getTarget() const {
    return target;
}

int PaintInfo::getMX() const {
    return m_X;
}

int PaintInfo::getMY() const {
    return m_Y;
}
