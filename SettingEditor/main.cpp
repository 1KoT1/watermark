#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "settings.h"

int main(int argc, char *argv[]) {
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QCoreApplication::setOrganizationName("Pochkaenko	");
	QCoreApplication::setOrganizationDomain("pochkaenko.ru");
	QCoreApplication::setApplicationName("Watermark");

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	Settings settings;
	engine.rootContext()->setContextProperty("settings", &settings);
	engine.load(QUrl(QLatin1String("qrc:/main.qml")));

	return app.exec();
}
