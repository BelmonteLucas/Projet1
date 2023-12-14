#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    ClickableLabel(QWidget *parent = nullptr);
    ClickableLabel(const QString &Image1, const QString &Image2, QWidget* parent = nullptr);
    void setImages(const QString &Image1, const QString &Image2);
    bool isPressed();

private:
    QString im1, im2;
    bool pressed{false};
    bool clicked{true};
    QPoint dragStartPosition;
    bool dragging{false};

signals:
    void clickedSignal();
    void released();
    void dragNdrop();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};

#endif // CLICKABLELABEL_H;


