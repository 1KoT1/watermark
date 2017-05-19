#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QStringList>

void AddTextWatermark(const QStringList &fileList) {
	for (auto name: fileList) {
		qDebug() << name << endl;
	}
}

int main(int argc, char *argv[]) {
	QDir directory("D:/test images");
	auto fileList = directory.entryList({"*.jpg"});
	AddTextWatermark(fileList);
}
