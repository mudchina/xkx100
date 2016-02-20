// Room: /d/guiyun/wofang.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","卧房");
	set("long",@LONG
这是庄主的卧房。房间不大，收拾得很干净。屋中的小八仙桌上放
着一把酒壶和一只酒盅，看来主人常常以饮酒自缱。
LONG );
	set("exits",([
		"east" : __DIR__"houting",
	]) );
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}
