#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_imageBox.Init(ui->verticalLayout_2);
}

Widget::~Widget()
{
    delete ui;
}


bool SortByImageFiles(const ImageFile img1, const ImageFile img2)
{
    return img1.order_number < img2.order_number;
}

QVector<QString>mysplit(const QString& str, const QString& delim)
{
    QVector<QString> res;
    if ("" == str) return res;
    char* strs = new char[str.length() + 1];
    strcpy(strs, str.toStdString().c_str());    // qstring to char

    char* d = new char[delim.length() + 1];
    strcpy(d, delim.toStdString().c_str());

    char* p = strtok(strs, d);
    while (p) {
        QString s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }
//	cout << str.length() << endl;

    return res;
}

void GetImagePaths(std::string folder_path, std::string file_format, std::vector<ImageFile>& file_names)
{
    intptr_t hFile = 0;
    _finddata_t fileInfo;
    std::string file_path = folder_path;
    file_path = file_path.append(file_format);
    hFile = _findfirst(file_path.c_str(), &fileInfo);
    ImageFile temp_path;
    QVector<QString> split_result;
    if (hFile != -1) {
        /*cout << "----原顺序----" << endl;*/
        do {
            if ((fileInfo.attrib & _A_SUBDIR)) {
                continue;
            }
            else {
                temp_path.file_name = folder_path + fileInfo.name;
                split_result = mysplit(fileInfo.name, ".");
                temp_path.order_number = atoi(split_result[0].toStdString().c_str());
                file_names.push_back(temp_path);
                //cout << temp_path.file_name << endl;
            }

        } while (_findnext(hFile, &fileInfo) == 0);
        std::sort(file_names.begin(), file_names.end(), SortByImageFiles);

        _findclose(hFile);
    }
}

int Getimage(const char * filename, unsigned char* pImage,int row)
{
    unsigned int height;
    unsigned int weight;

    int ret = -1;
    FILE* fpR = fopen(filename, "rb");

    BITMAPFILEHEADER fileheaderR;
    BITMAPINFOHEADER infoheaderR;

    ret = fread(&fileheaderR, sizeof(BITMAPFILEHEADER), 1, fpR);
    ret = fread(&infoheaderR, sizeof(BITMAPINFOHEADER), 1, fpR);

    height = infoheaderR.biHeight;
    weight = infoheaderR.biWidth;

    // rgb
    unsigned char* pRGBQuard = new unsigned char[256 * sizeof(RGBQUAD)];
    ret = fread(pRGBQuard, 256 * sizeof(RGBQUAD), 1, fpR);

    delete[]pRGBQuard;
    // info
    //unsigned char pRimage[4096 * 1];
    fseek(fpR, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 256 + weight * (height - row), SEEK_SET);
    ret = fread(pImage, weight * 1, 1, fpR);
    fclose(fpR);
    return 0;
}

void Widget::on_pushButton_opendir_clicked()
{

    QString filename = QFileDialog::getExistingDirectory();
//    vector<ImageFile> file_name;
    ige_path = filename.toStdString()+"/";
    cout << ige_path<<endl;
    GetImagePaths(ige_path,"*.bmp",file_names);

    ui->lineEdit_dir->setText(filename);
//    ui->textBrowser->setText());
    cout << file_names.size() <<endl;
    pic_counts = file_names.size();
//    for (int i = 0; i < file_names.size(); ++i) {
//        //cout << file_names[i].file_name <<endl;
//        ui->textBrowser->setText(file_names[i].file_name);
//    }

}

IMAGEINFO GetWidHei(const char* filename)
{
    IMAGEINFO OUTFILE;

    int  ret = -1;
    // open r.bmp
    FILE* fp = fopen(filename, "rb");

    BITMAPFILEHEADER fileheaderR;
    BITMAPINFOHEADER infoheaderR;

    ret = fread(&fileheaderR, sizeof(BITMAPFILEHEADER), 1, fp);
    ret = fread(&infoheaderR, sizeof(BITMAPINFOHEADER), 1, fp);

    OUTFILE.height = infoheaderR.biHeight;
    OUTFILE.width = infoheaderR.biWidth;

    //height = infoheaderR.biHeight;
    //weight = infoheaderR.biWidth;
    return OUTFILE;
}

