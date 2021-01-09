#include "pch.h"

HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

void change_console_color(const unsigned short color) {
  SetConsoleTextAttribute(h_console, color);
}
class timer {
  double m_start_ = 0;
  double m_end_ = 0;
  double m_Elapsed = 0;
  const char *m_name_ = {};

public:
  explicit timer(const char *function_name) {
    m_name_ = function_name;
    m_start_ = omp_get_wtime();
  }

  ~timer() {
    m_end_ = omp_get_wtime();
    m_Elapsed = m_end_ - m_start_;
    change_console_color(3);
    std::cout << m_name_ << ": ";
    change_console_color(11);
    std::cout << std::fixed << m_Elapsed << " seconds\n";
    change_console_color(15);
  }
};

void count() {
  size_t n = 2000000;
  timer example("Timer example");
  while (n > 0) {
    n -= 1;
  }
}

int main() {
  count();
  return 0;
}
