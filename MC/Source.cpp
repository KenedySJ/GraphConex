#include "iostream"
#include "Windows.h"
#include "MainPanel.h"
using namespace std;
using namespace MC;
using namespace System::Windows::Forms;
int main()
{
	Application::EnableVisualStyles();
	MainPanel^ formulario = gcnew MainPanel();
	Application::Run(formulario);
	return 0;
}