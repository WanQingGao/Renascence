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
#ifndef CORE_GPCOMPUTEPOINT_H
#define CORE_GPCOMPUTEPOINT_H
#include "head.h"
#include "core/GPFunctionDataBase.h"
#include "lowlevelAPI/GPContents.h"
#include <vector>
#include "core/GPStatusContent.h"
class GPComputePoint:public GPRefCount
{
public:
    typedef GPContents::GP_Unit ContentWrap;
    GPComputePoint(const GPFunction* f);
    virtual ~GPComputePoint();
    /*inputs can only has one content*/
    bool receive(GPPtr<ContentWrap> inputs, int n);
    inline const GPFunction* get() const {return mF;}
    const std::vector<bool>& flags() const {return mFlags;}
    int map(double* value, int n);
    inline bool completed() const {return mComplte;}
    GPContents* compute();
private:
    bool _computeCompleteStatus() const;
    const GPFunction* mF;
    std::vector<bool> mFlags;
    std::vector<GPPtr<ContentWrap>> mCache;
    bool mComplte;
    std::vector<GPPtr<GPStatusContent> > mStatus;
};
#endif
