#pragma once

#ifdef WW_PLATFORM_WINDOWS

extern ww::Application* ww::CreateApplication();

int main(int argc, char** argv)
{
	ww::Log::Init();

	auto editor = ww::CreateApplication();
	editor->Run();
	delete editor;
}

#endif