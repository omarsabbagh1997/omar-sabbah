#include "equipements.h"

equipements::equipements()
{
    numero=0;
    type="";
}
equipements::equipements(int numero,QString type)
{
  this->numero=numero;
  this->type=type;

}
int equipements::get_numero(){return  numero;}
QString equipements::get_type(){return type;}


bool equipements::ajouter()
{
QSqlQuery query;
QString res1= QString::number(numero);
query.prepare("INSERT INTO EQUIPEMENTS (NUMERO,TYPE) "
                    "VALUES (:numero, :type)");
query.bindValue(":numero", res1);
query.bindValue(":type", type);


return    query.exec();
}

QSqlQueryModel * equipements::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from equipements");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));

    return model;
}

bool equipements::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from EQUIPEMENTS where NUMERO = :numero ");
query.bindValue(":numero", res);
return    query.exec();
}
