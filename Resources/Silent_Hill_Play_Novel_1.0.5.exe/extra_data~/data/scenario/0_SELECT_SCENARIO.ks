[_tb_system_call storage=system/_0_SELECT_SCENARIO.ks]

*0_SELECT_SCENARIO

[cm  ]
[tb_hide_message_window  ]
[playse  storage="SCENARIO_SELECTOR.ogg"  ]
[bg  time="400"  method="crossfade"  storage="WHITE.gif"  ]
[bg  time="500"  method="crossfade"  storage="00_SCENARIO_SELECTOR.gif"  ]
[button  storage="title_screen.ks"  target="*title"  graphic="BACK_BUTTON.gif"  width="24"  height="16"  y="220"  x="4"  ]
[clickable  storage="scene1.ks"  x="27"  y="61"  width="103"  height="124"  target="*H_START"  _clickable_img="00_SCENARIO_SELECTOR.gif"  ]
*H_START

[clickable  storage="C0_1.ks"  x="188"  y="61"  width="103"  height="124"  target="*C_START"  _clickable_img="00_SCENARIO_SELECTOR.gif"  ]
*C_START

[s  ]
