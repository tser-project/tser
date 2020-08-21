#include "builtin/date.h"
#include <sys/time.h>

using namespace tser;

int64_t Date::now() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}