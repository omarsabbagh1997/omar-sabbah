#include "poubelle.h"

poubelle::poubelle()
{
    id=0;
    diametre=0;
    hauteur=0;
}
poubelle::poubelle(int id,int diametre,int hauteur)
{
  this->id=id;
  this->diametre=diametre;
  this->hauteur=hauteur;
}
int poubelle::get_diametre(){return  diametre;}
int poubelle::get_hauteur(){return hauteur;}
int poubelle::get_id(){return  id;}

bool poubelle::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO POUBELLE (ID, DIAMETRE, HAUTEUR) "
                    "VALUES (:id, :diametre, :hauteur)");
query.bindValue(":id", res);
query.bindValue(":diametre", diametre);
query.bindValue(":hauteur", hauteur);

return    query.exec();
}

QSqlQueryModel * poubelle::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from poubelle");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DIAMETRE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("HAUTEUR"));
    return model;
}

bool poubelle::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from poubelle where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

