#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

class Demo : public QWidget {
public:
    explicit Demo(QWidget *parent = nullptr);

    void setLayout();

    void setProperties();

    ~Demo() override;

public slots:
    void signalsAndSlots();

private:
    QVBoxLayout    *verticalLayout;
    QGridLayout    *gLayoutTop;
    QGridLayout    *gLayoutBottom;
    QLabel         *labelNumber;
    QLabel         *labelUnit;
    QLabel         *labelTotal;
    QLabel         *labelDec;
    QLabel         *labelBin;
    QLabel         *labelHex;
    QSpinBox       *spinBoxNumber;
    QSpinBox       *spinBoxDec;
    QSpinBox       *spinBoxBin;
    QSpinBox       *spinBoxHex;
    QDoubleSpinBox *dSpinBoxUnit;
    QDoubleSpinBox *dSpinBoxTotal;
    QPushButton    *buttonCalculate;
    QPushButton    *buttonDec;
    QPushButton    *buttonBin;
    QPushButton    *buttonHex;
    QSpacerItem    *vSpacer;
};