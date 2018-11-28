#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "poubelle.h"
#include "lampes.h"
#include "equipements.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:




    void on_ajouter_clicked();





    void on_supprimer_clicked();



    void on_ajouterlampe_clicked();



    void on_supplampes_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_ajouterE_clicked();



    void on_suppE_clicked();

    void on_rechercher_clicked();

private:
    Ui::MainWindow *ui;
    poubelle tmppoubelle;
    lampes tmplampes ;
    equipements tmpequipements ;

};

#endif // MAINWINDOW_H
