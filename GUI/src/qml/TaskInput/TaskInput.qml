import QtQuick 2.7
import "../Button"

Item {
    property int taskInputwidth:600
    property var handler: null
    property real textAreaOpacity:1
    property string textInputText: ""
    Rectangle
    {
        id:root
        width: taskInputwidth
        height: 60
        border.color: "black"
        border.width: 1
        radius:internalRecangle.radius
        Rectangle
        {
            id:internalRecangle
            radius: 10
            width: parent.width
            height: parent.height
            color: "#564b4b4b"
            opacity: textAreaOpacity

        }
        AddButton
        {

            id:addButton
            onClickHandler: function()
            {
                if(handler)
                {
                    handler();
                }
                else
                {
                    console.warn("No click handler defined for this button.");
                }
            }
            anchors {
                left: internalRecangle.left
                leftMargin: 10
            }
            y:parent.height/2 -12
        }
        Text
        {
            id:taskText
            text: "Add a task"
            color: "black"
            y: parent.height/2 - 12
            font.pixelSize: 20
            anchors {
                left: addButton.right
                leftMargin: 45
            }
        }
        TextInput
        {
            id:taskInput
            z:1
            width: parent.width - 50
            height: parent.height - 10
            text:textInputText
            anchors {
                left: internalRecangle.left
                right: internalRecangle.right
                leftMargin:50
                verticalCenter: internalRecangle.verticalCenter
                rightMargin: 10
                fill: internalRecangle
                topMargin: 17
            }
            onTextChanged: {
                taskText.text = taskInput.text.length === 0 ? "Add a task" : ""
                textInputText = taskInput.text
            }
            font.pixelSize: 20
            color: "black"
            clip: true
            wrapMode: TextInput.NoWrap


        }

    }   
}