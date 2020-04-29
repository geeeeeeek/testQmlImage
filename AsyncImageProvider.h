#ifndef ASYNCIMAGEPROVIDER_H
#define ASYNCIMAGEPROVIDER_H

#include <QQuickAsyncImageProvider>
#include <QThreadPool>
class QQuickImageResponse;
class AsyncImageProvider : public QQuickAsyncImageProvider
{
public:
    virtual QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override;
private:
    QThreadPool m_pool;
};

#endif // ASYNCIMAGEPROVIDER_H
