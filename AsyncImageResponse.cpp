#include "AsyncImageResponse.h"
#include <QQuickTextureFactory>
#include "ImageData.h"
#include <QDebug>

AsyncImageResponse::AsyncImageResponse(const QString &id, const QSize &requestedSize)
    : m_id(id)
    , m_requestedSize(requestedSize)
{
    setAutoDelete(false);
}

QQuickTextureFactory *AsyncImageResponse::textureFactory() const
{
    return QQuickTextureFactory::textureFactoryForImage(m_image);
}

void AsyncImageResponse::run()
{
//    m_image = QImage(50, 50, QImage::Format_ARGB32);
    if(m_id == "red")
    {
//        m_image.fill(Qt::red);
        m_image = QImage(ImageData::instance()->data1(), 720, 540, QImage::Format_RGB32);
    }
    else
    {
//        m_image.fill(Qt::blue);
        m_image = QImage(ImageData::instance()->data2(), 720, 540, QImage::Format_RGB32);
    }

    if(m_requestedSize.isValid())
    {
        m_image = m_image.scaled(m_requestedSize);
    }

    emit finished();
}


