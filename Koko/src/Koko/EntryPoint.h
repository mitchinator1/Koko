#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#ifdef KOKO_PLATFORM_WINDOWS

extern Koko::Application* Koko::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Koko::CreateApplication();
	app->Run();
	delete app;
}

#endif

#endif