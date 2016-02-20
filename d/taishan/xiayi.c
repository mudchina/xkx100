// Room: /d/taishan/xiayi.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "侠义厅");
	set("long", @LONG
这里是封禅台左边的侠义厅，武林盟赏善使者平时不下山时，
通常都是在这里办理武林公案。上首正中放着把太师椅，赏善使者
就坐在上面开堂审理。左右各侍立着几位红衣武士，看上去威风凛
凛，自有一股庄严气象。
LONG );
	set("exits", ([
		"west" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/shang-shan" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
	set("coor/x", 420);
	set("coor/y", 630);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
