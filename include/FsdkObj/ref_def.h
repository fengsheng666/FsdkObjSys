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

#ifndef REF_DEF_H_FSDKOBJ
#define REF_DEF_H_FSDKOBJ

#include "./Releasable.h"

namespace FsdkObj
{
	struct IRefrence 
	{
		virtual Releasable& asReleasable() = 0;
		virtual int ref() const = 0;
		virtual int unref() const = 0;
	};
}

#endif