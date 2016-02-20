// Room: /d/taishan/zhengqi.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "正气厅");
	set("long", @LONG
这里是封禅台右边的正气厅，武林盟罚恶使者平时不下山时，
通常都是在这里处置武林公案。上首正中放着把虎皮椅，罚恶使者
就坐在上面开堂审理。左右各侍立着几位红衣武士，看上去杀气腾
腾，令人凛然而生惧意。
LONG );
	set("exits", ([
		"east" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/fa-e" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
	set("coor/x", 400);
	set("coor/y", 630);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
