#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QStackedLayout>
#include <QPushButton>

class welcome : public QWidget
{
    Q_OBJECT

public:
    welcome(QWidget *parent = nullptr);
    QStackedLayout* Pages = nullptr;
    QWidget* Page(
            QWidget *Page,
            const int &PageType,
            const QString &ImagePath
            );
    QPushButton * PageButton(QPushButton * Button, const QString &Name);
    ~welcome();
};
#endif // WELCOME_H
