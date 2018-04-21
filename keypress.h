#include <QWidget>
#include <QtGui>

class KeyPress : public QWidget {
    Q_OBJECT

    public:
        KeyPress(QWidget *parent = 0);

    protected:
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

    private:
        QLabel *myLabelText;
};
