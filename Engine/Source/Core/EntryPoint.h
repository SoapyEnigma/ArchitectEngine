#pragma once

#ifdef AE_PLATFORM_WINDOWS

extern AE::Application* AE::CreateApplication();

int main(int argc, char** argv)
{
	AE::Log::Init();

	AE_ENGINE_TRACE("Initialized Logger.");
	
	AE_APP_TRACE("Initialized Logger.");

	auto editor = AE::CreateApplication();
	editor->Run();
	delete editor;
}

#endif