#include "trimspaces.h"
#include "ui_trimspaces.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

TrimSpaces::TrimSpaces(QWidget *parent)
    : QWidget(parent)
{
    m_pInputField = new QLineEdit(this);
    m_pTrimButton = new QPushButton("Trim Spaces", this);
    m_pOriginalLabel = new QLabel("Original string with spaces will appear here", this);
    m_pResultLabel = new QLabel("Result will be show here", this);

    // Создаем макет
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Enter a string with trailing spaces:", this));
    layout->addWidget(m_pInputField);
    layout->addWidget(m_pTrimButton);
    layout->addWidget(new QLabel("Original string (spaces highlighted):", this));
    layout->addWidget(m_pOriginalLabel);
    layout->addWidget(new QLabel("Result:", this));
    layout->addWidget(m_pResultLabel);

    // Подключаем кнопку и функции
    connect(m_pTrimButton, &QPushButton::clicked, this, &TrimSpaces::on_trimSpaces);
}

TrimSpaces::~TrimSpaces() {}

void TrimSpaces::on_trimSpaces()
{
    QString input = m_pInputField->text(); // Получаем строку из текстового поля
    QByteArray byteArray = input.toUtf8(); // Преобразуем в UTF-8
    char* cString = byteArray.data(); // Получаем C-строку

     // Сохраняем строку с пробелами для отображения
    QString originalWithSpaces = input;
    originalWithSpaces.replace(" ", "<span style='background-color: red;'>&nbsp;</span>"); // Подсвечиваем пробелы

    trimRight(cString); // Вызываем функцию обрезки пробелов

    m_pOriginalLabel->setText("<html>" + originalWithSpaces + "</html>"); // Выделяем пробелы
    m_pResultLabel->setText(QString::fromUtf8(cString)); // Отображаем результат
}

void TrimSpaces::trimRight(char *str)
{
    if (!str) return;

    char* end = str;
    while (*end != '\0') {
        ++end;
    }

    while (end > str && *(end - 1) == ' ') {
        --end;
    }

    *end = '\0';
}

