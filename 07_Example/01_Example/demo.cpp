#include "demo.h"

Demo::Demo(QWidget *parent) : QWidget(parent) {
    {
        this->gLayoutMain           = new QGridLayout(this);
        this->gLayoutTopLeft        = new QGridLayout();
        this->gLayoutRight          = new QGridLayout();
        this->gLayoutBottomLeft     = new QGridLayout();

        this->gBoxDateTime          = new QGroupBox(QString("Date and Time"), this);
        this->gBoxCalendar          = new QGroupBox(QString("Calendar"), this);
        this->gBoxTimer             = new QGroupBox(QString("Timer"), this);

        this->gLayoutDateTime       = new QGridLayout(this->gBoxDateTime);
        this->gLayoutCalendar       = new QGridLayout(this->gBoxCalendar);
        this->gLayoutTimer          = new QGridLayout(this->gBoxTimer);

        this->labelTime             = new QLabel(QString("Time"), this->gBoxDateTime);
        this->labelDate             = new QLabel(QString("Date"), this->gBoxDateTime);
        this->labelDateTime         = new QLabel(QString("Date and Time"), this->gBoxDateTime);
        this->labelStringDisplay    = new QLabel(QString("Display"), this->gBoxDateTime);

        this->timeEdit              = new QTimeEdit(this->gBoxDateTime);
        this->dateEdit              = new QDateEdit(this->gBoxDateTime);
        this->dateTimeEdit          = new QDateTimeEdit(this->gBoxDateTime);

        this->hSpacer               = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        this->lineEditTime          = new QLineEdit(this->gBoxDateTime);
        this->lineEditDate          = new QLineEdit(this->gBoxDateTime);
        this->lineEditDateTime      = new QLineEdit(this->gBoxDateTime);

        this->buttonCurrentDateTime = new QPushButton(QString("Current date and time"), this->gBoxDateTime);
        this->buttonSetTime         = new QPushButton(QString("Set Time"), this->gBoxDateTime);
        this->buttonSetDate         = new QPushButton(QString("Set Date"), this->gBoxDateTime);
        this->buttonSetDateTime     = new QPushButton(QString("Set Date and Time"), this->gBoxDateTime);

        this->labelSelectedDate     = new QLabel(QString("Selected Date"), this->gBoxCalendar);
        this->lineEditSelectedDate  = new QLineEdit(this->gBoxCalendar);
        this->calendarWidget        = new QCalendarWidget(this->gBoxCalendar);

        this->buttonStart           = new QPushButton(QString("Start"), this->gBoxTimer);
        this->buttonStop            = new QPushButton(QString("Stop"), this->gBoxTimer);
        this->buttonSetPeriod       = new QPushButton(QString("Set Timer"), this->gBoxTimer);

        this->timer                 = new QTimer(this);

        this->labelPeriod           = new QLabel(QString("Period"), this->gBoxTimer);
        this->labelElapsedTime      = new QLabel(this->gBoxTimer);

        this->spinBoxPeriod         = new QSpinBox(this->gBoxTimer);

        this->lcdHours              = new QLCDNumber(this->gBoxTimer);
        this->lcdMinutes            = new QLCDNumber(this->gBoxTimer);
        this->lcdSeconds            = new QLCDNumber(this->gBoxTimer);

        this->progressBar           = new QProgressBar(gBoxTimer);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalsAndSlots();
        Demo::setFont(QFont("Arial", 9, -1, false));
        Demo::setFixedSize(QWidget::sizeHint().width(), QWidget::sizeHint().height());
    }
}

