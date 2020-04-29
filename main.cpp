#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AsyncImageProvider.h"
#include "ImageData.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    ImageData::instance()->loadImage1("C:/Users/86176/AppData/Local/Temp/bokeccdoc/781A6E17256948509C33DC5901307461/2E4FE0D0037E02429C33DC5901307461/drawingBoard/0.jpg");
    ImageData::instance()->loadImage2("C:/Users/86176/AppData/Local/Temp/bokeccdoc/781A6E17256948509C33DC5901307461/2E4FE0D0037E02429C33DC5901307461/drawingBoard/1.jpg");

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("async"), new AsyncImageProvider);
//    engine.load(QUrl(QStringLiteral("qrc:/no_provider_image_show.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/no_provider_canvas_show.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/provider_image_show.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/provider_canvas_show.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
