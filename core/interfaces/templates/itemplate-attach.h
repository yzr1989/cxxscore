#pragma once

#include <memory>

namespace Interface {
	namespace Template {

		template <class Class>
		class IAttachTemplate {
		public:
			explicit IAttachTemplate() = default;
			virtual ~IAttachTemplate() = default;

			virtual void attach(std::unique_ptr<Class> &&object) = 0;

		};

	}
}
