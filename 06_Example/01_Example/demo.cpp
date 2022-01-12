#include "demo.h"

Demo::Demo(QWidget *parent) : QWidget(parent){
    {
        this->gLayoutMain        = new QGridLayout(this);

        this->gBoxTopLeft        = new QGroupBox(QString("Slider and Color"), this);
        this->gBoxTopRight       = new QGroupBox(QString("Vertical"), this);
        this->gBoxLeftCenter     = new QGroupBox(QString("Horizontal"), this);
        this->gBoxBottom         = new QGroupBox(QString("Dial and LCDNumber"), this);
        this->gBoxInner          = new QGroupBox(QString("LCD display base"), this->gBoxBottom);

        this->buttonClose        = new QPushButton(QIcon("D:/images/exit.png"), QString("Close"),  this);

        this->gridLayout         = new QGridLayout(this->gBoxTopLeft);
        this->hLayoutTopRight    = new QHBoxLayout(this->gBoxTopRight);
        this->vLayoutLeftCenter  = new QVBoxLayout(this->gBoxLeftCenter);
        this->hLayoutBottom      = new QHBoxLayout(this->gBoxBottom);
        this->vLayoutInner       = new QVBoxLayout(this->gBoxInner);

        this->labelRed           = new QLabel(QString("Red"), this->gBoxTopLeft);
        this->labelGreen         = new QLabel(QString("Green"), this->gBoxTopLeft);
        this->labelBlue          = new QLabel(QString("Blue"), this->gBoxTopLeft);
        this->labelAlpha         = new QLabel(QString("Alpha"), this->gBoxTopLeft);

        this->sRed               = new QSlider(this->gBoxTopLeft);
        this->sGreen             = new QSlider(this->gBoxTopLeft);
        this->sBlue              = new QSlider(this->gBoxTopLeft);
        this->sAlpha             = new QSlider(this->gBoxTopLeft);

        this->textEdit           = new QTextEdit(this->gBoxTopLeft);

        this->vSlider            = new QSlider(this->gBoxTopRight);
        this->hSlider            = new QSlider(this->gBoxLeftCenter);

        this->vScroll            = new QScrollBar(this->gBoxTopRight);
        this->hScroll            = new QScrollBar(this->gBoxLeftCenter);

        this->vProgressBar       = new QProgressBar(this->gBoxTopRight);
        this->hProgressBar       = new QProgressBar(this->gBoxLeftCenter);

        this->dial               = new QDial(this->gBoxBottom);
        this->lcdNumber          = new QLCDNumber(this->gBoxBottom);

        this->rButtonDecimal     = new QRadioButton(QString("Decimal"), this->gBoxInner);
        this->rButtonBinary      = new QRadioButton(QString("Binary"), this->gBoxInner);
        this->rButtonOctal       = new QRadioButton(QString("Octal"), this->gBoxInner);
        this->rButtonHexadecimal = new QRadioButton(QString("Hexadecimal"), this->gBoxInner);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalsAndSlots();
        Demo::setFont(QFont("Arial", 9, -1, false));
        Demo::setFixedSize(QWidget::sizeHint().width(), QWidget::sizeHint().height());
    }
}

void Demo::setProperties() {
    {
        this->sRed->setOrientation(Qt::Horizontal);
        this->sGreen->setOrientation(Qt::Horizontal);
        this->sBlue->setOrientation(Qt::Horizontal);
        this->sAlpha->setOrientation(Qt::Horizontal);

        this->textEdit->setMaximumSize(QSize(100, 100));
        this->textEdit->setFrameShape(QFrame::NoFrame);
        this->textEdit->setReadOnly(true);

        this->vSlider->setMaximum(100);
        this->vSlider->setSliderPosition(35);
        this->vSlider->setTracking(true);
        this->vSlider->setOrientation(Qt::Vertical);
        this->vSlider->setTickPosition(QSlider::TicksAbove);

        this->vScroll->setOrientation(Qt::Vertical);
        this->hScroll->setOrientation(Qt::Horizontal);
        this->hScroll->setInvertedAppearance(true);
        this->vScroll->setValue(35);
        this->hScroll->setValue(70);

        this->vProgressBar->setOrientation(Qt::Vertical);
        this->vProgressBar->setValue(35);
        this->hProgressBar->setValue(70);
        this->hProgressBar->setTextVisible(false);

        this->hSlider->setMaximum(100);
        this->hSlider->setOrientation(Qt::Horizontal);
        this->hSlider->setTickPosition(QSlider::TicksAbove);
        this->hSlider->setSliderPosition(70);
    }
}

