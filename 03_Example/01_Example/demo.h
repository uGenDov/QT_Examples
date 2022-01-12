#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Demo : public QWidget {
public:
    explicit Demo(QWidget *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalAndSlots();

private:
    QVBoxLayout *vLayout;
    QGridLayout *gLayoutTop;
    QGridLayout *gLayoutBottom;
    QLabel      *labelNumber;
    QLabel      *labelUnit;
    QLabel      *labelTotal;
    QLabel      *labelDec;
    QLabel      *labelBin;
    QLabel      *labelHex;
    QLineEdit   *lineEditNumber;
    QLineEdit   *lineEditUnit;
    QLineEdit   *lineEditTotal;
    QLineEdit   *lineEditDec;
    QLineEdit   *lineEditBin;
    QLineEdit   *lineEditHex;
    QPushButton *buttonCalculate;
    QPushButton *buttonDec;
    QPushButton *buttonBin;
    QPushButton *buttonHex;
    QSpacerItem *vSpacer;
};