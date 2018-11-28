#include "lampes.h"

lampes::lampes()
{
    numero=0;
    type="";
}
lampes::lampes(int numero,QString type)
{
  this->numero=numero;
  this->type=type;

}
int lampes::get_numero(){return  numero;}
QString lampes::get_type(){return type;}


bool lampes::ajouter()
{
QSqlQuery query;
QString res1= QString::number(numero);
query.prepare("INSERT INTO lAMPES (NUMERO,TYPE) "
                    "VALUES (:numero, :type)");
query.bindValue(":numero", res1);
query.bindValue(":type", type);


return    query.exec();
}

QSqlQueryModel * lampes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from lampes");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));

    return model;
}

bool lampes::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from LAMPES where NUMERO = :numero ");
query.bindValue(":numero", res);
return    query.exec();
}

