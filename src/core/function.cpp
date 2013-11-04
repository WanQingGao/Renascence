/******************************************************************
   Copyright 2013, Jiang Xiao-tang

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
******************************************************************/
#include "core/function.h"
void GP_Output_clear(GP_Output& out)
{
    for (int i=0; i<out.output.size(); ++i)
    {
        if (NULL!=out.output[i].freeCallBack)
        {
            out.output[i].freeCallBack(out.output[i].content);
        }
    }
}

void GP_Output_collect(std::vector<void*>& output, GP_Output& out)
{
    for (int i=0; i<out.output.size(); ++i)
    {
        output.push_back(out.output[i].content);
    }
}