void Widget::on_pushButton_composite_clicked()
{
//    std::vector<ImageFile> file_names;
//    on_pushButton_opendir_clicked();

    cout << file_names[1].file_name<<endl;

//    int OutfileWid, OotfileHid;
    IMAGEINFO OUTFILE;
    OUTFILE = GetWidHei(file_names[1].file_name.c_str());
    OutfileWid = OUTFILE.width;	// width
    OotfileHid = OUTFILE.height;	// hight

    ROWS = ui->lineEdit_rows->text().toInt();// 总共多少行
    R_ROW = ui->lineEdit_R->text().toInt();  // 第几行
    G_ROW = ui->lineEdit_G->text().toInt();
    B_ROW = ui->lineEdit_B->text().toInt();

    unsigned char * pRGBImage = new unsigned char[3 * OutfileWid * ROWS];

    unsigned char* imagbuffR = new unsigned char[OutfileWid * 1];
    unsigned char* imagbuffG = new unsigned char[OutfileWid * 1];
    unsigned char* imagbuffB = new unsigned char[OutfileWid * 1];

    for (int i = 0; i < pic_counts; i += 4)
        {
                Getimage(file_names[i].file_name.c_str(), imagbuffR, R_ROW);
                Getimage(file_names[i + 1].file_name.c_str(), imagbuffG,G_ROW);
                Getimage(file_names[i + 2].file_name.c_str(), imagbuffB,B_ROW);

            for (int j = 0; j < OutfileWid * 3; j += 3)
            {
                *(pRGBImage + i * OutfileWid * 3 / 4 + j) = *(imagbuffB + j / 3);
                *(pRGBImage + i * OutfileWid * 3 / 4 + j + 1) = *(imagbuffG +  j / 3);
                *(pRGBImage + i * OutfileWid * 3 / 4 + j + 2) = *(imagbuffR +  j / 3);
            }
        }

    BITMAPINFOHEADER pBmpInfo;
    memset(&pBmpInfo, 0, sizeof(BITMAPFILEHEADER) + sizeof(RGBQUAD));
    //pBmpInfo = (LPBITMAPINFO)malloc(sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD));
    pBmpInfo.biSize = sizeof(BITMAPINFOHEADER);
    pBmpInfo.biWidth = OutfileWid;//nImgW
    pBmpInfo.biHeight = -ROWS;//nImgH	result_out   /*500*/
    pBmpInfo.biPlanes = 1;	// 	为目标设备说明颜色的平面数。其值总是为1。
    pBmpInfo.biBitCount = 24;	// 指定表示颜色时要用到的位数 1：黑白二色图; 4：16色图; 8：256色; 24：真彩色图
    pBmpInfo.biCompression = 0;		// BI_RGB  不压缩
    pBmpInfo.biSizeImage = OutfileWid * ROWS * 3;//nImgW * nImgH     //	指定实际的位图数据占用的字节数。biSizeImage = biWidth * biHeight
    pBmpInfo.biXPelsPerMeter = 0;	// 指定目标设备的水平分辨率。单位是每米的像素个数，
    pBmpInfo.biYPelsPerMeter = 0;	// 指定目标设备的竖直分辨率。单位是每米的像素个数，
    pBmpInfo.biClrUsed = 0;			//	指定本图象实际用到彩色表中的颜色索引数	若为0，则说明使用所有调色板项（数量为$\small{2^{biBitCount}}$)
    pBmpInfo.biClrImportant = 0;	// 指定本图象中重要的颜色数 若为0，则认为所有的颜色都是重要的

    BITMAPFILEHEADER fheader;
    memset(&fheader, 0, sizeof(BITMAPFILEHEADER));
    RGBQUAD rgbquad[256];

    // mono8
    if (pBmpInfo.biBitCount == 8)
    {
        fheader.bfType = 0x4d42;  //'MB','BM'
        fheader.bfSize = (DWORD)sizeof(BITMAPINFOHEADER) + (DWORD)sizeof(BITMAPFILEHEADER) + sizeof(RGBQUAD) + OutfileWid * ROWS;
        fheader.bfOffBits = (DWORD)sizeof(BITMAPINFOHEADER) + (DWORD)sizeof(BITMAPFILEHEADER) + sizeof(RGBQUAD);
        fheader.bfReserved1 = 0;
        fheader.bfReserved2 = 0;

        for (int i = 0; i < 256; i++)
        {
            rgbquad[i].rgbBlue = i;
            rgbquad[i].rgbGreen = i;
            rgbquad[i].rgbRed = i;
            rgbquad[i].rgbReserved = 0;
        }
    }
    // RGB24
    else if (pBmpInfo.biBitCount == 24)
    {
        fheader.bfType = 0x4d42;  //'MB','BM'
        fheader.bfSize = (DWORD)sizeof(BITMAPINFOHEADER) + (DWORD)sizeof(BITMAPFILEHEADER) + OutfileWid * ROWS * 3;
        fheader.bfOffBits = (DWORD)sizeof(BITMAPINFOHEADER) + (DWORD)sizeof(BITMAPFILEHEADER);
        fheader.bfReserved1 = 0;
        fheader.bfReserved2 = 0;
    }

    /*unsigned char *imageData = NULL*/;

    int imageLen = OutfileWid * ROWS *3;
//    imageData = (unsigned char*)malloc(imageLen);
//    memcpy(imageData,pRGBImage,3 * OutfileWid * ROWS);

    FILE*stream;
    if((stream=fopen(save_pic_name,"wb+"))==NULL)
    {
        fprintf(stderr,"Can not open output file.\n");
//        return 0;
    }
    fread(pRGBImage ,1,imageLen,stream);
    QImage image(pRGBImage+54, OutfileWid, ROWS, QImage::Format_RGB888);
//    QMatrix matrix;
//    matrix.rotate(180);
//    QImage m_image = image.transformed(matrix).rgbSwapped();
    my_image = image.rgbSwapped();

    //ui->label_picture->setPixmap(QPixmap::fromImage(my_image.scaled(ui->label_picture->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    // 存入图像，格式为R,G,B(0,1,2)
    m_imageBox.SetImage(my_image);
//    free(imageData);
}

void Widget::on_pushButton_savepit_clicked()
{
    QString save_path = QFileDialog::getSaveFileName(this,tr("Save Image"),"",tr("Images (*.png *.bmp *.jpg)")); //选择路径
//    QScreen *screen = QGuiApplication::primaryScreen();
//    screen->grabWindow(ui->label_picture->winId()).save(filename1);
    my_image.save(save_path);
}

void Widget::on_pushButton_exit_clicked()
{
    close();
}


