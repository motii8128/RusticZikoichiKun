#include "RusticZikoichiKun.hpp"

RusticZikoichiKun rustic_zikoichi_kun;

void setup() {
  // put your setup code here, to run once:
  rustic_zikoichi_kun.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  rustic_zikoichi_kun.receive();
  rustic_zikoichi_kun.motor();
}
