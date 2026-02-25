#include <application.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	application app;
	return app.run();
}
