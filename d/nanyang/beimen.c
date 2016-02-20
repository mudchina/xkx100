// Room: /d/nanyang/beimen.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","北城门");
	set("long",@LONG
这里是南阳北门。南阳古称宛城，东边是桐柏山、北面是伏牛山，
西靠秦岭。当年张绣大败曹操于此，典韦便战死城外。“唱戏的腔，做
菜的汤”，这里的风味也甚有名气。
LONG);
	set("exits",([
		"north"  : __DIR__"yidao3",
		"south"  : __DIR__"dajie2",
	]));
	set("objects",([
		"/d/city/npc/bing" : random(2)+1,
	]));
	set("outdoors","nanyang");
	set("coor/x", 10);
	set("coor/y", 520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

