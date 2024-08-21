#ifndef RR_PARSER_HPP_
#define RR_PARSER_HPP_

namespace rustic_rover
{
    struct RusticRover
    {
        int value_1;
        int value_2;
        int value_3;
        int value_4;
        int value_5;
        RusticRover(int _1, int _2, int _3, int _4, int _5):value_1(_1),value_2(_2),value_3(_3),value_4(_4),value_5(_5)
        {};
    };


    inline RusticRover from_str(String read)
    {
        int start_index = 0;
        int end_index = read.indexOf('e');
        String data = read.substring(start_index+1, end_index);

        int first_div_index = data.indexOf(',');

        String str_1 = data.substring(0, first_div_index);

        String without_1 = data.substring(first_div_index+1);

        int second_com = without_1.indexOf(',');

        String str_2 = without_1.substring(0, second_com);
        String without_2 = without_1.substring(second_com+1);

        int third_com = without_2.indexOf(',');

        String str_3 = without_2.substring(0, third_com);
        String without_3 = without_2.substring(third_com+1);

        int four_com = without_3.indexOf(',');

        String str_4 = without_3.substring(0, four_com);
        String str_5 = without_3.substring(four_com+1);

        int v1 = str_1.toInt();
        int v2 = str_2.toInt();
        int v3 = str_3.toInt();
        int v4 = str_4.toInt();
        int v5 = str_5.toInt();

        return RusticRover(v1, v2, v3, v4, v5);
    }
}

#endif