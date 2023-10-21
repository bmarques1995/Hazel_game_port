#pragma once

namespace Hazel {

	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void Present() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() = 0;

		static Scope<GraphicsContext> Create(void* window);
	};

}