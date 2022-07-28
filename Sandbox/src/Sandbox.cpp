#include <Launch.h>

class Sandbox : public Launch::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Launch::Application* Launch::CreateApplication()
{
	return new Sandbox();
}