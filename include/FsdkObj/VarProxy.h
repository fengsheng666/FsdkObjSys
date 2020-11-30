// Copyright (c) 2020 FengSheng.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//    http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef VARPROXY_H_FSDKOBJ
#define VARPROXY_H_FSDKOBJ

#include "./Variant.h"
#include "./FsdkObjDef.h"

namespace FsdkObj
{
	class FSDKOBJ_API VarProxy : public IVariant
	{
	public:
		VarProxy();
		VarProxy(const VarProxy& other);
		~VarProxy();
		VarProxy& operator=(const VarProxy& other);
		bool isNull() const;

		virtual IVariant* clone() const;

		template <typename T>
		void setVar(T var)
		{
			if (m_impl)
			{
				delete m_impl;
			}
			m_impl = new VarImpl<T>(var);
		}
		template <typename T>
		T getVar() const
		{
			VarImpl<T>* impl
				= dynamic_cast<VarImpl<T>*>(m_impl);
			if (impl != NULL)
			{
				return impl->value();
			}
			else
			{
				throw "not find!";
			}
		}
	private:
		IVariant* m_impl;
	};
}

#endif