void Demo::setLayout() {
    {
        this->gLayoutTopLeft->addWidget(this->buttonSetDate, 2, 4);
        this->gLayoutTopLeft->addWidget(this->buttonCurrentDateTime, 0, 0, 1, 3);
        this->gLayoutTopLeft->addWidget(this->dateEdit, 2, 1);
        this->gLayoutTopLeft->addWidget(this->timeEdit, 1, 1);
        this->gLayoutTopLeft->addWidget(this->labelDate, 2, 0);
        this->gLayoutTopLeft->addWidget(this->labelDateTime, 3, 0);
        this->gLayoutTopLeft->addWidget(this->buttonSetTime, 1, 4);
        this->gLayoutTopLeft->addWidget(this->lineEditDate, 2, 3);
        this->gLayoutTopLeft->addWidget(this->labelTime, 1, 0);
        this->gLayoutTopLeft->addWidget(this->dateTimeEdit, 3, 1, 1, 2);
        this->gLayoutTopLeft->addItem(this->hSpacer, 1, 2, 2, 1);
        this->gLayoutTopLeft->addWidget(this->buttonSetDateTime, 3, 4);
        this->gLayoutTopLeft->addWidget(this->lineEditTime, 1, 3);
        this->gLayoutTopLeft->addWidget(this->lineEditDateTime, 3, 3);
        this->gLayoutTopLeft->addWidget(this->labelStringDisplay, 0, 3, 1, 2);
    }

    {
        this->gLayoutBottomLeft->addWidget(this->buttonStart, 0, 0);
        this->gLayoutBottomLeft->addWidget(this->buttonStop, 0, 1);
        this->gLayoutBottomLeft->addWidget(this->labelElapsedTime, 0, 2);
        this->gLayoutBottomLeft->addWidget(this->labelPeriod, 1, 0);
        this->gLayoutBottomLeft->addWidget(this->spinBoxPeriod, 1, 1);
        this->gLayoutBottomLeft->addWidget(this->buttonSetPeriod, 1, 2);
        this->gLayoutBottomLeft->addWidget(this->lcdHours, 2, 0);
        this->gLayoutBottomLeft->addWidget(this->lcdMinutes, 2, 1);
        this->gLayoutBottomLeft->addWidget(this->lcdSeconds, 2, 2);
        this->gLayoutBottomLeft->addWidget(this->progressBar, 3, 0, 1, 3);
    }

    {
        this->gLayoutRight->addWidget(this->labelSelectedDate, 0, 0);
        this->gLayoutRight->addWidget(this->lineEditSelectedDate, 0, 1);
        this->gLayoutRight->addWidget(this->calendarWidget, 1, 0, 1, 2);
    }

    {
        this->gLayoutDateTime->addLayout(this->gLayoutTopLeft, 0, 0);
        this->gLayoutCalendar->addLayout(this->gLayoutRight, 0, 0);
        this->gLayoutTimer->addLayout(this->gLayoutBottomLeft, 0, 0);
    }

    {
        this->gLayoutMain->addWidget(this->gBoxDateTime, 0, 0);
        this->gLayoutMain->addWidget(this->gBoxCalendar, 0, 1, 2, 1);
        this->gLayoutMain->addWidget(this->gBoxTimer, 1, 0);
    }
}

void Demo::setProperties() {
    this->spinBoxPeriod->setSuffix(" ms");
    this->spinBoxPeriod->setMaximum(10'000);
    this->spinBoxPeriod->setSingleStep(1'000);
    this->spinBoxPeriod->setValue(1'000);

    this->buttonStop->setEnabled(false);

    this->timer->setInterval(1'000);

    this->lcdHours->display(10);
    this->lcdMinutes->display(26);
    this->lcdSeconds->display(35);

    this->progressBar->setTextVisible(false);
}

void Demo::signalsAndSlots() {
    QObject::connect(this->buttonCurrentDateTime, &QPushButton::clicked, this, [&]() {
        this->timeEdit->setTime(QTime::currentTime());
        this->dateEdit->setDate(QDate::currentDate());
        this->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

        this->lineEditTime->setText(QTime::currentTime().toString("hh:mm:ss"));
        this->lineEditDate->setText(QDate::currentDate().toString("yyyy-MM-dd"));
        this->lineEditDateTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    });

    QObject::connect(this->buttonSetTime, &QPushButton::clicked, this, [&]() {
        this->timeEdit->setTime(QTime::fromString(this->lineEditTime->text(), "hh:mm:ss"));
    });

    QObject::connect(this->buttonSetDate, &QPushButton::clicked, this, [&]() {
        this->dateEdit->setDate(QDate::fromString(this->lineEditDate->text(), "yyyy-MM-dd"));
    });

    QObject::connect(this->buttonSetDateTime, &QPushButton::clicked, this, [&]() {
        this->dateTimeEdit->setDateTime(QDateTime::fromString(this->lineEditDateTime->text(), "yyyy-MM-dd hh:mm:ss"));
    });

    QObject::connect(this->calendarWidget, &QCalendarWidget::selectionChanged, this->lineEditSelectedDate, [&]() {
        QDate date = this->calendarWidget->selectedDate();
        this->lineEditSelectedDate->setText(date.toString("Год: yyyy Месяц: MM День: dd"));
    });

    QObject::connect(this->buttonStart, &QPushButton::clicked, this, [&]() {
        this->timer->start();
        this->buttonStart->setEnabled(false);
        this->buttonStop->setEnabled(true);
        this->buttonSetPeriod->setEnabled(false);
        timeCounter.start();
    });

    QObject::connect(this->buttonStop, &QPushButton::clicked, this, [&]() {
        this->buttonStart->setEnabled(true);
        this->buttonStop->setEnabled(false);
        this->buttonSetPeriod->setEnabled(true);
        timer->stop();

        long long MinSec = timeCounter.elapsed();
        long long sec = MinSec / 1'000;
        long long mSec = MinSec % 1'000;

        QString str = QString::asprintf("Elapsed: %lld sec %lld ms", sec, mSec);
        this->labelElapsedTime->setText(str);
    });

    QObject::connect(this->buttonSetPeriod, &QPushButton::clicked, this, [&]() {
        this->timer->setInterval(this->spinBoxPeriod->value());
    });

    QObject::connect(this->timer, &QTimer::timeout, this, [&]() {
        this->lcdHours->display(QTime::currentTime().hour());
        this->lcdMinutes->display(QTime::currentTime().minute());
        this->lcdSeconds->display(QTime::currentTime().second());

        int value = this->progressBar->value();
        ++value;
        if (value > 100) value = 0;

        this->progressBar->setValue(value);
    });
}

Demo::~Demo() = default;