#ifndef POUBELLE_H
#define POUBELLE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class poubelle
{
public:
    poubelle();
    poubelle(int,int,int);
        int get_hauteur();
        int get_diametre();
        int get_id();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
    private:
        int diametre,hauteur;
        int id;
};

#endif // POUBELLE_H
