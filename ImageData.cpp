#include "ImageData.h"
#include <QImage>
#include <QDebug>
#include <string.h>


ImageData *ImageData::m_instance = nullptr;

ImageData *ImageData::instance()
{
    if(!m_instance)
    {
        m_instance = new ImageData();
    }

    return m_instance;
}

bool ImageData::loadImage1(const QString &fileName)
{
    return loadImage(fileName, m_data1);
}

bool ImageData::loadImage2(const QString &fileName)
{
    return loadImage(fileName, m_data2);
}

unsigned char *ImageData::data1() const
{
    return m_data1;
}

unsigned char *ImageData::data2() const
{
    return m_data2;
}

ImageData::ImageData()
{

}

ImageData::~ImageData()
{
    if(m_data1)
    {
        delete m_data1;
        m_data1 = nullptr;
    }

    if(m_data2)
    {
        delete m_data2;
        m_data2 = nullptr;
    }

}

bool ImageData::loadImage(const QString &fileName, unsigned char* &data)
{
    if(fileName.isEmpty())
    {
        qWarning() << "file name is empty.";
        return false;
    }

    QImage img(fileName, "jpg");
    auto width = img.width();
    auto height = img.height();
    auto format = img.format();

    switch(format)
    {
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32:
        {
            data = new unsigned char[width * height * 4];
            memcpy(data, img.bits(), width * height * 4);
        }
        break;
        default:
        {
            qCritical() << "image format not supported.";
        }
        return false;
    }

    return true;
}