void Demo::setLayout() {
    {
        this->gridLayout->addWidget(this->labelRed, 0, 0);
        this->gridLayout->addWidget(this->labelGreen, 1, 0);
        this->gridLayout->addWidget(this->labelBlue, 2, 0);
        this->gridLayout->addWidget(this->labelAlpha, 3, 0);
        this->gridLayout->addWidget(this->sRed, 0, 1);
        this->gridLayout->addWidget(this->sGreen, 1, 1);
        this->gridLayout->addWidget(this->sBlue, 2, 1);
        this->gridLayout->addWidget(this->sAlpha, 3, 1);
        this->gridLayout->addWidget(this->textEdit, 0, 2, 4, 1);
    }

    {
        this->hLayoutTopRight->addWidget(this->vSlider);
        this->hLayoutTopRight->addWidget(this->vScroll);
        this->hLayoutTopRight->addWidget(this->vProgressBar);
    }

    {
        this->vLayoutLeftCenter->addWidget(this->hSlider);
        this->vLayoutLeftCenter->addWidget(this->hScroll);
        this->vLayoutLeftCenter->addWidget(this->hProgressBar);
    }

    {
        this->hLayoutBottom->addWidget(this->dial);
        this->hLayoutBottom->addWidget(this->lcdNumber);
        this->vLayoutInner->addWidget(this->rButtonDecimal);
        this->vLayoutInner->addWidget(this->rButtonBinary);
        this->vLayoutInner->addWidget(this->rButtonOctal);
        this->vLayoutInner->addWidget(this->rButtonHexadecimal);
        this->hLayoutBottom->addWidget(this->gBoxInner);
    }

    {
        this->gLayoutMain->addWidget(this->gBoxTopLeft, 0, 0);
        this->gLayoutMain->addWidget(this->gBoxTopRight, 0, 1, 2, 1);
        this->gLayoutMain->addWidget(this->gBoxLeftCenter, 1, 0); //
        this->gLayoutMain->addWidget(this->gBoxBottom, 2, 0, 1, 2);
        this->gLayoutMain->addWidget(this->buttonClose, 3, 0, 1, 2);
    }
}

void Demo::signalsAndSlots() {
    QObject::connect(this->buttonClose, &QPushButton::clicked, this, &Demo::close);

    QObject::connect(this->sRed, &QSlider::valueChanged, this, &Demo::sliderColorChanged);
    QObject::connect(this->sGreen, &QSlider::valueChanged, this, &Demo::sliderColorChanged);
    QObject::connect(this->sBlue, &QSlider::valueChanged, this, &Demo::sliderColorChanged);
    QObject::connect(this->sAlpha, &QSlider::valueChanged, this, &Demo::sliderColorChanged);

    QObject::connect(this->vSlider, &QSlider::valueChanged, this, [&](int value) {
        this->vProgressBar->setValue(value);
        this->vScroll->setValue(value);
    });

    QObject::connect(this->vScroll, &QScrollBar::valueChanged, this, [&](int value) {
        this->vSlider->setValue(value);
        this->vProgressBar->setValue(value);
    });

    QObject::connect(this->hSlider, &QSlider::valueChanged, this, [&](int value) {
        this->hProgressBar->setValue(value);
        this->hScroll->setValue(value);
    });

    QObject::connect(this->hScroll, &QScrollBar::valueChanged, this, [&](int value) {
        this->hSlider->setValue(value);
        this->hProgressBar->setValue(value);
    });

    QObject::connect(this->dial, &QDial::valueChanged, this, [&](int value) {
        this->lcdNumber->display(value);
    });

    QObject::connect(this->rButtonDecimal, &QRadioButton::clicked, this->lcdNumber, [&]() {
        this->lcdNumber->setDecMode();
    });

    QObject::connect(this->rButtonBinary, &QRadioButton::clicked, this->lcdNumber, [&]() {
        this->lcdNumber->setDigitCount(8);
        this->lcdNumber->setBinMode();
    });

    QObject::connect(this->rButtonOctal, &QRadioButton::clicked, this->lcdNumber, [&]() {
        this->lcdNumber->setOctMode();
    });

    QObject::connect(this->rButtonHexadecimal, &QRadioButton::clicked, this->lcdNumber, [&]() {
        this->lcdNumber->setDigitCount(3);
        this->lcdNumber->setHexMode();
    });
}

void Demo::sliderColorChanged() {
    palette = this->textEdit->palette();
    color.setRgb(this->sRed->value(), this->sGreen->value(), this->sBlue->value(), this->sAlpha->value());
    palette.setColor(QPalette::Base, color);
    this->textEdit->setPalette(palette);
}

Demo::~Demo() = default;