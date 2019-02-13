#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QVector>

class Command
{
private:
    QString commandWord;
    QString secondWord;
    static QVector <QString> validCommandWords;
    static void isThereCommandWords();
    static void loadCommandWords();

public:
    Command(QString, QString);
    QString listValidCommands();
    const QString commandWordRef = commandWord;
    const QString secondWordRef = secondWord;
    bool isValidCommand();
    bool hasSecondWord();
};

#endif // COMMAND_H
