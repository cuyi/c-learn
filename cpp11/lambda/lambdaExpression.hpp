#pragma once

//PARAMS - lambda declaration to capture everything by the ref
//         and take one parameter as a rvalue ref of automatic type
#define PARAMS(m)   [&](auto &&m)

//PROC - lambda declaration to capture everything by ref
//       and take no parameters
#define PROC        [&]()

//SAFE_PROC - lambda declaration to capture everything by value
//            and take no parameters
#define SAFE_PROC   [=]()

