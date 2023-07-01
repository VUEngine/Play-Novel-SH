[_tb_system_call storage=system/_H2_15.ks]

*H2_15

[tb_show_message_window  ]
Those large wings.[p]
It uses them nimbly to maintain its balance in the air.[p]
If I destroy its wing it won't be able to move.[p]
Then I can finish it at my leisure.[p]


[playse  storage="GUNSHOT.ogg"  ]
[stopbgm  ]
[tb_image_show  time="12"  storage="default/BLOOD.gif"  width="55"  height="60"  x="183"  y="55"  _clickable_img="BIRD_DIE.gif"  ]
[tb_hide_message_window  ]
[bg  time="0"  method="crossfade"  storage="BIRD_DIE.gif"  ]
[tb_image_hide  time="1000"  ]
[bg  time="5000"  method="crossfade"  storage="BLACK.gif"  ]
[bg  time="500"  method="crossfade"  storage="harry_02-13.gif"  ]
[wait  time="3000"  ]
[tb_show_message_window  ]
My one shot hits the wing, blasting a large hole in it. [p]
The creature loses altitude as it falls to the floor.[p]
I can't afford to waste bullets.[p]
I crush it with the thick sole of my shoe many times.[p]
As its strange cries die out, a dark red stain spreads out on the floor.[p]


*H2_16

[tb_hide_message_window  ]
[bg  time="3000"  method="crossfade"  storage="harry_02-14.gif"  ]
[wait  time="500"  ]
[tb_show_message_window  ]
"What the hell...[p]
This is not a dream.[p]
What's happening to this place?"[p]
Only the sound of my fist hitting the table echoes in the cafe.[p]
At my feet the still warm corpse of the creature lies in the center of a pool of oddly colored liquid.[p]


[playse  storage="CAFE_DOOR.ogg"  ]
[jump  storage="H3_1.ks"  target="*H3_1"  ]
