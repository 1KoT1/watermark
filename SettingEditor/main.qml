import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
	id: applicationWindow
	visible: true
	width: 640
	height: 480
	title: qsTr("Настроить водяной знак")

	GridLayout {
		id: gridLayout
		height: 100
		anchors.right: parent.right
		anchors.left: parent.left
		anchors.top: parent.top
		columns: 1
		rows: 3

		Label {
			id: label
			text: qsTr("Текст водяного знака")
			Layout.row: 1
			Layout.column: 1
			Layout.fillWidth: true
		}

		TextField {
			id: watermarkText
			Layout.row: 1
			Layout.column: 2
			Layout.alignment: Qt.AlignLeft | Qt.AlignTop
			Layout.fillWidth: true

			text: settings.watermarkText
		}

		Label {
			id: label1
			text: qsTr("Коэффициент размера")
			Layout.row: 2
			Layout.column: 1
			Layout.fillWidth: true
		}

		TextField {
			id: sizeCoef
			Layout.row: 2
			Layout.column: 2
			Layout.alignment: Qt.AlignLeft | Qt.AlignTop
			Layout.fillWidth: true

			text: settings.sizeCoef
		}

		Label {
			id: label2
			text: qsTr("Шрифт")
			Layout.row: 3
			Layout.column: 1
			Layout.fillWidth: true
		}

		TextField {
			id: watermarkFont
			Layout.row: 3
			Layout.column: 2
			Layout.alignment: Qt.AlignLeft | Qt.AlignTop
			Layout.fillWidth: true

			text: settings.watermarkFont
		}
	}

	Button {
		id: button
		x: 349
		y: 356
		text: qsTr("Сохранить")
		anchors.bottom: parent.bottom
		anchors.right: parent.right

		onClicked: {
			settings.sizeCoef = sizeCoef.text;
			settings.watermarkFont = watermarkFont.text;
			settings.watermarkText = watermarkText.text;
			settings.save();
		}
	}
}
