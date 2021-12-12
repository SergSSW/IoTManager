// StreamUtils - github.com/bblanchon/ArduinoStreamUtils
// Copyright Benoit Blanchon 2019-2021
// MIT License

#pragma once

#include "Stream.h"
#include "WString.h"

using IPAddress = String;

struct Client : Stream {
  virtual int connect(IPAddress ip, uint16_t port) = 0;
  virtual int connect(const char *host, uint16_t port) = 0;
  virtual uint8_t connected() = 0;
  virtual void stop() = 0;
  virtual operator bool() = 0;

  // Already in Print
  virtual size_t write(uint8_t) = 0;
  virtual size_t write(const uint8_t *buf, size_t size) = 0;
  virtual void flush() = 0;

  // Already in Stream
  virtual int available() = 0;
  virtual int read() = 0;
  virtual int peek() = 0;

  // Curiously not in Stream
  virtual int read(uint8_t *buf, size_t size) = 0;
};
