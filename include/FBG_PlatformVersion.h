#ifndef FBG_PLATFORMVERSION_H
#define FBG_PLATFORMVERSION_H

// Conventional string-ification macro.
#if !defined(FBG_STRINGIZE)
#define FBG_STRINGIZEIMPL(x) #x
#define FBG_STRINGIZE(x)     FBG_STRINGIZEIMPL(x)
#endif

// Master version numbers
#define FBG_PLATFORM_PRODUCT_VERSION 0 // Product version doesn't participate in semantic versioning.
#define FBG_PLATFORM_MAJOR_VERSION   0 
#define FBG_PLATFORM_MINOR_VERSION   3
#define FBG_PLATFORM_PATCH_VERSION   0
#define FBG_PLATFORM_BUILD_NUMBER    0
#define FBG_PLATFORM_DRIVER_VERSION  0
// "Major.Minor.Patch.Build"
#if !defined(FBG_PLATFORM_VERSION_STRING)
#define FBG_PLATFORM_VERSION_STRING FBG_STRINGIZE(FBG_PLATFORM_MAJOR_VERSION.FBG_PLATFORM_MINOR_VERSION.FBG_PLATFORM_PATCH_VERSION.FBG_PLATFORM_BUILD_NUMBER)
#endif

// This appears in the user-visible file properties.  TeamCity builds will stamp PLATFORM_DESCRIPTION_STRING.
#if !defined(FBG_PLATFORM_DESCRIPTION_STRING)
#if defined(_DEBUG)
#define FBG_PLATFORM_DESCRIPTION_STRING "dev build debug"
#else
#define FBG_PLATFORM_DESCRIPTION_STRING "dev build"
#endif
#endif

#if !defined(FBG_JOIN)
#define FBG_JOIN(a, b)  FBG_JOIN1(a, b)
#define FBG_JOIN1(a, b) FBG_JOIN2(a, b)
#define FBG_JOIN2(a, b) a##b
#endif

#endif
