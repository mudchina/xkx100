// Room: /d/taishan/baihe.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "白鹤泉");
	set("long", @LONG
相传从前这里有一个白鹤泉，它的水清凉甘甜，为泰山之最。这泉
水长年涌流不断，喷出的水象仙鹤扑扇着翅膀洗澡一样，因以为名。可
惜后来有一个自私自利的小官，独霸了泉水，后来更因迷信风水之说，
把泉眼堵塞，白鹤泉从此便干涸了。现在只剩下一座刻着「白鹤泉」三
字的石坊以为纪念。从这里继续北上，便是上山之路。
LONG );
	set("exits", ([
		"northup"   : __DIR__"hongmen",
		"southdown" : __DIR__"daizong",
	]));
	set("resource/water",1);
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
	if(!userp(me) && (int)me->query("ts_xl") && dir=="southdown")
		return 0;
	return ::valid_leave(me,dir);
}

