#ifndef JAPKAT_H
#define JAPKAT_H

#include <QObject>
#include "edict2.h"

class JapKat : public QObject
{
    Q_OBJECT
public:
    explicit JapKat(QObject *parent = 0);

    void doConj(QString verb);

    //Functions related to conjugation
    QString basicConjugation(QString verb, EdictType type);
    QString complexConjugation(QString verb, EdictType type);
    QString getCForm(CForm cform);
    QString getKForm(KForm kform, bool desc = false);
    QString dataFolder;

signals:

public slots:

};

#endif // JAPKAT_H
