//  Room:  /d/luoyang/xiaojiudian.c

inherit  ROOM;

void  create  ()
{
	set("short",  "酒肆");
	set("long",  @LONG
这里是个小酒肆，七八名无赖正在店中赌骰子。店里卖些混酒和猪
鸭下水，你看了一点胃口都没有。无赖们看着你，一副要痛扁你一顿，
或者赌骰子狠出你一把老千的样子，看来还是走吧。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" :  __DIR__"xiaojie1",
	]));
	set("objects",  ([
		__DIR__"npc/wulai" : 3,
	]));
	set("coor/x", -400);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
