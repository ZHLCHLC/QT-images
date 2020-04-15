#include "image.h"
#include<iostream>
using namespace std;

image::image(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_openimage, SIGNAL(clicked()), this, SLOT(openImg()));
	connect(ui.pushButton_openfolder, SIGNAL(clicked()), this, SLOT(openFolder()));
	connect(ui.listWidget_dirs, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(clickshowPic(QListWidgetItem *)));


}

void image::openImg()
{
	QString OpenFile, OpenFilePath;
	QImage image;

	//打开文件夹中的图片文件
	OpenFile = QFileDialog::getOpenFileName(this,
		"Please choose an image file",
		"",
		"Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
	if (OpenFile != "")
	{
		if (image.load(OpenFile))
		{
			QPainter painter(&image);
			//label自适应窗口大小
			QImage resultImg = image.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
			ui.label->setPixmap(QPixmap::fromImage(resultImg));
			ui.label->show();
		}
	}
	qDebug() << OpenFile;
	//显示所示图片的路径
	QFileInfo OpenFileInfo;
	OpenFileInfo = QFileInfo(OpenFile);
	OpenFilePath = OpenFileInfo.filePath();  //filePath（）函数返回QString类型
	ui.statusBar->showMessage(OpenFilePath);

}

void image::openFolder()
{
	cout << "openFolder is clicked" << endl;
	ui.listWidget_dirs->clear();
	QString path = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("view file"), QDir::currentPath()));
	qDebug() << path;

	QDir dir(path);
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::Dirs);
	QFileInfoList list = dir.entryInfoList();


	//循环遍历文件，并添加到listWidget
	for (int i = 0; i < list.length(); i++)
	{
		QString file = path + "\\"+list.at(i).fileName() ;
		ui.listWidget_dirs->addItem(file);
	}
}

void image::clickshowPic(QListWidgetItem *item)
{

	QString strName = item->text();
	QString OpenFile = strName;
	QImage image;
	if (OpenFile != "")
	{
		if (image.load(OpenFile))
		{
			QPainter painter(&image);
			
			QImage resultImg = image.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
			ui.label->setPixmap(QPixmap::fromImage(resultImg));
			ui.label->show();
		}
	}
}
