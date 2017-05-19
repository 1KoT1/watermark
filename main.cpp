#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QImage>
#include <QString>
#include <QStringList>

void AddTextWatermark(const QString &dirPath, const QString &resDirPath) {
	QDir directory(dirPath);
	QDir resDir(resDirPath);
	if(!resDir.exists()) {
		if(!resDir.mkpath(resDirPath)) {
			qCritical() << QObject::trUtf8("Не могу создать каталог %0").arg(resDirPath);
			return;
		}
	}
	auto fileList = directory.entryInfoList({"*.jpg"});
	for (auto file: fileList) {
		qDebug() << file.absoluteFilePath() << endl;
		QImage image(file.absoluteFilePath());
		auto resFileName = resDir.filePath(file.fileName());
		if(!image.save(resFileName)) {
			qCritical() << QObject::trUtf8("Не могу сохранить файл %0").arg(resFileName);
		}
	}
}

int main(int argc, char *argv[]) {
	AddTextWatermark("D:/test images", "D:/test images result");
}
