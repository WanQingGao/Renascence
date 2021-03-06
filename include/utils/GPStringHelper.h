/******************************************************************
   Copyright 2015, Jiang Xiao-tang

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
#ifndef UTILS_GPSTRINGHELPER_H
#define UTILS_GPSTRINGHELPER_H
#include <vector>
#include <string>
class GPStringHelper
{
public:
    static std::vector<std::string> divideString(const std::string& input);
    static std::string cleanString(const std::string& input);
};
#endif
