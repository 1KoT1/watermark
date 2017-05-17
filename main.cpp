#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	using namespace std;

	cout << "Start app." << endl;
	QCoreApplication a(argc, argv);

	cout << "Exec QCoreApplication" << endl;

	return a.exec();

	cout << "Exit" << endl;
}
