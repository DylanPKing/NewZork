#include "Command.h"

/**
 * @brief Command::validCommandWords
 */
QVector <QString> Command::validCommandWords;

/**
 * @brief Command::Command
 * @param commandWord
 * @param secondWord
 */
Command::Command(QString commandWord, QString secondWord) :
    commandWord(commandWord),
    secondWord(secondWord)
{
    isThereCommandWords();
}

/**
 * @brief Command::isValidCommand Checks if entered command is a valid key-word
 * @return true if the command is valid and false if it is not
 */
bool Command::isValidCommand()
{
    return validCommandWords.contains(commandWord);
}

/**
 * @brief Command::hasSecondWord
 * @return
 */
bool Command::hasSecondWord()
{
    return secondWord.compare("") != 0;
}

/**
 * @brief Command::listValidCommands
 * @return
 */
QString Command::listValidCommands()
{
    QString out = "";
    for (QVector <QString>::iterator i = validCommandWords.begin(); i != validCommandWords.end(); ++i)
        out += *i + "\t";
    return out;
}

/**
 * @brief Command::isThereCommandWords
 */
void Command::isThereCommandWords()
{
    if (validCommandWords.size() == 0)
        loadCommandWords();
}

/**
 * @brief Command::loadCommandWords
 */
void Command::loadCommandWords()
{
    validCommandWords.push_back("go");
    validCommandWords.push_back("quit");
    validCommandWords.push_back("info");
    validCommandWords.push_back("map");
    validCommandWords.push_back("take");
    validCommandWords.push_back("put");
    validCommandWords.push_back("teleport");
}
