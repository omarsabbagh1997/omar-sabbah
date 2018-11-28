#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "poubelle.h"
#include "lampes.h"
#include "QtDebug"

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablepoubelle->setModel(tmppoubelle.afficher());
    ui->tablelampes->setModel(tmplampes.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}









void MainWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    int diametre= ui->lineEdit_diametre->text().toInt();
       int hauteur= ui->lineEdit_hauteur->text().toInt();

     poubelle p(id,diametre,hauteur);
     bool test=p.ajouter();
     if(test)
   {ui->tablepoubelle->setModel(tmppoubelle.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter une poubelle"),
                     QObject::tr("poubelle ajoutée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une poubelle"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_supprimer_clicked()
{
    int id = ui->lineEdit_ID_2->text().toInt();
    bool test=tmppoubelle.supprimer(id);
    if(test)
    {ui->tablepoubelle->setModel(tmppoubelle.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une poubelle"),
                    QObject::tr("poubelle supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une poubelle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_ajouterlampe_clicked()
{
    int numero = ui->lineEdit_numero_3->text().toInt();
    QString type= ui->lineEdit_type->text();


     lampes l(numero,type);
     bool test=l.ajouter();
     if(test)
   {ui->tablelampes->setModel(tmplampes.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter une lampe"),
                     QObject::tr("lampe ajoutée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une lampe"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_supplampes_clicked()
{
    int numero = ui->lineEdit_numero->text().toInt();
    bool test=tmplampes.supprimer(numero);
    if(test)
    {ui->tablelampes->setModel(tmplampes.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une lampe"),
                    QObject::tr("lampe supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une lampe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tabWidget_3_currentChanged(int )
{
    ui->tablelampes->setModel(tmplampes.afficher());//refresh
}

void MainWindow::on_ajouterE_clicked()
{
    int numero = ui->lineEdit_numeroequip->text().toInt();
    QString type= ui->lineEdit_typeE->text();


     equipements E(numero,type);
     bool test=E.ajouter();
     if(test)
   {ui->tableView_3->setModel(tmpequipements.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                     QObject::tr("equipement ajoutée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_suppE_clicked()
{
    int numero = ui->lineEdit_numero_4->text().toInt();
    bool test=tmpequipements.supprimer(numero);
    if(test)
    {ui->tableView_3->setModel(tmpequipements.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un equipements"),
                    QObject::tr("lampe supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_rechercher_clicked()
{

        int numero;

        numero=ui->linerechercher->text().toInt();
        QSqlQueryModel *model=new QSqlQueryModel();
        QSqlQuery* query=new QSqlQuery();
        query->prepare("Select * from equipements where numero=:numero ");
        query->bindValue(":numero",numero);
       // ui->tableEtudiant->setModel(model);
        query->exec();
        model->setQuery(*query);

        qDebug()<<(model->rowCount());
       if( (model->rowCount()==0))
        QMessageBox::information(nullptr, QObject::tr("Rechercher un Etudiant "),
                    QObject::tr(" L etudiant n existe pas .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


      else
        QMessageBox::information(nullptr, QObject::tr("Rechercher un etudiant "),
                    QObject::tr(" L'etudiant existe .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel)


       ;
    }

