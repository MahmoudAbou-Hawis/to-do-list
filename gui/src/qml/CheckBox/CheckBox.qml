import QtQuick 2.7

Item {
    signal checked(bool checkValue) 

    property bool __checked: false 
    property string text: ""
    property string color: "black"
    property string family: "Arial"
    property bool __delete: false
    property real textOpacity: 1.0
    
    id:checkedBox

    Image {
        id: box
        source: "../../assests/images/approve.png"
        width: 40
        height: 40
        fillMode: Image.PreserveAspectFit

        Rectangle {
            id: hoverRectangle
            anchors.fill: parent
            color: __checked ? "lightgreen" : "white" 
            opacity: 0.5 
            anchors.margins: 6
        }

        Image {
            id: tick
            source: "../../assests/images/tick.png"
            visible: __checked 
            anchors.fill: parent
            anchors.margins: 6
        }
        Text {
            id: label
            text: checkedBox.text
            color: checkedBox.color
            font.family: checkedBox.family
            opacity:textOpacity
            font.pixelSize: 24
            anchors {
                left: box.right
                leftMargin: 10
                verticalCenter: box.verticalCenter
            }
            Rectangle
            {
                visible: checkedBox.__delete
                color:"black"
                anchors{
                    fill: parent
                    topMargin: 15
                    bottomMargin: 10
                    verticalCenter:label.verticalCenter
                }
            }
        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                __checked = !__checked 
                tick.visible = __checked 
                checked(__checked) 
            }

            onEntered: hoverRectangle.color = "lightgray"
            onExited: hoverRectangle.color = __checked ? "lightgreen" : "white"
        }
    }
}
