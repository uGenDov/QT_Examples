#include <QMainWindow>

class Demo : public QMainWindow {
public:
    explicit Demo(QMainWindow *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

private:

};