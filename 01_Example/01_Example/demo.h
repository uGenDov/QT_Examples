#include <QDialog>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>

class Demo : public QDialog {
public:
    explicit Demo(QDialog *parent = nullptr);

    ~Demo() override;

public:
    void setLayout();

    void setProperties();

public slots:
    void signalsAndSlots();

private:
    QVBoxLayout    *vLayout;
    QHBoxLayout    *hLayoutFirst;
    QHBoxLayout    *hLayoutSecond;
    QHBoxLayout    *hLayoutThird;
    QGroupBox      *gBoxFirst;
    QGroupBox      *gBoxSecond;
    QCheckBox      *cBoxUnderline;
    QCheckBox      *cBoxItalic;
    QCheckBox      *cBoxBold;
    QRadioButton   *rButtonBlack;
    QRadioButton   *rButtonBlue;
    QRadioButton   *rButtonRed;
    QPlainTextEdit *plainText;
    QPushButton    *buttonAccept;
    QPushButton    *buttonCancel;
    QPushButton    *buttonClose;
    QFrame         *line;
    QSpacerItem    *spacer;

private:
    QFont          myFont;
    QPalette       myPalette;
};
