#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug>
#include <QVector>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <io.h>
#include <QDirIterator>
#include <QWheelEvent>
#include <QGuiApplication>
#include <QDateTime>
#include <QScreen>
#include "hi_imagebox.h"
#include <QWheelEvent>
#include <QPainter>
//#include "mylabel.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

struct ImageFile
{
    std::string file_name; /*!< 文件名 */
    int order_number; /*!< 文件序号, 取文件名 */
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;

public:
//    bool SortByImageFiles(const ImageFile img1, const ImageFile img2);
//    QVector<QString> split(const QString& str, const QString& delim);
//    void GetImagePaths(string folder_path, std::string file_format, std::vector<ImageFile>& file_names);

//    int Getimage(const char * filename, unsigned char* pImage,int row);
    //int max_row;
    int ROWS;
    int R_ROW;
    int G_ROW;
    int B_ROW;

    int OutfileWid, OotfileHid;


    int pic_counts;
    const char* save_pic_name;
    string ige_path;

    unsigned char *data = new unsigned char;
    std::vector<ImageFile> file_names;

    QString runPath = QCoreApplication::applicationDirPath();       //获取exe路径
//    QString hglpName = "photo";
//    QString hglpPath = QString("%1/%2").arg(runPath).arg(hglpName);

    unsigned char * pRGBImage;
    unsigned char *imageData;

    QPixmap m_pix;
    QImage my_image;

private slots:
    void on_pushButton_opendir_clicked();
    void on_pushButton_composite_clicked();
    void on_pushButton_savepit_clicked();
    void on_pushButton_exit_clicked();
private:
    HI_ImageBox m_imageBox;
};
#endif // WIDGET_H


// sort picture retuan array
bool SortByImageFiles(const ImageFile img1, const ImageFile img2);
QVector<QString> mysplit(const QString& str, const QString& delim);
void GetImagePaths(string folder_path, std::string file_format, std::vector<ImageFile>& file_names);

int Getimage(const char * filename, unsigned char* pImage,int row);

struct IMAGEINFO {
    unsigned int width;
    unsigned int height;
    BITMAPINFOHEADER INFOHEADER;
};
IMAGEINFO GetWidHei(const char* filename);
//int SaveBmp(PUCHAR data, BITMAPINFOHEADER pBmpInfo, int nImgW, int nImgH, const char* filename);


