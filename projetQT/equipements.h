#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class equipements
{
public:
    equipements();
    equipements(int,QString);
        int get_numero();
        QString get_type();


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
    private:
        int numero;
        QString type ;
};

#endif // EQUIPEMENTS_H
