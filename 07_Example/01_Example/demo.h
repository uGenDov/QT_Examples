#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QDateEdit>
#include <QLabel>
#include <QSpinBox>
#include <QLCDNumber>
#include <QProgressBar>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QTimer>
#include <QElapsedTimer>

class Demo : public QWidget {
public:
    explicit Demo(QWidget *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

private:
    QGridLayout     *gLayoutMain;
    QGridLayout     *gLayoutCalendar;
    QGridLayout     *gLayoutDateTime;
    QGridLayout     *gLayoutTimer;
    QGridLayout     *gLayoutTopLeft;
    QGridLayout     *gLayoutRight;
    QGridLayout     *gLayoutBottomLeft;
    QGroupBox       *gBoxDateTime;
    QGroupBox       *gBoxCalendar;
    QGroupBox       *gBoxTimer;
    QPushButton     *buttonCurrentDateTime;
    QPushButton     *buttonSetDate;
    QPushButton     *buttonSetTime;
    QPushButton     *buttonSetDateTime;
    QPushButton     *buttonStart;
    QPushButton     *buttonStop;
    QPushButton     *buttonSetPeriod;
    QTimeEdit       *timeEdit;
    QDateEdit       *dateEdit;
    QDateTimeEdit   *dateTimeEdit;
    QCalendarWidget *calendarWidget;
    QLabel          *labelStringDisplay;
    QLabel          *labelTime;
    QLabel          *labelDate;
    QLabel          *labelDateTime;
    QLabel          *labelSelectedDate;
    QLabel          *labelElapsedTime;
    QLabel          *labelPeriod;
    QLineEdit       *lineEditTime;
    QLineEdit       *lineEditDate;
    QLineEdit       *lineEditDateTime;
    QLineEdit       *lineEditSelectedDate;
    QSpinBox        *spinBoxPeriod;
    QLCDNumber      *lcdHours;
    QLCDNumber      *lcdMinutes;
    QLCDNumber      *lcdSeconds;
    QProgressBar    *progressBar;
    QSpacerItem     *hSpacer;
    QTimer          *timer;

private:
    QElapsedTimer   timeCounter;
};