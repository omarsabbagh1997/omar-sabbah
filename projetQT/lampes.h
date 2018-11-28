#ifndef LAMPES_H
#define LAMPES_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class lampes
{
public:
    lampes();
    lampes(int,QString);
        int get_numero();
        QString get_type();


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
    private:
        int numero;
        QString type ;
};

#endif // LAMPES_H
