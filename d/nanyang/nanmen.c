// Room: /d/nanyang/nanmen.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","南城门");
	set("long",@LONG
这里是南阳南门。南阳处南阳盆地内，水土肥沃，物产丰饶。再往
南就是汉水了，偶尔有渔夫在河上张网捕鱼。
LONG);
	set("exits",([
		"north"   : __DIR__"dajie1",
		"south"   : __DIR__"hanshui2",
	]));
	set("objects",([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors","nanyang");
	set("coor/x", 10);
	set("coor/y", 480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
