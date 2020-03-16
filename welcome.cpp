#include "welcome.h"
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QImageReader>
#include <QPixmap>
#include <QApplication>
#include <QGraphicsDropShadowEffect>


welcome::welcome(QWidget *parent)
    : QWidget(parent)
{
    QWidget * FirstPage = new QWidget;
    QWidget * SecondPage = new QWidget;
    QWidget * ThirdPage = new QWidget;
    QWidget * FourthPage = new QWidget;
    QWidget * FifthPage = new QWidget;

    Page(FirstPage,1,"://resource/images/image1.jpg");
    Page(SecondPage,2,"://resource/images/image2.jpg");
    Page(ThirdPage,2,"://resource/images/image3.jpg");
    Page(FourthPage,2,"://resource/images/image4.jpg");
    Page(FifthPage,3,"://resource/images/image5.jpg");

    Pages = new QStackedLayout;
    Pages->setSpacing(0);
    Pages->setMargin(0);
    Pages->addWidget(FirstPage);
    Pages->addWidget(SecondPage);
    Pages->addWidget(ThirdPage);
    Pages->addWidget(FourthPage);
    Pages->addWidget(FifthPage);


    Pages->setCurrentIndex(0);

    this->resize(QSize(1366,768));
    this->setMaximumSize(QSize(1366,768));
    this->setWindowTitle("KOOMPI OS");
    this->setWindowIcon(QIcon("://resource/icons/koompi-light.svg"));
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setLayout(Pages);
}

QWidget *welcome::Page(QWidget *Page, const int &PageType, const QString &ImagePath)
{
    QGridLayout * PageLayout = new QGridLayout;
    QLabel * PageBackground = new QLabel;
    QPushButton * NextButton = new QPushButton;
    QPushButton * BackButton = new QPushButton;
    QPushButton * DoneButton = new QPushButton;

    QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect;
    effect1->setBlurRadius(50);
    effect1->setXOffset(0);
    effect1->setYOffset(10);
    effect1->setColor(Qt::black);

    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
    effect2->setBlurRadius(50);
    effect2->setXOffset(0);
    effect2->setYOffset(10);
    effect2->setColor(Qt::black);

    QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect;
    effect3->setBlurRadius(50);
    effect3->setXOffset(0);
    effect3->setYOffset(10);
    effect3->setColor(Qt::black);

    NextButton->setGraphicsEffect(effect1);
    BackButton->setGraphicsEffect(effect2);
    DoneButton->setGraphicsEffect(effect3);

    NextButton->setStyleSheet("font-weight: bold; background-color: #68207a; color: white; font-size: 24px; border-radius: 6px;");
    BackButton->setStyleSheet("font-weight: bold; background-color: gray; color: white; font-size: 24px; border-radius: 6px;");
    DoneButton->setStyleSheet("font-weight: bold; background-color: #2E8B57; color: white; font-size: 24px; border-radius: 6px;");

    PageButton(NextButton, "Next");
    PageButton(BackButton, "Back");
    PageButton(DoneButton, "Done");


    QImageReader reader(ImagePath);
    reader.setAutoTransform(true);
    const QImage Image = reader.read();
    QPixmap BackgroundImage = QPixmap::fromImage(Image);

    PageBackground->setPixmap(BackgroundImage);
    PageBackground->setScaledContents(true);
    PageBackground->resize(QSize(1366,768));
    PageBackground->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    PageBackground->setMaximumSize(QSize(1366,768));

    PageLayout->addWidget(PageBackground, 1,1,2,5,Qt::AlignCenter);
    PageLayout->setSpacing(0);

    switch (PageType) {
        case 1:
            PageLayout->addWidget(NextButton,2,3,1,1,Qt::AlignCenter);
            break;
        case 2:
            PageLayout->addWidget(BackButton,2,2,1,1,Qt::AlignCenter);
            PageLayout->addWidget(NextButton,2,4,1,1,Qt::AlignCenter);
            break;
        case 3:
            PageLayout->addWidget(BackButton,2,2,1,1,Qt::AlignCenter);
            PageLayout->addWidget(DoneButton,2,4,1,1,Qt::AlignCenter);
            break;
    }

    connect(NextButton, &QPushButton::clicked, this, [=](){
        int nextPage = Pages->currentIndex() + 1;
        Pages->setCurrentIndex(nextPage);
    });

    connect(BackButton, &QPushButton::clicked, this, [=](){
        int prevPage = Pages->currentIndex() - 1;
        Pages->setCurrentIndex(prevPage);
    });

    connect(DoneButton, &QPushButton::clicked, this, [=](){
        QApplication::quit();
    });

    PageLayout->setSpacing(0);
    PageLayout->setMargin(0);
    Page->setLayout(PageLayout);

    return  Page;
}

QPushButton *welcome::PageButton(QPushButton *Button, const QString &Name)
{
    Button->setText(Name);
    Button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    Button->setMaximumSize(200,70);
    Button->setMinimumSize(200,70);
    Button->setFocusPolicy(Qt::ClickFocus);
//    Button->setStyleSheet("background-color: green; color: white; font-size: 24px; border-radius: 25px;");
    return Button;
}



welcome::~welcome()
{
}

