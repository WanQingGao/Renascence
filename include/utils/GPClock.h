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
#ifndef UTILS_GPCLOCK_H
#define UTILS_GPCLOCK_H

class GPClock
{
    public:
        GPClock(int func, const char* name);
        ~GPClock();
        int reset();
    protected:
        size_t mStart;
        int mId;
        char* mName;
};

#define GPCLOCK GPClock __clock(__LINE__, __func__)


#endif
