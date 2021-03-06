/** @file
    @brief Header

    @date 2016

    @author
    Sensics, Inc.
    <http://sensics.com>

*/

// Copyright 2016 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_DisplayConfiguration_h_GUID_960CC7C4_FE0B_4CFF_9AEE_F5F11557A2C6
#define INCLUDED_DisplayConfiguration_h_GUID_960CC7C4_FE0B_4CFF_9AEE_F5F11557A2C6

// Internal Includes
#include <osvr/Display/Display.h>

#include <osvr/Display/Export.h>

// Library/third-party includes
// - none

// Standard includes
#include <vector>

namespace osvr {
namespace display {

OSVR_DISPLAY_EXPORT bool setDesktopOrientation(const Display& display, DesktopOrientation orientation);

} // end namespace display
} // end namespace osvr

#endif // INCLUDED_DisplayConfiguration_h_GUID_960CC7C4_FE0B_4CFF_9AEE_F5F11557A2C6

