#include <avr/io.h>
#include <util/delay.h>

int main() {
  DDRD = _BV(5);
  while (1) {
    PORTD ^= _BV(5);
    _delay_ms(1000);
  }
  return 0;
}
