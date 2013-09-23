#ifndef INTELLIGENTCOFFEEMACHINE_H
#define INTELLIGENTCOFFEEMACHINE_H


class IntelligentCoffeeMachine
    {
        public:
            IntelligentCoffeeMachine();
            void Open_lid();
            void Insert_filter();
            void Insert_coffee ( float temp_coffe_reservoir );
            void Insert_water( float temp_water_reservoir );
            void Close_lid();
            void Switch_on();
            void Start_cooking();
            void Switch_off();
            void Take_coffee();
            void Take_Filter_out();
            ~IntelligentCoffeeMachine();

        private:
            float water_volume;
            float coffee_reservoir;
            bool lid_opened ;
            bool insert_filter ;
            bool switch_on;
            bool take_coffee;
            bool cook;
    };


#endif // INTELLIGENTCOFFEEMACHINE_H
