
// Copyright 2013 Dolphin Emulator Project / 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <algorithm>
#include <codecvt>

#include "string_util.h"

#ifdef _WIN32
#include <Windows.h>
#endif

namespace utl {

// Turns "  hej " into "hej". Also handles tabs.
std::string strip_spaces(const std::string& str) {
    const std::size_t s = str.find_first_not_of(" \t\r\n");

    if (str.npos != s)
        return str.substr(s, str.find_last_not_of(" \t\r\n") - s + 1);
    else
        return "";
}

// "\"hello\"" is turned to "hello"
// This one assumes that the string has already been space stripped in both
// ends, as done by StripSpaces above, for example.
std::string strip_quotes(const std::string& s) {
    if (s.size() && '\"' == s[0] && '\"' == *s.rbegin())
        return s.substr(1, s.size() - 2);
    else
        return s;
}

std::string from_bool(bool value) {
    return value ? "True" : "False";
}

std::string tabs_to_spaces(int tab_size, std::string in) {
    std::size_t i = 0;

    while ((i = in.find('\t')) != std::string::npos) {
        in.replace(i, 1, tab_size, ' ');
    }

    return in;
}

bool split_path(const std::string& full_path, std::string* _pPath, std::string* _pFilename,
               std::string* _pExtension) {
    if (full_path.empty())
        return false;

    std::size_t dir_end = full_path.find_last_of("/\\:");
    if (std::string::npos == dir_end)
        dir_end = 0;
    else
        dir_end += 1;

    std::size_t fname_end = full_path.rfind('.');
    if (fname_end < dir_end || std::string::npos == fname_end)
        fname_end = full_path.size();

    if (_pPath)
        *_pPath = full_path.substr(0, dir_end);

    if (_pFilename)
        *_pFilename = full_path.substr(dir_end, fname_end - dir_end);

    if (_pExtension)
        *_pExtension = full_path.substr(fname_end);

    return true;
}

#ifdef _WIN32

std::string utf16_to_utf8(const std::u16string& input) {
#ifdef _MSC_VER
    // Workaround for missing char16_t/char32_t instantiations in MSVC2017
    std::wstring_convert<std::codecvt_utf8_utf16<__int16>, __int16> convert;
    std::basic_string<__int16> tmp_buffer(input.cbegin(), input.cend());
    return convert.to_bytes(tmp_buffer);
#else
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.to_bytes(input);
#endif
}

std::u16string utf8_to_utf16(const std::string& input) {
#ifdef _MSC_VER
    // Workaround for missing char16_t/char32_t instantiations in MSVC2017
    std::wstring_convert<std::codecvt_utf8_utf16<__int16>, __int16> convert;
    auto tmp_buffer = convert.from_bytes(input);
    return std::u16string(tmp_buffer.cbegin(), tmp_buffer.cend());
#else
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.from_bytes(input);
#endif
}

static std::wstring CPToUTF16(uint32_t code_page, const std::string& input) {
    const auto size =
        MultiByteToWideChar(code_page, 0, input.data(), static_cast<int>(input.size()), nullptr, 0);

    if (size == 0) {
        return L"";
    }

    std::wstring output(size, L'\0');

    if (size != MultiByteToWideChar(code_page, 0, input.data(), static_cast<int>(input.size()),
                                    &output[0], static_cast<int>(output.size()))) {
        output.clear();
    }

    return output;
}

std::string utf16_to_utf8(const std::wstring& input) {
    const auto size = WideCharToMultiByte(CP_UTF8, 0, input.data(), static_cast<int>(input.size()),
                                          nullptr, 0, nullptr, nullptr);
    if (size == 0) {
        return "";
    }

    std::string output(size, '\0');

    if (size != WideCharToMultiByte(CP_UTF8, 0, input.data(), static_cast<int>(input.size()),
                                    &output[0], static_cast<int>(output.size()), nullptr,
                                    nullptr)) {
        output.clear();
    }

    return output;
}

std::wstring utf8_to_utf16_w(const std::string& input) {
    return CPToUTF16(CP_UTF8, input);
}

#elif __linux__
std::string utf16_to_utf8(const std::u16string& input) {
    char p[input.length()];
    wcstombs(p, (const wchar_t *) input.c_str(), input.length());
    std::string output = p;
    return output;
}

std::u16string utf8_to_utf16(const std::string& input) {
    char16_t p[input.length()];
    mbstowcs((wchar_t *) p, input.c_str(), input.length());
    std::u16string output = p;
    return output;
}

std::string utf16_to_utf8(const std::wstring& input) {
    char p[input.length()];
    wcstombs(p, input.c_str(), input.length());
    std::string output = p;
    return output;
}

std::wstring utf8_to_utf16_w(const std::string& input) {
    wchar_t p[input.length()];
    mbstowcs(p, input.c_str(), input.length());
    std::wstring output = p;
    return output;
}
#endif
}