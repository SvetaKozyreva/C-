#include "MyForm.h";
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab8::MyForm form;
	Application::Run(% form);
	return 0;

}
