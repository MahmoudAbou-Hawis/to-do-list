import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.2

ApplicationWindow {
    visible: true
    width: Screen.width
    height: Screen.height
    title: "ToDo Login"
    Image {
        source: "../assests/images/background.jpeg"  // Path to your background image
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }
    Column {
        anchors.centerIn: parent
        spacing: 20
        Row {
            Rectangle {
                id: rect1
                width: 450
                height: 40
                color: "#4285F4"  // Google blue color
                border.color: "#34A853"  // Google green color
                radius: 20  // More rounded corners for a softer button appearance
                
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    id: name
                    text: qsTr("Login With Your Google Account")
                    color: "white"
                    font.bold: true
                    font.pointSize: 14
                }

                Image {
                    id: googleimg
                    source: "../assests/images/google-calendar.png"
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    width: 25  
                    height: 25
                }

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {
                    login.loadGoogle();

                    if (login.connect()) {
                            login.gotoApp(); 
                      }
                    }

                    onHoveredChanged: {
                        if (mouseArea.containsMouse) {
                            rect1.color = "#34A853";  
                        } else {
                            rect1.color = "#4285F4";  
                        }
                    }
                }
            }
        }
    }
}
