import QtQuick 2.9
import QtQuick.Window 2.2
import QtQml 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    QtObject {
        id: data
        property bool isRed: true
    }

    Image {
        id: img
        asynchronous: true
        anchors.fill: parent
        visible: true
        cache: false
        source: "image://async/red"


        onSourceChanged: {
            canvas.requestPaint();
        }
    }

    Canvas {
        id: canvas
        renderStrategy: Canvas.Cooperative
        renderTarget: Canvas.FramebufferObject
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.save();
            ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
            ctx.restore();
        }
    }

    Timer {
        id: timer
        interval: 30
        repeat: true
        running: false

        onTriggered: {

            if(data.isRed)
            {
                img.source = "image://async/blue";
                data.isRed = false;
            }
            else
            {
                img.source = "image://async/red";
                data.isRed = true;
            }

        }
    }

    Button {
        id: btn
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        checkable: true
        text: "start timer"
        onToggled: {
            if(checked) {
                timer.start();
                text = "end timer";
            } else {
                timer.stop();

                text = "start timer";
            }
        }
    }
}
