
/*
 * UTL : The universal utility library
 *
 * Copyright 2019-2020 Force67.
 * For information regarding licensing see LICENSE
 * in the root of the source tree.
 */
// TODO: move this in dcore?

#ifdef __linux__

#include "logger.h"

namespace utl {
class fileOut final : public logBase {
  FILE *handle{nullptr};
  size_t bytes_written{0};

public:
  explicit fileOut(const std::wstring &filename) {
    // sad, but filename.size() == filename.length()
	size_t len = filename.length() * sizeof(wchar_t) + 1; // + 1 for '\0'
	char dst[len];
	wcstombs(dst, filename.c_str(), len);
    
    handle = fopen(dst, "w");
  }

  void close() {
    if (handle)
      fclose(handle);
  }

  const char *getName() override { return "fileOut"; }

  void write(const logEntry &entry) override {
    constexpr std::size_t MAX_BYTES_WRITTEN = 50 * 1024L * 1024L;

    // prevent spam
    if (!handle || bytes_written > MAX_BYTES_WRITTEN)
      return;

    auto msg = formatLogEntry(entry).append(1, '\n');
    bytes_written +=
        fwrite(static_cast<const void *>(msg.c_str()), msg.length(), 1, handle);

    if (entry.log_level >= logLevel::Error) {
      fflush(handle);
    }
  }
};

static void PrintMessage(const logEntry &entry, const std::string &color) {
  auto str = formatLogEntry(entry);
  if (!color.empty())
    str = "\x1B[" + color + str + "\033[0m";
  puts(str.c_str()); // stdout
}

class conOut_Linux final : public logBase {

public:
  const char *getName() override { return "conOut"; }

  void write(const logEntry &entry) override {
    std::string color = "";
    switch (entry.log_level) {
    case logLevel::Trace: // Grey
      color = "90m"; // FOREGROUND_INTENSITY;
      break;
    case logLevel::Debug: // Cyan
      color = "36m"; // FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
    case logLevel::Info: // Bright gray
      // "37m" - is white, there is "38;5;247m" - check if you like it
	  color = "37m"; // FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      break;
    case logLevel::Warning: // Bright yellow
      color = "93m"; // FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
      break;
    case logLevel::Error: // Bright red
      color = "31m"; //FOREGROUND_RED | FOREGROUND_INTENSITY;
      break;
    case logLevel::Critical: // Bright magenta
      color = "35m"; //FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
      break;
      // case LogLevel::Count:
      //	UNREACHABLE();
    }

    PrintMessage(entry, color);
  }
};

class dbgOut_Linux final : public logBase {
public:
  const char *getName() override { return "dbgOut"; }

  void write(const logEntry &entry) override {
    auto str = formatLogEntry(entry).append(1, '\n');
    fputs(str.c_str(), stderr);
  }
};

void createLogger(bool createConsole) {
  if (createConsole) {
    addLogSink(std::make_unique<conOut_Linux>());
  }

  // attach the sinks to the log system
  addLogSink(std::make_unique<fileOut>(FXNAME_WIDE L".log"));

  addLogSink(std::make_unique<dbgOut_Linux>());

  // attempt to properly close log file in case of a crash
  std::atexit([]() {
    auto *sink = static_cast<fileOut *>(getLogSink("fileOut"));
    if (sink)
      sink->close();
  });
}
}
#endif
