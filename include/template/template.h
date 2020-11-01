// Copyright (C) 2020 Anders Rosén <panrosen@gmail.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
// USA

#pragma once

#ifndef DECLSPEC
#   if defined(__WIN32__) || defined(__WINRT__)
#       ifdef BUILDING_TEMPLATE
#           define DECLSPEC __declspec(dllexport)
#       else
#           define DECLSPEC __declspec(dllimport)
#       endif
#   else
#       define DECLSPEC
#   endif
#endif

/// The version of the template library.
/// Format: ABBCC Where A = Major, BB = Minor, CC = Revision
#define TEMPLATE_VERSION 0x00102

namespace arosen::Template {

    /// \class MyVeryOwnClass template.h template/template.h
    /// \brief This is just a silly little class just to have something in the template
    ///
    /// There could be a longer description here, and even an example:
    /// \includeexamplewithoutput{example1.cpp}
    class DECLSPEC MyVeryOwnClass
    {
        int a_ = 14;
        int b_ = 48;

    public:
        MyVeryOwnClass() = default;
        MyVeryOwnClass(int a, int b);

        /// Returns the sum of the two integers this object contains
        ///
        /// \return The sum
        int sum() const;
    };
}
