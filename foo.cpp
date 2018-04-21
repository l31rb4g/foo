#include <iostream>
#include <fstream>
#include <string>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QVBoxLayout>
#include <QEvent>
using namespace std;


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QKeyEvent ev(QEvent::KeyPress);
    window.keyPressEvent(ev);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(2);
    layout->setMargin(2);

    QPalette palette = window.palette();
    palette.setColor(QPalette::Window, QColor("#ffcccc"));
    palette.setColor(QPalette::WindowText, QColor("#ffffff"));

    int line_height = 45;
    int line_count = 0;

    string line;
    string file_path = "/home/l31rb4g/.foo";
    ifstream f(file_path);
    if (f.is_open()){
        cout << "File opened\n";
        while (getline(f, line)){
            if (line != ""){
                line_count++;
                string label_line = to_string(line_count) + ". " + line;
                QLabel *label = new QLabel(label_line.c_str());
                string style = "padding:0 5px;";
                if (line_count == 1){
                    style += "background: #222";
                } else {
                    style += "background: #2c2c2c";
                }

                label->setStyleSheet(style.c_str());
                label->setMargin(0);
                label->setPalette(palette);
                layout->addWidget(label);
            }
        }

        f.close();

        // set black background
        palette.setColor(QPalette::Background, QColor("#333333"));
        window.setAutoFillBackground(true);
        window.setPalette(palette);
        window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        window.setFixedSize(300, line_height * line_count);
        window.setLayout(layout);
        window.show();
        app.exec();
    } else {
        cout << "Unable to open file " << file_path << "\n";
    }

    return 0;
}

