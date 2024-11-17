#ifndef TRIMSPACES_H
#define TRIMSPACES_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QPushButton;

class TrimSpaces : public QWidget
{
    Q_OBJECT

public:
    explicit TrimSpaces(QWidget *parent = nullptr);
    ~TrimSpaces();

private slots:
    void on_trimSpaces();

private:
    QLineEdit* m_pInputField;
    QLabel* m_pOriginalLabel;
    QLabel* m_pResultLabel;
    QPushButton* m_pTrimButton;

    void trimRight(char* str);
};
#endif // TRIMSPACES_H
