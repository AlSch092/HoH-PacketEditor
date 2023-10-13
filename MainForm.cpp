#include "MainForm.h"

using namespace HoHPacketEditor;

[STAThreadAttribute]
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	Application::Run(gcnew MainForm());
	return 0;
}