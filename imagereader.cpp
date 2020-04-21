#include "imagereader.h"
#include <QFile>
#include <QDir>

ImageReader::ImageReader(QString folder, typeReader type)
{
    if (type == Rcard)
        fillListImgCard(folder);
}

Card    ImageReader::readCard(QImage cardIm)
{
    for (int i = 0; i < strIm.size(); i++)
        if (strIm.at(i).first == cardIm)
            return Card(strIm.at(i).second);
    return Card("wtf");
}

int ImageReader::readNumber(QImage number)
{
    return -1;
}

void ImageReader::fillListImgCard(QString folder)
{
    QDir d(folder);
    QFileInfoList fi = d.entryInfoList();
    for (int i(0); i < fi.size(); i++)
    {
        if (fi.at(i).filePath().endsWith("/.") || fi.at(i).filePath().endsWith("/.."))
            continue;
          strIm.push_back(
                      (qMakePair ( QImage(fi.at(i).filePath() ) ,
                       fi.at(i).baseName()))
                      );
    }
}

