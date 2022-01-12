#include "demo.h"

Demo::Demo(QDialog *parent) : QDialog(parent) {
    {
        this->vLayout       = new QVBoxLayout(this);

        this->gBoxFirst     = new QGroupBox(this);
        this->gBoxSecond    = new QGroupBox(this);

        this->hLayoutSecond = new QHBoxLayout(this->gBoxSecond);
        this->hLayoutFirst  = new QHBoxLayout(this->gBoxFirst);
        this->hLayoutThird  = new QHBoxLayout();

        this->cBoxUnderline = new QCheckBox(QString("Underline"), this->gBoxFirst);
        this->cBoxItalic    = new QCheckBox(QString("Italic"), this->gBoxFirst);
        this->cBoxBold      = new QCheckBox(QString("Bold"), this->gBoxFirst);

        this->rButtonBlack  = new QRadioButton(QString("Black"), this->gBoxSecond);
        this->rButtonBlue   = new QRadioButton(QString("Blue"), this->gBoxSecond);
        this->rButtonRed    = new QRadioButton(QString("Red"), this->gBoxSecond);

        this->plainText     = new QPlainTextEdit(this);

        this->line          = new QFrame(this);
        this->spacer        = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        this->buttonAccept  = new QPushButton(QString("Accept"), this);
        this->buttonCancel  = new QPushButton(QString("Cancel"), this);
        this->buttonClose   = new QPushButton(QString("Close"), this);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalsAndSlots();
        Demo::setFont(QFont("Arial", 9, -1, false));
        Demo::setFixedSize(QDialog::sizeHint().width(), QDialog::sizeHint().height());
    }
}

void Demo::setLayout() {
    {
        this->hLayoutFirst->addWidget(this->cBoxUnderline);
        this->hLayoutFirst->addWidget(this->cBoxItalic);
        this->hLayoutFirst->addWidget(this->cBoxBold);
    }

    {
        this->hLayoutSecond->addWidget(this->rButtonBlack);
        this->hLayoutSecond->addWidget(this->rButtonBlue);
        this->hLayoutSecond->addWidget(this->rButtonRed);
    }

    {
        this->hLayoutThird->addWidget(this->buttonAccept);
        this->hLayoutThird->addItem(this->spacer);
        this->hLayoutThird->addWidget(this->buttonCancel);
        this->hLayoutThird->addWidget(this->buttonClose);
    }

    {
        this->vLayout->addWidget(this->gBoxFirst);
        this->vLayout->addWidget(this->gBoxSecond);
        this->vLayout->addWidget(this->plainText);
        this->vLayout->addWidget(this->line);
        this->vLayout->addLayout(this->hLayoutThird);
    }
}

void Demo::setProperties() {
    this->line->setFrameShape(QFrame::HLine);
    this->line->setFrameShadow(QFrame::Sunken);
    this->plainText->setPlainText(QString("Hello QT\nHow are you?"));
}

void Demo::signalsAndSlots() {
    QObject::connect(this->buttonAccept, &QPushButton::clicked, this, [&]() { Demo::accept(); });
    QObject::connect(this->buttonCancel, &QPushButton::clicked, this, [&]() { Demo::reject(); });
    QObject::connect(this->buttonClose, &QPushButton::clicked, this, [&]() { Demo::close(); });

    QObject::connect(this->cBoxUnderline, &QCheckBox::stateChanged, this->plainText, [&]() {
        myFont.setUnderline(this->cBoxUnderline->isChecked());
        this->plainText->setFont(myFont);
    });

    QObject::connect(this->cBoxItalic, &QCheckBox::stateChanged, this->plainText, [&]() {
        myFont.setItalic(this->cBoxItalic->isChecked());
        this->plainText->setFont(myFont);
    });

    QObject::connect(this->cBoxBold, &QCheckBox::stateChanged, this->plainText, [&]() {
        myFont.setBold(this->cBoxBold->isChecked());
        this->plainText->setFont(myFont);
    });

    QObject::connect(this->rButtonBlack, &QRadioButton::clicked, this->plainText, [&]() {
        myPalette.setColor(QPalette::Text, Qt::black);
        this->plainText->setPalette(myPalette);
    });

    QObject::connect(this->rButtonBlue, &QRadioButton::clicked, this->plainText, [&]() {
        myPalette.setColor(QPalette::Text, Qt::blue);
        this->plainText->setPalette(myPalette);
    });

    QObject::connect(this->rButtonRed, &QRadioButton::clicked, this->plainText, [&]() {
        myPalette.setColor(QPalette::Text, Qt::red);
        this->plainText->setPalette(myPalette);
    });
}

Demo::~Demo() = default;