//  Room:  /d/lanzhou/jincheng.c

inherit  ROOM;

void  create  ()
{
	set("short",  "金城");
	set("long",  @LONG
金城郡设于西汉时，这里是金城郡治所。金城渡口因其战略位置的
重要性而闻名于世，历史上许多著名的战役就发生在这儿。
    河里有几只羊皮筏子(boat)，是用来摆渡的，喊一喊(yell)或许会
有人过来。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"road4",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2740);
	set("coor/z", 0);
	setup();
}

void init()
{
    add_action("do_yell", "yell");
}

int do_yell()
{
	return notify_fail("喊什么喊，那边还没做好呢！\n");
}