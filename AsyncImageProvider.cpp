#include "AsyncImageProvider.h"
#include "AsyncImageResponse.h"
#include <QDebug>

QQuickImageResponse *AsyncImageProvider::requestImageResponse(const QString &id, const QSize &requestedSize)
{
//    qDebug() << "id: " << id;
    AsyncImageResponse *response = new AsyncImageResponse(id, requestedSize);
    m_pool.start(response);
    return response;
}
