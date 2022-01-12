#include <iostream>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QLineEdit>

class Demo : public QWidget {
public:
    explicit Demo(QWidget *parent = nullptr);

    void setProperties();
    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

private:
    QVBoxLayout *vLayout;
    QFormLayout *fLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayoutCenter;
    QGridLayout *gLayout;
    QGridLayout *gLayoutLeft;
    QGridLayout *gLayoutRight;
    QLabel      *labelStr1;
    QComboBox   *comboStr1;
    QLabel      *labelStr2;
    QComboBox   *comboStr2;
    QGroupBox   *gBoxLeft;
    QPushButton *buttonAppend;
    QPushButton *buttonPrepend;
    QPushButton *buttonToUpper;
    QPushButton *buttonToLower;
    QPushButton *buttonLeft;
    QPushButton *buttonRight;
    QPushButton *buttonSection;
    QPushButton *buttonSimplified;
    QPushButton *buttonTrimmed;
    QGroupBox   *gBoxCenter;
    QPushButton *buttonCount;
    QPushButton *buttonSize;
    QPushButton *buttonIndexOf;
    QPushButton *buttonLastIndexOf;
    QGroupBox   *gBoxRight;
    QPushButton *buttonEndsWith;
    QPushButton *buttonStartsWith;
    QPushButton *buttonContains;
    QPushButton *buttonIsNull;
    QPushButton *buttonIsEmpty;
    QLabel      *labelResult;
    QCheckBox   *checkBox;
    QLabel      *labelSpin;
    QLineEdit   *lineEdit;
    QSpinBox    *spinBox;
};