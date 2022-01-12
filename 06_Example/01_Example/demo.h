#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSlider>
#include <QScrollBar>
#include <QProgressBar>
#include <QDial>
#include <QLCDNumber>
#include <QRadioButton>
#include <QPushButton>
#include <QTextEdit>

class Demo : public QWidget {
public:
    explicit Demo(QWidget *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

    void sliderColorChanged();

private:
    QGridLayout  *gridLayout;
    QGridLayout  *gLayoutMain;
    QHBoxLayout  *hLayoutTopRight;
    QHBoxLayout  *hLayoutBottom;
    QVBoxLayout  *vLayoutLeftCenter;
    QVBoxLayout  *vLayoutInner;
    QGroupBox    *gBoxTopLeft;
    QGroupBox    *gBoxTopRight;
    QGroupBox    *gBoxLeftCenter;
    QGroupBox    *gBoxBottom;
    QGroupBox    *gBoxInner;
    QLabel       *labelRed;
    QLabel       *labelGreen;
    QLabel       *labelBlue;
    QLabel       *labelAlpha;
    QTextEdit    *textEdit;
    QSlider      *sRed;
    QSlider      *sGreen;
    QSlider      *sBlue;
    QSlider      *sAlpha;
    QSlider      *vSlider;
    QSlider      *hSlider;
    QScrollBar   *vScroll;
    QScrollBar   *hScroll;
    QProgressBar *vProgressBar;
    QProgressBar *hProgressBar;
    QDial        *dial;
    QLCDNumber   *lcdNumber;
    QRadioButton *rButtonDecimal;
    QRadioButton *rButtonBinary;
    QRadioButton *rButtonOctal;
    QRadioButton *rButtonHexadecimal;
    QPushButton  *buttonClose;

private:
    QPalette     palette;
    QColor       color;
};
