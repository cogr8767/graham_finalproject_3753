#include <stdlib.h>
#include "ctest.h"
#include "logic.h"

//TEST 1: No initial velocity and no thrust = 1 after 1 tick
//Assumptions: tick = 100ms
CTEST_DATA(no_startingV_no_thrust) {
    
};

CTEST_SETUP(no_startingV_no_thrust) {
    set_velocityX(0);
    set_thrustX(0);
    physics_logic();
}

CTEST2(no_startingV_no_thrust, test_) {
    ASSERT_EQUAL(1, get_velocityX());
}

//TEST 2: If thrust is over limit for a certain time, check that a blackout has occurred.
//Assumptions: tick = 100ms, thrust limit for blackout is 25 for 1 sec, 1 button press = 5 thrust
CTEST_DATA(blackout) {
    
};

//Runs for 10 ticks
CTEST_SETUP(blackout) {
    set_thrustX(25);

    for(int i = 0; i < 10; i++) {
        physics_logic();
    }
}

CTEST2(blackout, backoutstate) {
    ASSERT_EQUAL(1, get_shipState());
}

//TEST 3: If buttons have been pressed during blackout, check that thrust was still 0.
CTEST_DATA(blackout_no_thrust) {
    
};

CTEST_SETUP(blackout_no_thrust) {
    set_shipState(1);
    physics_logic();
    button_inc();
    physics_logic();
}

CTEST2(blackout_no_thrust, no_thrust) {
    ASSERT_EQUAL(0, get_button_num());
    ASSERT_EQUAL(0, get_thrustX());
    ASSERT_EQUAL(0, get_thrustY());
}

//TEST 4: If a blackout occurs, make sure that in 2 seconds it clears.
//Assumptions: tick = 100ms
CTEST_DATA(blackout_clear) {
    
};

CTEST_SETUP(blackout_clear) {
    set_shipState(1);

    for(int i = 0; i < 21; i++) {
        physics_logic();
    }
}

CTEST2(blackout_clear, cleared) {
    ASSERT_EQUAL(0, get_shipState());
}

//TEST 5: If a blackout occurs, make sure thrust is reset to 0.
CTEST_DATA(blackout_reset_thrust) {
    
};

CTEST_SETUP(blackout_reset_thrust) {
    set_shipState(1);
    physics_logic();
}

CTEST2(blackout_reset_thrust, reset_success) {
    ASSERT_EQUAL(0, get_thrustX());
    ASSERT_EQUAL(0, get_thrustY());
}

//TEST 6: If button_inc is called, make sure thrust is increased.
//Assumptions: ship is perpindicular to ground
CTEST_DATA(button_0_pressed) {
    
};

CTEST_SETUP(button_0_pressed) {
    set_thrustX(0);
    button_inc();
    physics_logic();
}

CTEST2(button_0_pressed, pressed) {
    ASSERT_EQUAL(5, get_thrustX());
    ASSERT_EQUAL(0, get_thrustY());
}

//TEST 7: If button_dec is called, make sure thrust is decreased.
//Assumptions: ship is perpindicular to ground
CTEST_DATA(button_1_pressed) {
    
};

CTEST_SETUP(button_1_pressed) {
    set_thrustX(15);
    button_dec();
    physics_logic();
}

CTEST2(button_1_pressed, pressed1) {
    ASSERT_EQUAL(10, get_thrustX());
    ASSERT_EQUAL(0, get_thrustY());
}

//TEST 8: If finger is on cap position 0, make sure that ship is pointed to -45 degrees.
CTEST_DATA(capPos0) {
    
};

CTEST_SETUP(capPos0) {
    set_sliderPos(0);
    physics_logic();
}

CTEST2(capPos0, left_angle) {
    ASSERT_EQUAL(0, get_angle());
}

//TEST 9: If finger is on cap position 1, make sure that ship is pointed straight down.
CTEST_DATA(capPos1) {
    
};

CTEST_SETUP(capPos1) {
    set_sliderPos(1);
    physics_logic();
}

CTEST2(capPos1, no_angle) {
    ASSERT_EQUAL(1, get_angle());
}

//TEST 10: If finger is on cap position 2, make sure that ship is pointed to 45 degrees.
CTEST_DATA(capPos2) {
    
};

CTEST_SETUP(capPos2) {
    set_sliderPos(2);
    physics_logic();
}

CTEST2(capPos2, right_angle) {
    ASSERT_EQUAL(2, get_angle());
}
//TEST 11: If position is in the ground and velocityX or velocityY > the max of those values, make sure the ship crashes.
CTEST_DATA(crash) {
    
};

CTEST_SETUP(crash) {
    set_positionX(1);
    set_velocityX(100);
    set_velocityY(100);  
    physics_logic();
}

CTEST2(crash, crash_success) {
    ASSERT_EQUAL(2, get_shipState());
}
//TEST 12: If position is in the ground and velocityX and velocityY are within acceptable range, make sure the ship lands and doesn’t crash.
CTEST_DATA(land) {
      
};

CTEST_SETUP(land) {
    set_positionX(1);
    set_velocityX(0);
    set_velocityY(0);
    physics_logic();
}

CTEST2(land, win_game) {
    ASSERT_EQUAL(3, get_shipState());
}
