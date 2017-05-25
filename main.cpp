#include <QGuiApplication>
#include <QDebug>
#include <QDir>
#include <QImage>
#include <QPainter>
#include <QPointF>
#include <QString>
#include <QStringList>
#include <QTextCodec>
#include <exception>

class FileSavingFailed : public std::runtime_error {
public:
	FileSavingFailed (const QString &fileName) : std::runtime_error("File saving failed."), _fileName(fileName) {}
	const QString &fileName() { return _fileName; }
private:
	QString _fileName;
};

void AddTextWatermarkToImage(const QFileInfo &file, const QDir &resDir) {
	qDebug() << file.absoluteFilePath() << endl;
	QImage image(file.absoluteFilePath());
	QPainter p(&image);
	p.setPen(QPen(Qt::white));
	p.setFont(QFont("Times", image.width() * image.height() / 300000));
	p.translate(image.width(), image.height());
	p.rotate(-90);
	p.drawText(0, 0, QObject::trUtf8("Zarubenko Julia | https://vk.com/phzarubenkoiuliia |"));
	auto resFileName = resDir.filePath(file.fileName());
	if(!image.save(resFileName)) {
		throw FileSavingFailed(resFileName);
	}
}

class DirCreatingFailed : public std::runtime_error {
public:
	DirCreatingFailed (const QString &dirName) : std::runtime_error("File saving failed."), _dirName(dirName) {}
	const QString &dirName() { return _dirName; }
private:
	QString _dirName;
};

void AddTextWatermarkToImageList(const QDir &directory, const QDir &resDir) {
	if(!resDir.exists()) {
		if(!resDir.mkpath(resDir.absolutePath())) {
			throw DirCreatingFailed(resDir.absolutePath());
		}
	}
	auto fileList = directory.entryInfoList({"*.jpg"});
	for (auto file: fileList) {
		AddTextWatermarkToImage(file, resDir);
	}
}

void AddTextWatermarkToImageList(const QString &dirPath, const QString &resDirPath) {
	AddTextWatermarkToImageList(QDir(dirPath), QDir(resDirPath));
}

int main(int argc, char *argv[]) {	
#ifdef Q_OS_WIN32
	  QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

	QGuiApplication a(argc, argv);
	try {
		auto args = a.arguments();
		if(args.count() <= 1) 	{
			qCritical() << QObject::trUtf8("Необходимо указать каталог в параметре запуска.") << endl;
			return 1;
		}

		QDir sourceDir(args[1]);
		QDir resDir(sourceDir.absoluteFilePath("../") + QDir::separator() + sourceDir.dirName() + QObject::trUtf8(" водяной знак"));
		AddTextWatermarkToImageList(sourceDir, resDir);
	} catch (FileSavingFailed ex) {
		qCritical() << QObject::trUtf8("Не могу сохранить файл %0").arg(ex.fileName()) << endl;
	} catch (DirCreatingFailed ex) {
		qCritical() << QObject::trUtf8("Не могу создать каталог %0").arg(ex.dirName()) << endl;
	}
}
