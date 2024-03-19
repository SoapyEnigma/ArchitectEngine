#include <Engine.h>

class Editor : public AE::Application
{
public:
	Editor()
	{

	}
	~Editor()
	{

	}
};

AE::Application* AE::CreateApplication()
{
	return new Editor();
}