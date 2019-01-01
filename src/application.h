#pragma once
#include <iostream>

namespace Game
{

	class Application
	{
	public:
		virtual ~Application() {};

		virtual void init() {};

		virtual void run();
	private:
	};

}