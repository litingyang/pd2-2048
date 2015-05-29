#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->pushButton->hide();
    ui->label_19->hide();
    ui->continue_2->hide();
    this->score=0;
    ui->label_18->setNum(score);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    this->setWindowTitle("2048");
    this->qvec.resize(16);
    this->array.resize(16);
    this->qvec[0]=(ui->label);
    qvec[1]=(ui->label_2);
    qvec[2]=(ui->label_3);
    qvec[3]=(ui->label_4);
    qvec[4]=(ui->label_5);
    qvec[5]=(ui->label_6);
    qvec[6]=(ui->label_7);
    qvec[7]=(ui->label_8);
    qvec[8]=(ui->label_9);
    qvec[9]=(ui->label_10);
    qvec[10]=(ui->label_11);
    qvec[11]=(ui->label_12);
    qvec[12]=(ui->label_13);
    qvec[13]=(ui->label_14);
    qvec[14]=(ui->label_15);
    qvec[15]=(ui->label_16);
    int i;
    for(i=0;i<16;i++){
        array[i]=0;
    }
    int a=qrand()%16;
    int b=qrand()%16;
    while(b==a)b=qrand()%16;
    array[a]=2;
    array[b]=2;
    for(i=0;i<16;i++){
        if(array[i]==0)
            qvec.at(i)->setText("");
        else
        qvec.at(i)->setNum(array[i]);
        qvec.at(i)->setStyleSheet("QLabel{background-color: lightblue;}");
        qvec.at(i)->setAlignment(Qt::AlignCenter);
        qvec.at(i)->setGeometry(90+110*(i%4),130+110*(i/4),100,100);
        qvec.at(i)->setFont(QFont("algerian",25,QFont::Bold));

    }
    for(int f=0;f<16;f++){
        if(array[f]==0)qvec[f]->setPixmap(QPixmap(":/0.png"));
         if(array[f]==2)qvec[f]->setPixmap(QPixmap(":/2.png"));
         if(array[f]==4)qvec[f]->setPixmap(QPixmap(":/4.png"));
         if(array[f]==8)qvec[f]->setPixmap(QPixmap(":/8.png"));
         if(array[f]==16)qvec[f]->setPixmap(QPixmap(":/16.png"));
         if(array[f]==32)qvec[f]->setPixmap(QPixmap(":/32.png"));
         if(array[f]==64)qvec[f]->setPixmap(QPixmap(":/64.png"));
          if(array[f]==128)qvec[f]->setPixmap(QPixmap(":/128.png"));
           if(array[f]==256)qvec[f]->setPixmap(QPixmap(":/256.png"));
            if(array[f]==512)qvec[f]->setPixmap(QPixmap(":/512.png"));
             if(array[f]==1024)qvec[f]->setPixmap(QPixmap(":/1024.png"));
              if(array[f]==2048)qvec[f]->setPixmap(QPixmap(":/2048.png"));
    }
    one=array;
    carr=array;
    undoscore=score;
    undo=one;
    ui->pushButton_3->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    static int i,j,k;

    int a=qrand()%16;
      one=array;
      last=score;

    switch(event->key()){
        case Qt::Key_W:{
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j>0&&array[i+4*(j-1)]==0){
                    for(k=0;k<j;k++){
                        if(array[i+4*(j-k-1)]==0){
                            array[i+4*(j-k-1)]=array[i+4*(j-k)];
                            array[i+4*(j-k)]=0;
                        }
                    }
                }
            }
        }
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j>0&&array[i+4*(j-1)]==array[i+4*j]){
                    array[i+4*(j-1)]=array[i+4*(j-1)]+array[i+4*j];
                    array[i+4*j]=0;
                    score=score+array[i+4*(j-1)];
                    ui->label_18->setNum(score);
                }
            }
        }

        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j>0&&array[i+4*(j-1)]==0){
                    array[i+4*(j-1)]=array[i+4*j];
                    array[i+4*j]=0;
                }
            }
        }

        for(i=0;i<16;i++){
            if(array[i]==0)
                qvec.at(i)->setText("");
            else
            qvec.at(i)->setNum(array[i]);
            k=array[i];
            j=0;
            while(k>10){
                k=k/10;
                j=j+1;
            }
            qvec.at(i)->setFont(QFont("algerian",25-j*3,QFont::Bold));
        }
            if(array!=carr){

                ui->pushButton_3->setEnabled(true);
                while(array[a]!=0)
                    a=qrand()%16;
                if(array[a]==0)
                {
                array[a]=2;
                undoscore=last;
                undo=one;
                }
                qvec.at(a)->setNum(array[a]);
            }
            break;


        }

        case Qt::Key_S:{

        for(i=0;i<4;i++){
            for(j=3;j>=0;j--){
                if(j>0&&array[i+4*(j)]==0){
                    for(k=0;k<4-j;k++){
                        if(array[i+4*(j+k)]==0){
                            array[i+4*(j+k)]=array[i+4*(j+k-1)];
                            array[i+4*(j+k-1)]=0;
                        }
                    }
                }
            }
        }
        for(i=0;i<4;i++){
            for(j=3;j>0;j--){
                if(array[i+4*(j-1)]==array[i+4*j]){
                    array[i+4*(j)]=array[i+4*(j-1)]+array[i+4*j];
                    array[i+4*(j-1)]=0;
                    score=score+array[i+4*(j)];
                    ui->label_18->setNum(score);
                }
            }
        }

        for(i=0;i<4;i++){
            for(j=3;j>=0;j--){
                if(j>0&&array[i+4*(j)]==0){
                    array[i+4*(j)]=array[i+4*(j-1)];
                    array[i+4*(j-1)]=0;
                }
            }
        }

        for(i=0;i<16;i++){
            if(array[i]==0)
                qvec.at(i)->setText("");
            else
            qvec.at(i)->setNum(array[i]);
            k=array[i];
            j=0;
            while(k>10){
                k=k/10;
                j=j+1;
            }
            qvec.at(i)->setFont(QFont("algerian",25-3*j,QFont::Bold));
        }
            if(array!=carr){
                ui->pushButton_3->setEnabled(true);
                while(array[a]!=0)
                    a=qrand()%16;
                if(array[a]==0)
                {
                array[a]=2;
                undoscore=last;
                undo=one;
                }
                qvec.at(a)->setNum(array[a]);
            }
            break;
        }

        case Qt::Key_A:{
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j>0&&array[4*i+(j-1)]==0){
                    for(k=0;k<j;k++){
                        if(array[4*i+(j-k-1)]==0){
                            array[4*i+(j-k-1)]=array[4*i+(j-k)];
                            array[4*i+(j-k)]=0;
                        }
                    }
                }
            }
        }
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j>0&&array[4*i+(j-1)]==array[4*i+j]){
                    array[4*i+(j-1)]=array[4*i+(j-1)]+array[4*i+j];
                    array[4*i+j]=0;
                    score=score+array[4*i+(j-1)];
                    ui->label_18->setNum(score);
                }
            }
        }

        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j>0&&array[4*i+(j-1)]==0){
                    array[4*i+(j-1)]=array[4*i+j];
                    array[4*i+j]=0;
                }
            }
        }

        for(i=0;i<16;i++){
            if(array[i]==0)
                qvec.at(i)->setText("");
            else
            qvec.at(i)->setNum(array[i]);
            k=array[i];
            j=0;
            while(k>10){
                k=k/10;
                j=j+1;
            }
            qvec.at(i)->setFont(QFont("algerian",25-3*j,QFont::Bold));
        }
            if(array!=carr){
                ui->pushButton_3->setEnabled(true);
                while(array[a]!=0)
                    a=qrand()%16;
                if(array[a]==0)
                {
                array[a]=2;
                undoscore=last;
                undo=one;
                }
                qvec.at(a)->setNum(array[a]);
            }
        break;
    }
    case Qt::Key_D:{
        for(i=0;i<4;i++){
            for(j=3;j>0;j--){
                if(j>0&&array[4*i+(j)]==0){
                    for(k=0;k<4-j;k++){
                        if(array[4*i+(j+k)]==0){
                            array[4*i+(j+k)]=array[4*i+(j+k-1)];
                            array[4*i+(j+k-1)]=0;
                        }
                    }
                }
            }
        }
        for(i=0;i<4;i++){
            for(j=3;j>0;j--){
                if(array[4*i+(j-1)]==array[4*i+j]){
                    array[4*i+(j)]=array[4*i+(j-1)]+array[4*i+j];
                    array[4*i+(j-1)]=0;
                    score=score+array[4*i+(j)];
                    ui->label_18->setNum(score);
                }
            }
        }

        for(i=0;i<4;i++){
            for(j=3;j>=0;j--){
                if(j>0&&array[4*i+(j)]==0){
                    array[4*i+(j)]=array[4*i+(j-1)];
                    array[4*i+(j-1)]=0;
                }
            }
        }

            for(i=0;i<16;i++){
                if(array[i]==0)
                    qvec.at(i)->setText("");
                else
                qvec.at(i)->setNum(array[i]);
                k=array[i];
                j=0;
                while(k>10){
                    k=k/10;
                    j=j+1;
                }
                qvec.at(i)->setFont(QFont("algerian",25-3*j,QFont::Bold));
            }

            if(array!=carr){
                ui->pushButton_3->setEnabled(true);
                while(array[a]!=0)
                    a=qrand()%16;
                if(array[a]==0)
                {
                array[a]=2;
                undoscore=last;
                undo=one;
                }
                qvec.at(a)->setNum(array[a]);

            }
    break;
}

}

        carr=array;

    for(int f=0;f<16;f++){
        if(array[f]==0)qvec[f]->setPixmap(QPixmap(":/0.png"));
         if(array[f]==2)qvec[f]->setPixmap(QPixmap(":/2.png"));
         if(array[f]==4)qvec[f]->setPixmap(QPixmap(":/4.png"));
         if(array[f]==8)qvec[f]->setPixmap(QPixmap(":/8.png"));
         if(array[f]==16)qvec[f]->setPixmap(QPixmap(":/16.png"));
         if(array[f]==32)qvec[f]->setPixmap(QPixmap(":/32.png"));
         if(array[f]==64)qvec[f]->setPixmap(QPixmap(":/64.png"));
          if(array[f]==128)qvec[f]->setPixmap(QPixmap(":/128.png"));
           if(array[f]==256)qvec[f]->setPixmap(QPixmap(":/256.png"));
            if(array[f]==512)qvec[f]->setPixmap(QPixmap(":/512.png"));
             if(array[f]==1024)qvec[f]->setPixmap(QPixmap(":/1024.png"));
              if(array[f]==2048)qvec[f]->setPixmap(QPixmap(":/2048.png"));
    }
    for(i=0;i<16;i++){
        if(array[i]==2048){ui->pushButton->show();
           // ui->continue_2->show();
           ui->label_19->show();ui->pushButton_3->setEnabled(false);
           ui->label_19->setPixmap(QPixmap(":/youwin.png"));
            //ui->pushButton->show();
        for(j=0;j<16;j++){
 //           //qvec[j]->hide();
            qvec[j]->hide();
        }
        }
    }
    if (check()==true){ui->pushButton->show();
        ui->label_19->show();
        ui->label_19->setPixmap(QPixmap(":/unnamed.png"));ui->pushButton_3->setEnabled(false);

    for(j=0;j<16;j++){
     qvec[j]->hide();
    }
    }

}
void MainWindow::on_pushButton_clicked()
{
    //ui->pushButton->hide();
    ui->pushButton_3->setEnabled(false);
    int i;
    for(i=0;i<16;i++){
        array[i]=0;
    }
    int a=qrand()%16;
    int b=qrand()%16;
    while(b==a)b=qrand()%16;
    array[a]=2;
    array[b]=2;
    for(i=0;i<16;i++){
        if(array[i]==0)
            qvec.at(i)->setText("");
        else
        qvec.at(i)->setNum(array[i]);
        qvec.at(i)->setStyleSheet("QLabel{background-color: lightblue;}");
        qvec.at(i)->setAlignment(Qt::AlignCenter);
        qvec.at(i)->setGeometry(90+110*(i%4),130+110*(i/4),100,100);
        qvec.at(i)->setFont(QFont("algerian",25,QFont::Bold));
        score=0;
        ui->label_18->setNum(score);
        ui->label_19->hide();
        for(int z=0;z<16;z++){qvec[z]->setEnabled(true);qvec[z]->show();}

}
    for(int f=0;f<16;f++){
        if(array[f]==0)qvec[f]->setPixmap(QPixmap(":/0.png"));
         if(array[f]==2)qvec[f]->setPixmap(QPixmap(":/2.png"));
         if(array[f]==4)qvec[f]->setPixmap(QPixmap(":/4.png"));
         if(array[f]==8)qvec[f]->setPixmap(QPixmap(":/8.png"));
         if(array[f]==16)qvec[f]->setPixmap(QPixmap(":/16.png"));
         if(array[f]==32)qvec[f]->setPixmap(QPixmap(":/32.png"));
         if(array[f]==64)qvec[f]->setPixmap(QPixmap(":/64.png"));
          if(array[f]==128)qvec[f]->setPixmap(QPixmap(":/128.png"));
           if(array[f]==256)qvec[f]->setPixmap(QPixmap(":/256.png"));
            if(array[f]==512)qvec[f]->setPixmap(QPixmap(":/512.png"));
             if(array[f]==1024)qvec[f]->setPixmap(QPixmap(":/1024.png"));
              if(array[f]==2048)qvec[f]->setPixmap(QPixmap(":/2048.png"));
    }
}
 bool MainWindow::check(){
     for(int z=0;z<16;z++){
         if(array.at(z)==0)return false;


     }
     for(int z=0;z<3;z++){
         for(int y=0;y<3;y++){
             if(array.at(4*z+y)==array.at(4*z+y+1))return false;
         }
     }
     for(int z=0;z<3;z++){
         for(int y=0;y<3;y++){
             if(array.at(z+4*y)==array.at(z+4*(y+1)))return false;
         }
     }
     return true;





 }

