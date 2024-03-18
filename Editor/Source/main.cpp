#include <Engine.h>

class Editor : public ww::Application
{
public:
	Editor()
	{

	}
	~Editor()
	{

	}
};

ww::Application* ww::CreateApplication()
{
	return new Editor();
}