#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "settings.h"

int main(int argc, char *argv[]) {
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	Settings settings("Zarubenko Julia | https://vk.com/phzarubenkoiuliia |", 70, "Times");
	engine.rootContext()->setContextProperty("settings", &settings);
	engine.load(QUrl(QLatin1String("qrc:/main.qml")));

	return app.exec();
}