void MainWindow::on_quit_clicked()
{
    exit(0);
}

void MainWindow::on_continue_2_clicked()
{
    ui->label_19->hide();
    ui->continue_2->hide();
    for(int z=0;z<16;z++){qvec[z]->setEnabled(true);}
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    array=undo;
    score=undoscore;
    ui->label_18->setNum(score);
    for(int f=0;f<16;f++){
        if(array[f]==0)qvec[f]->setPixmap(QPixmap(":/0.png"));
         if(array[f]==2)qvec[f]->setPixmap(QPixmap(":/2.png"));
         if(array[f]==4)qvec[f]->setPixmap(QPixmap(":/4.png"));
         if(array[f]==8)qvec[f]->setPixmap(QPixmap(":/8.png"));
         if(array[f]==16)qvec[f]->setPixmap(QPixmap(":/16.png"));
         if(array[f]==32)qvec[f]->setPixmap(QPixmap(":/32.png"));
         if(array[f]==64)qvec[f]->setPixmap(QPixmap(":/64.png"));
          if(array[f]==128)qvec[f]->setPixmap(QPixmap(":/128.png"));
           if(array[f]==256)qvec[f]->setPixmap(QPixmap(":/256.png"));
            if(array[f]==512)qvec[f]->setPixmap(QPixmap(":/512.png"));
             if(array[f]==1024)qvec[f]->setPixmap(QPixmap(":/1024.png"));
              if(array[f]==2048)qvec[f]->setPixmap(QPixmap(":/2048.png"));
    }
    ui->pushButton_3->setEnabled(false);
}
