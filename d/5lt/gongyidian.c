// Room: /d/5lt/gongyidian.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "民间工艺品店");
	set  ("long",  @LONG
这是一个古色古香的民间工艺品商店。房内摆设着上好的香檀木家
具，柜子里陈列着店主收藏的各种名贵工艺品，墙上则挂满了店主自己
绘制的Ascii名画。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"south"  :  __DIR__"wroad1",
	]));
	set("objects",  ([
		__DIR__"npc/xiyi": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -160);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
