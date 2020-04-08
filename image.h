#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_image.h"
#include<QPainter>
#include<QDir>
#include<QListWidget>
#include<QDebug>
#include<QFileDialog>
#include<QDebug>
#include<QPixmap>

class image : public QMainWindow
{
	Q_OBJECT

public:
	image(QWidget *parent = Q_NULLPTR);

private:
	Ui::imageClass ui;
	QString currentDirPath;

signals:
	
	
public slots :
	void openImg();
    void openFolder();
	void clickshowPic(QListWidgetItem *item);


};
