#ifndef ZK_FOR_RUSTIC_ROVER_HPP_
#define ZK_FOR_RUSTIC_ROVER_HPP_

#include "zikoichi_kun_api.hpp"
#include "rr_parser.hpp"

class RusticZikoichiKun
{
  public:
  RusticZikoichiKun():
  rr_value(rustic_rover::RusticRover(10, 10, 10, 10, 10)), 
  i(0), 
  x_vec(0.0),
  y_vec(0.0),
  rotation_vec(0.0)
  {}

  void setup()
  {
    zk_api::setup();
    Serial.begin(115200);
  }

  void receive()
  {
    if(Serial.available())
    {
      buf[i] = Serial.read();
      if(buf[i] == 'e')
      {
        i = 0;

        String get_str(buf);

        rr_value = rustic_rover::from_str(get_str);

        Serial.println(x_vec);
      }
      else
      {
        i++;
      }
    }
  }

  void motor()
  {
    rr_to_pwm();
    zk_api::xyz_control(-1.0*x_vec, y_vec, -1.0*rotation_vec,1.0);
  }

  private:
  void rr_to_pwm()
  {
    x_vec = (float)(rr_value.value_1) / 10.0 -1.0;
    y_vec = ((float)rr_value.value_2-10.0) / 10.0;
    rotation_vec = ((float)rr_value.value_3-10.0) / 10.0;
  }
  rustic_rover::RusticRover rr_value;
  float x_vec, y_vec, rotation_vec;
  char buf[256];
  int i;
};

#endif