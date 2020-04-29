#ifndef ASYNCIMAGERESPONSE_H
#define ASYNCIMAGERESPONSE_H

#include <QQuickImageResponse>
#include <QRunnable>
#include <QImage>
#include <QString>
#include <QSize>

class QQuickTextureFactory;
class AsyncImageResponse : public QQuickImageResponse, public QRunnable
{
public:
    AsyncImageResponse(const QString &id, const QSize &requestedSize);

    virtual QQuickTextureFactory *textureFactory() const override;

    virtual void run() override;

    QString m_id;
    QSize m_requestedSize;
    QImage m_image;
};

#endif // ASYNCIMAGERESPONSE_H
