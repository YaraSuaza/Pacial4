#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    h_limit=2000;                   //Asigna los valores leidos el archivo
    v_limit=1000;
    dt=1;                            //Asigna el lapso de tiempo
    ui->setupUi(this);
    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
            qDebug()<<ui->graphicsView->size();
    ui->centralwidget->adjustSize();
            qDebug()<<ui->centralwidget->size();

    timer->stop();                              //para el timer
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    bars.append(new cuerpograf(300,100,-0.6,0.2,25,100));
    for(int i=0;i<bars.size();i++){
        bars.at(i)->actualizar(dt);
        scene->addItem(bars.at(i));}
}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;

}
void MainWindow::actualizar()//se actualiza la posicion
{
    for (int i=0; i<bars.size();i++){
        for(int j=0; j<bars.size();j++){
            if(i!=j){
                bars.at(i) -> getEsf() -> acelerar(bars.at(j)->getEsf()->getX(),bars.at(j)->getEsf()->getY(),bars.at(j)->getEsf()->get_mass());
            }
        }
    }
    for(int i=0;i<bars.size();i++){
        bars.at(i)->actualizar(dt);

    }
}


void MainWindow::on_iniciar_clicked()
{
     timer->start(dt);
}
