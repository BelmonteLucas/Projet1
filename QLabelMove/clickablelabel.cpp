#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent) {}

ClickableLabel::ClickableLabel(const QString &Image1, const QString &Image2, QWidget *parent)
    : QLabel(parent) {
    setImages(Image1, Image2);
}

void ClickableLabel::setImages(const QString &Image1, const QString &Image2) {

    im1 = Image1;
    im2 = Image2;
    setPixmap(QPixmap(im1));
}

bool ClickableLabel::isPressed() {
    return pressed;
}

void ClickableLabel::mousePressEvent(QMouseEvent *event) {

    setPixmap(QPixmap(im2));
    if (event->button() == Qt::LeftButton)
    {
        clicked = true;
        dragStartPosition = event->pos();
        dragging = true;
        emit clickedSignal();
    }
    QLabel::mousePressEvent(event);
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent *event) {

    setPixmap(QPixmap(im1));
    if (event->button() == Qt::LeftButton && dragging)
    {
        dragging = false;
        emit released();
    }
    clicked = false;
    QLabel::mouseReleaseEvent(event);
}

void ClickableLabel::mouseMoveEvent(QMouseEvent *event) {

    if (dragging)
    {
        QPoint currentPosition = mapToParent(event->pos() - dragStartPosition);
        move(currentPosition);
        emit dragNdrop();
    }
    QLabel::mouseMoveEvent(event);
}


