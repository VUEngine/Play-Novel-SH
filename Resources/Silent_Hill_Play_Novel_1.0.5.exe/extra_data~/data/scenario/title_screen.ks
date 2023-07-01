[_tb_system_call storage=system/_title_screen.ks]

[bg  time="1000"  method="crossfade"  storage="WARNING_1.gif"  ]
[wait  time="12000"  ]
[bg  time="500"  method="crossfade"  storage="BLACK.gif"  ]
[bg  time="1000"  method="crossfade"  storage="WARNING_2.gif"  ]
[wait  time="8000"  ]
[bg  time="500"  method="crossfade"  storage="BLACK.gif"  ]
[bg  time="4000"  method="crossfade"  storage="SS_1.gif"  ]
[bg  time="1000"  method="crossfade"  storage="WHITE.gif"  ]
[bg  time="4000"  method="crossfade"  storage="SS_2.gif"  ]
[bg  time="1000"  method="crossfade"  storage="WHITE.gif"  ]
[bg  time="4000"  method="crossfade"  storage="SS_3.gif"  ]
[bg  time="1000"  method="crossfade"  storage="BLACK.gif"  ]
[movie  storage="INTRO.mp4.mp4"  skip="true"  ]
[tb_hide_message_window  ]
*title

[cm  ]
[stopbgm  ]
[stopse  ]
[playbgm  loop="true"  storage="MAIN_MENU_SOUND.ogg"  ]
[bg  storage="MAIN_MENU.gif"  ]
[button  storage="0_SELECT_SCENARIO.ks"  target="*0_SELECT_SCENARIO"  graphic="SS_BUTTON.png"  width="181"  height="20"  y="140"  x="70"  ]
[button  storage="0_CREDITS.ks"  target="*0_CREDITS"  graphic="C_BUTTON.png"  width="89"  height="20"  x="115"  y="165"  ]
[s  ]
*start

[showmenubutton]

[cm  ]
[jump  storage="scene1.ks"  target=""  ]
[s  ]
*load

[showmenubutton]

[cm  ]
[showload]

[jump  target="*title"  storage=""  ]
[s  ]
